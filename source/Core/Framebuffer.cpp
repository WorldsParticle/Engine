//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 3 of the License, or
// any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this program; If not, see <http://www.gnu.org/licenses/>.
//
// Copyright (C) 2016 Worldsparticle (worldsparticle@gmail.com)
//

#include    <glm/gtc/matrix_transform.hpp>
#include    <GL/glew.h>
#include    <log4cpp/Category.hh>

#include    "Engine/Core/Framebuffer.hpp"
#include    "Engine/Core/ArrayObject.hpp"
#include    "Engine/Core/BufferObject.hpp"
#include    "Engine/Core/ShaderProgramLibrary.hpp"

using namespace     log4cpp;

namespace   Engine
{
    Framebuffer::Framebuffer(const ShaderProgramLibrary &shaderprograms, const glm::ivec2 &size) :
	m_shaderFramebuff(shaderprograms.get(FRAMEBUFFER_SHADER_PROGRAM)),
	m_vao(std::make_shared<ArrayObject>()),
	m_vbo(std::make_shared<BufferObject>(BufferObject::Type::ARRAY_BUFFER, BufferObject::Usage::STATIC_DRAW)),
	m_framebuffer(),
	m_textureColorbuffer(),
	m_size(size)
    {
	GLfloat quadVertices[24] = {   // Vertex attributes for a simple quad
	    // Positions   // TexCoords
	    -1.0f,  1.0f,  0.0f, 1.0f,
	    -1.0f, -1.0f,  0.0f, 0.0f,
	    1.0f, -1.0f,  1.0f, 0.0f,

	    -1.0f,  1.0f,  0.0f, 1.0f,
	    1.0f, -1.0f,  1.0f, 0.0f,
	    1.0f,  1.0f,  1.0f, 1.0f
	};
	m_vbo->update(quadVertices, 24 * sizeof(GLfloat));
	m_vao->bind();
	m_vbo->bind();
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), nullptr);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), reinterpret_cast<GLvoid*>(2 * sizeof(GLfloat)));
	m_vbo->unbind();
	m_vao->unbind();

	GLuint rbo;
	Category &root = Category::getRoot();
	glEnable(GL_DEPTH_TEST);
	glGenFramebuffers(1, &m_framebuffer);
	glBindFramebuffer(GL_FRAMEBUFFER, m_framebuffer);
	createTexture();
	// Create a renderbuffer object for depth and stencil attachment
	glGenRenderbuffers(1, &rbo);
	glBindRenderbuffer(GL_RENDERBUFFER, rbo);
	glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8,
		m_size.x, m_size.y);
	// Use a single renderbuffer object for both a depth AND stencil buffer
	glBindRenderbuffer(GL_RENDERBUFFER, 0);
	glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT,
		GL_RENDERBUFFER, rbo); // Now actually attach it
	// Check if the framebuffer is complete (it is supposed to)
	if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
	{
	    root << Priority::ERROR << "FRAMEBUFFER: Framebuffer\
		is not complete!";
	}
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	glDeleteRenderbuffers(1, &rbo);
    }

    Framebuffer::Framebuffer(const Framebuffer &other) :
	m_shaderFramebuff(other.m_shaderFramebuff),
	m_vao(other.m_vao),
	m_vbo(other.m_vbo),
	m_framebuffer(other.m_framebuffer),
	m_textureColorbuffer(other.m_textureColorbuffer),
	m_size(other.m_size)
    {
	GLuint rbo;
	Category &root = Category::getRoot();
	glEnable(GL_DEPTH_TEST);
	glGenFramebuffers(1, &m_framebuffer);
	glBindFramebuffer(GL_FRAMEBUFFER, m_framebuffer);
	createTexture();
	// Create a renderbuffer object for depth and stencil attachment
	glGenRenderbuffers(1, &rbo);
	glBindRenderbuffer(GL_RENDERBUFFER, rbo);
	glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8,
		m_size.x, m_size.y);
	// Use a single renderbuffer object for both a depth AND stencil buffer
	glBindRenderbuffer(GL_RENDERBUFFER, 0);
	glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT,
		GL_RENDERBUFFER, rbo); // Now actually attach it
	// Check if the framebuffer is complete (it is supposed to)
	if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
	{
	    root << Priority::ERROR << "FRAMEBUFFER: Framebuffer\
		is not complete!";
	}
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	glDeleteRenderbuffers(1, &rbo);
    }

    Framebuffer::Framebuffer(Framebuffer &&other) noexcept :
	m_shaderFramebuff(),
	m_vao(),
	m_vbo(),
	m_framebuffer(),
	m_textureColorbuffer(),
	m_size(other.m_size)
    {
    }

    Framebuffer::~Framebuffer(void) noexcept
    {
	glDeleteTextures(1, &m_textureColorbuffer);
	glDeleteFramebuffers(1, &m_framebuffer);
    }

    Framebuffer &Framebuffer::operator=(const Framebuffer &other)
    {
	this->m_vao = other.m_vao;
	this->m_vbo = other.m_vbo;
	this->m_framebuffer = other.m_framebuffer;
	this->m_size = other.m_size;
	return *this;
    }

    Framebuffer &Framebuffer::operator=(Framebuffer &&other) noexcept
    {
	this->m_size = other.m_size;
	return *this;
    }

    void Framebuffer::bindTexture(void)
    {
	glBindTexture(GL_TEXTURE_2D, m_textureColorbuffer);
    }

    void Framebuffer::createTexture(void)
    {
	glGenTextures(1, &m_textureColorbuffer);
	glBindTexture(GL_TEXTURE_2D, m_textureColorbuffer);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_size.x, m_size.y, 0, GL_RGB,
		GL_UNSIGNED_BYTE, nullptr);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	// Attach the texture to currently bound m_framebuffer object
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0,
		GL_TEXTURE_2D, m_textureColorbuffer, 0);
	glBindTexture(GL_TEXTURE_2D, 0);
    }

    void Framebuffer::bind()
    {
	glBindFramebuffer(GL_FRAMEBUFFER, m_framebuffer);
    }

    void Framebuffer::unbind()
    {
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
    }

    void Framebuffer::draw()
    {
	unbind();
	//unbind framebuff
	glClearColor(155.0f / 255.0f , 155.0f / 255.0f, 155.0f / 255.0f, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glDisable(GL_DEPTH_TEST); // depth useless for the quad

	// Draw Screen
	m_shaderFramebuff->bind();
	m_vao->bind();
	bindTexture();
	glDrawArrays(GL_TRIANGLES, 0, 6);
	glBindTexture(GL_TEXTURE_2D, 0);
	m_vao->unbind();
	m_shaderFramebuff->unbind();
    }
}
