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
// Copyright (C) 2016 Martin-Pierrat Louis (louismartinpierrat@gmail.com)
//

#include    <GL/glew.h>
#include    <log4cpp/Category.hh>

#include    "Engine/Core/Renderer.hpp"
#include    "Engine/Core/Object.hpp"
#include    "Engine/Core/Camera.hpp"
#include    "Engine/Core/Light.hpp"
#include    "Engine/Core/Transform.hpp"
#include    "Engine/Core/Mesh.hpp"

using namespace     log4cpp;

namespace   Engine
{
    Renderer::Renderer(const ShaderProgramLibrary &shaderprograms, Scene *scene) :
	m_scene(scene),
	m_objects(),
	m_cameras(),
	m_lights(),
	m_framebuffers(),
	m_textureColorbuffers(),
	m_shaderFramebuff(shaderprograms.get(FRAMEBUFFER_SHADER_PROGRAM)),
	m_quadVAO()
    {
	GLfloat quadVertices[] = {   // Vertex attributes for a quad that fills the entire screen in Normalized Device Coordinates.
	    // Positions   // TexCoords
	    -1.0f,  1.0f,  0.0f, 1.0f,
	    -1.0f, -1.0f,  0.0f, 0.0f,
	    1.0f, -1.0f,  1.0f, 0.0f,

	    -1.0f,  1.0f,  0.0f, 1.0f,
	    1.0f, -1.0f,  1.0f, 0.0f,
	    1.0f,  1.0f,  1.0f, 1.0f
	};
	GLuint quadVBO;
	glGenVertexArrays(1, &m_quadVAO);
	glGenBuffers(1, &quadVBO);
	glBindVertexArray(m_quadVAO);
	glBindBuffer(GL_ARRAY_BUFFER, quadVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(quadVertices), &quadVertices, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), nullptr);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), reinterpret_cast<GLvoid*>(2 * sizeof(GLfloat)));
	glBindVertexArray(0);
    }

    Renderer::Renderer(const Renderer &other) :
	m_scene(other.m_scene),
	m_objects(),
	m_cameras(other.m_cameras),
	m_lights(),
	m_framebuffers(other.m_framebuffers),
	m_textureColorbuffers(other.m_textureColorbuffers),
	m_shaderFramebuff(other.m_shaderFramebuff),
	m_quadVAO(other.m_quadVAO)
    {
    }

    Renderer::Renderer(Renderer &&other) noexcept :
	m_scene(std::move(other.m_scene)),
	m_objects(),
	m_cameras(std::move(other.m_cameras)),
	m_lights(),
	m_framebuffers(std::move(other.m_framebuffers)),
	m_textureColorbuffers(std::move(other.m_textureColorbuffers)),
	m_shaderFramebuff(std::move(other.m_shaderFramebuff)),
	m_quadVAO(std::move(other.m_quadVAO))
	{
	}

    Renderer::~Renderer(void) noexcept
    {
    }

    Renderer &
	Renderer::operator=(const Renderer &other)
	{
	    this->m_scene = other.m_scene;
	    return *this;
	}

    Renderer &
	Renderer::operator=(Renderer &&other) noexcept
	{
	    this->m_scene = std::move(other.m_scene);
	    return *this;
	}

    void
	Renderer::add(Object *object)
	{
	    //Category &root = Category::getRoot();

	    //root << Priority::DEBUG << "Renderer - add object()" << object->getName();
	    this->m_objects.push_back(object);
	}

    void
	Renderer::add(Camera *camera)
	{
	    Category& root = Category::getRoot();
	    const glm::ivec2 &size = camera->size();
	    unsigned int framebuffer;
	    unsigned int textureColorbuffer;
	    GLuint rbo;

	    //root << Priority::DEBUG << "Renderer - add camera()" << camera->getName();
	    this->m_cameras.push_back(camera);
	    glEnable(GL_DEPTH_TEST);
	    glGenFramebuffers(1, &framebuffer);
	    glBindFramebuffer(GL_FRAMEBUFFER, framebuffer);
	    // Generate texture
	    glGenTextures(1, &textureColorbuffer);
	    glBindTexture(GL_TEXTURE_2D, textureColorbuffer);
	    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, size.x, size.y, 0, GL_RGB, GL_UNSIGNED_BYTE, nullptr);
	    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
	    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	    glBindTexture(GL_TEXTURE_2D, 0);
	    // Attach it to currently bound framebuffer object
	    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, textureColorbuffer, 0);
	    // Create a renderbuffer object for depth and stencil attachment (we won't be sampling these)
	    glGenRenderbuffers(1, &rbo);
	    glBindRenderbuffer(GL_RENDERBUFFER, rbo);
	    glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, size.x, size.y); // Use a single renderbuffer object for both a depth AND stencil buffer.
	    glBindRenderbuffer(GL_RENDERBUFFER, 0);
	    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, rbo); // Now actually attach it
	    // Now that we actually created the framebuffer and added all attachments we want to check if it is actually complete now
	    if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
		root << Priority::ERROR << "FRAMEBUFFER: Framebuffer is not complete! -add camera";
	    glBindFramebuffer(GL_FRAMEBUFFER, 0);
	    glDeleteRenderbuffers(1, &rbo);
	    this->m_framebuffers.push_back(framebuffer);
	    this->m_textureColorbuffers.push_back(textureColorbuffer);
	}

    void
	Renderer::add(Light *light)
	{
	    //Category &root = Category::getRoot();

	    //root << Priority::DEBUG << "Renderer - add light() : " << light->getName();
	    this->m_lights.push_back(light);
	}

    void
	Renderer::render(void)
	{

	    std::list<unsigned int>::iterator texIt = m_textureColorbuffers.begin();
	    std::list<unsigned int>::iterator fbIt = m_framebuffers.begin();
	    for (Camera *camera : this->m_cameras)
	    {
		const glm::mat4 &projection = camera->getProjection();
		const glm::mat4 &view = camera->getView();
		/////////////////////////////////////////////////////
		// Bind to m_framebuffer and draw to color texture
		// as we normally would.
		// //////////////////////////////////////////////////
		glBindFramebuffer(GL_FRAMEBUFFER, *fbIt);
		// Clear all attached buffers
		glClearColor(155.0f / 255.0f , 155.0f / 255.0f, 155.0f / 255.0f, 1.0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glEnable(GL_DEPTH_TEST);

		const glm::ivec2 &size = camera->size();
		glViewport(0, 0, size.x, size.y);

		for (Object *object : this->m_objects)
		{
		    const glm::mat4 &model = object->getTransform().getMatrix();
		    const std::list<Mesh *>     &meshes = object->getMeshes();
		    for (Mesh *part : meshes)
		    {
			part->draw(model, view, projection);
		    }
		}
		/////////////////////////////////////////////////////
		// Bind to default m_framebuffer again and draw the
		// quad plane with attched screen texture.
		////////////////////////////////////////////////////
		glBindFramebuffer(GL_FRAMEBUFFER, 0);
		// Clear all relevant buffers
		glClearColor(155.0f / 255.0f , 155.0f / 255.0f, 155.0f / 255.0f, 1.0);
		glClear(GL_COLOR_BUFFER_BIT);
		glDisable(GL_DEPTH_TEST); // We don't care about depth information when rendering a single quad

		// Draw Screen
		m_shaderFramebuff->bind();
		glBindVertexArray(m_quadVAO);
		glBindTexture(GL_TEXTURE_2D, *texIt);	// Use the color attachment texture as the texture of the quad plane
		glDrawArrays(GL_TRIANGLES, 0, 6);
		glBindVertexArray(0);
		m_shaderFramebuff->unbind();
		glDeleteTextures(1, &(*texIt));
		glDeleteFramebuffers(1, &(*fbIt));
		texIt++;
		fbIt++;
	    }
	    this->m_cameras.clear();
	    this->m_objects.clear();
	    this->m_lights.clear();
	    this->m_framebuffers.clear();
	    this->m_textureColorbuffers.clear();
	}
}
