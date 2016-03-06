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

#include    "Engine/Core/Renderer.hpp"
#include    "Engine/Core/Object.hpp"
#include    "Engine/Core/Camera.hpp"
#include    "Engine/Core/Light.hpp"
#include    "Engine/Core/Transform.hpp"
#include    "Engine/Core/Mesh.hpp"
#include    "Engine/Core/ArrayObject.hpp"

namespace   Engine
{
    Renderer::Renderer(const ShaderProgramLibrary &shaderprograms, Scene *scene) :
	m_scene(scene),
	m_objects(),
	m_cameras(),
	m_lights(),
	m_shaderFramebuff(shaderprograms.get(FRAMEBUFFER_SHADER_PROGRAM)),
	m_vao(std::make_shared<ArrayObject>())
    {
	GLfloat quadVertices[] = {   // Vertex attributes for a simple quad
	    // Positions   // TexCoords
	    -1.0f,  1.0f,  0.0f, 1.0f,
	    -1.0f, -1.0f,  0.0f, 0.0f,
	    1.0f, -1.0f,  1.0f, 0.0f,

	    -1.0f,  1.0f,  0.0f, 1.0f,
	    1.0f, -1.0f,  1.0f, 0.0f,
	    1.0f,  1.0f,  1.0f, 1.0f
	};
	unsigned int vbo;
	glGenBuffers(1, &vbo);
	m_vao->bind();
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(quadVertices), &quadVertices, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), nullptr);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), reinterpret_cast<GLvoid*>(2 * sizeof(GLfloat)));
	m_vao->unbind();
    }

    Renderer::Renderer(const Renderer &other) :
	m_scene(other.m_scene),
	m_objects(),
	m_cameras(other.m_cameras),
	m_lights(),
	m_shaderFramebuff(other.m_shaderFramebuff),
	m_vao(other.m_vao)
    {
    }

    Renderer::Renderer(Renderer &&other) noexcept :
	m_scene(std::move(other.m_scene)),
	m_objects(),
	m_cameras(std::move(other.m_cameras)),
	m_lights(),
	m_shaderFramebuff(std::move(other.m_shaderFramebuff)),
	m_vao(std::move(other.m_vao))
	{
	}

    Renderer::~Renderer(void) noexcept
    {
    }

    Renderer &
	Renderer::operator=(const Renderer &other)
	{
	    this->m_scene = other.m_scene;
	    this->m_vao = other.m_vao;
	    return *this;
	}

    Renderer &
	Renderer::operator=(Renderer &&other) noexcept
	{
	    this->m_scene = std::move(other.m_scene);
	    this->m_vao = std::move(other.m_vao);
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
	    //Category& root = Category::getRoot();
	    //const glm::ivec2 &size = camera->size();

	    //root << Priority::DEBUG << "Renderer - add camera()" << camera->getName();
	    this->m_cameras.push_back(camera);
	}

    void
	Renderer::add(Light *light)
	{
	    //Category &root = Category::getRoot();

	    //root << Priority::DEBUG << "Renderer - add light() : " << light->getName();
	    this->m_lights.push_back(light);
	}

    void
	Renderer::renderTextureToScreen(Camera *camera)
	{
	    // Bind to default framebuffer and draw a quad with the screen texture
	    glBindFramebuffer(GL_FRAMEBUFFER, 0);
	    glClearColor(155.0f / 255.0f , 155.0f / 255.0f, 155.0f / 255.0f, 1.0);
	    glClear(GL_COLOR_BUFFER_BIT);
	    glDisable(GL_DEPTH_TEST); // depth useless for the quad

	    // Draw Screen
	    m_shaderFramebuff->bind();
	    m_vao->bind();
	    camera->bindTexture();
	    glDrawArrays(GL_TRIANGLES, 0, 6);
	    m_vao->unbind();
	    m_shaderFramebuff->unbind();
	}

    void
	Renderer::render(void)
	{
	    for (Camera *camera : this->m_cameras)
	    {
		const glm::mat4 &projection = camera->getProjection();
		const glm::mat4 &view = camera->getView();
		// Bind to framebuffer and draw to color texture as we normally would.
		camera->bindFramebuffer();
		glClearColor(155.0f / 255.0f , 155.0f / 255.0f, 155.0f / 255.0f, 1.0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glEnable(GL_DEPTH_TEST);

		const glm::ivec2 &size = camera->size();
		glViewport(0, 0, size.x, size.y);

		for (Object *object : this->m_objects)
		{
		    const glm::mat4 &model = object->getTransform().getMatrix();
		    const std::list<Mesh *> &meshes = object->getMeshes();
		    for (Mesh *part : meshes)
		    {
			part->draw(model, view, projection);
		    }
		}
		renderTextureToScreen(camera);
	    }
	    this->m_cameras.clear();
	    this->m_objects.clear();
	    this->m_lights.clear();
	}
}
