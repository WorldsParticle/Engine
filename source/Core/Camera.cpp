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
    Camera::Camera(SceneGraphNode *node, const ShaderProgramLibrary &shaderprograms) :
        Entity(node),
        m_clippingPlane{0.1f, 100.0f},
        m_aspect(4.0f/3.0f),
        m_fov(1.22173f),
        m_up(glm::vec3(0.0f, 1.0f, 0.0f)),
        m_lookat(glm::vec3(0.0f, 0.0f, 0.0f)),
        m_position(glm::vec3(10.0f, 10.0f, 10.0f)),
        m_size(glm::ivec2(1024, 768)),
	m_framebuffer(std::make_shared<Framebuffer>(shaderprograms, m_size))
    {
    }

    Camera::Camera(const aiCamera *assimpCamera, SceneGraphNode *node, const ShaderProgramLibrary &shaderprograms) :
        Entity(node),
        m_clippingPlane{assimpCamera->mClipPlaneNear, assimpCamera->mClipPlaneFar},
        m_aspect(assimpCamera->mAspect),
        m_fov(assimpCamera->mHorizontalFOV * 2.0f),
        m_up(glm::vec3(0.0f)),
        m_lookat(glm::vec3(0.0f)),
        m_position(glm::vec3(0.0f)),
        m_size(glm::ivec2(1024, 768)),
	m_framebuffer(std::make_shared<Framebuffer>(shaderprograms, m_size))
    {
        this->m_node->setName(assimpCamera->mName.C_Str());
        auto convert = [&](const aiVector3D &v) {return glm::vec3(v.x, v.y, v.z);};
        this->m_up = convert(assimpCamera->mUp);
        this->m_lookat = convert(assimpCamera->mLookAt);
        this->m_position = convert(assimpCamera->mPosition);
    }

    Camera::~Camera(void)
    {
    }


    const glm::ivec2 &
    Camera::size(void) const
    {
         return this->m_size;
    }

    void Camera::bindFramebuffer(void)
    {
	m_framebuffer->bind();
    }

    void Camera::unbindFramebuffer(void)
    {
	m_framebuffer->unbind();
    }

    void Camera::drawFramebuffer(void)
    {
	m_framebuffer->draw();
    }
}
