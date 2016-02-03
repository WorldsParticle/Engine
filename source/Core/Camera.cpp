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

#include    "Engine/Core/Camera.hpp"
#include    "Engine/Core/SceneGraphNode.hpp"

namespace Engine
{

    Camera::Camera(SceneGraphNode *node) :
        Entity(node),
        m_clippingPlane{0.0f, 0.0f},
        m_aspect(0.0f),
        m_fov(0.0f),
        m_up(glm::vec3(0.0f)),
        m_lookat(glm::vec3(0.0f)),
        m_position(glm::vec3(0.0f))
    {
        // nothing to do.
    }

    Camera::Camera(const aiCamera *assimpCamera, SceneGraphNode *node) :
        Entity(node),
        m_clippingPlane{assimpCamera->mClipPlaneNear, assimpCamera->mClipPlaneFar},
        m_aspect(assimpCamera->mAspect),
        m_fov(assimpCamera->mHorizontalFOV * 2.0f),
        m_up(glm::vec3(0.0f)),
        m_lookat(glm::vec3(0.0f)),
        m_position(glm::vec3(0.0f))
    {
        this->m_node->setName(assimpCamera->mName.C_Str());
        auto convert = [&](const aiVector3D &v) {return glm::vec3(v.x, v.y, v.z);};
        this->m_up = convert(assimpCamera->mUp);
        this->m_lookat = convert(assimpCamera->mLookAt);
        this->m_position = convert(assimpCamera->mPosition);
    }

    Camera::~Camera(void)
    {
        // nothing to do.
    }

}
