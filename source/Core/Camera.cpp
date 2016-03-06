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

#include    <glm/gtc/matrix_transform.hpp>
#include    <GL/glew.h>
#include    <log4cpp/Category.hh>

#include    "Engine/Core/Camera.hpp"
#include    "Engine/Core/SceneGraphNode.hpp"

using namespace     log4cpp;

namespace Engine
{

    Camera::Camera(SceneGraphNode *node) :
        Entity(node),
        m_clippingPlane{0.1f, 100.0f},
        m_aspect(4.0f/3.0f),
        m_fov(1.22173f),
        m_up(glm::vec3(0.0f, 1.0f, 0.0f)),
        m_lookat(glm::vec3(0.0f, 0.0f, 0.0f)),
        m_position(glm::vec3(10.0f, 10.0f, 10.0f)),
        m_size(glm::ivec2(1024, 768)),
	m_framebuffer(),
	m_textureColorbuffer()
    {
	createFramebuffer();
    }

    Camera::Camera(const aiCamera *assimpCamera, SceneGraphNode *node) :
        Entity(node),
        m_clippingPlane{assimpCamera->mClipPlaneNear, assimpCamera->mClipPlaneFar},
        m_aspect(assimpCamera->mAspect),
        m_fov(assimpCamera->mHorizontalFOV * 2.0f),
        m_up(glm::vec3(0.0f)),
        m_lookat(glm::vec3(0.0f)),
        m_position(glm::vec3(0.0f)),
        m_size(glm::ivec2(1024, 768)),
	m_framebuffer(),
	m_textureColorbuffer()
    {
        this->m_node->setName(assimpCamera->mName.C_Str());
        auto convert = [&](const aiVector3D &v) {return glm::vec3(v.x, v.y, v.z);};
        this->m_up = convert(assimpCamera->mUp);
        this->m_lookat = convert(assimpCamera->mLookAt);
        this->m_position = convert(assimpCamera->mPosition);
	createFramebuffer();
    }

    Camera::~Camera(void)
    {
	deleteFramebufferAndTexture();
    }


    const glm::ivec2 &
    Camera::size(void) const
    {
         return this->m_size;
    }

    void Camera::bindFramebuffer(void)
    {
	glBindFramebuffer(GL_FRAMEBUFFER, m_framebuffer);
    }

    void Camera::bindTexture(void)
    {
	glBindTexture(GL_TEXTURE_2D, m_textureColorbuffer);
    }

    void Camera::createTexture(void)
    {
	glGenTextures(1, &m_textureColorbuffer);
	glBindTexture(GL_TEXTURE_2D, m_textureColorbuffer);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_size.x, m_size.y, 0, GL_RGB,
		GL_UNSIGNED_BYTE, nullptr);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBindTexture(GL_TEXTURE_2D, 0);
	// Attach the texture to currently bound m_framebuffer object
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0,
		GL_TEXTURE_2D, m_textureColorbuffer, 0);
    }

    void Camera::createFramebuffer(void)
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
		is not complete! -add camera";
	}
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	glDeleteRenderbuffers(1, &rbo);
    }

    void Camera::deleteFramebufferAndTexture(void)
    {
	glDeleteTextures(1, &m_textureColorbuffer);
	glDeleteFramebuffers(1, &m_framebuffer);
    }
}
