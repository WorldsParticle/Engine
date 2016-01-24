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

namespace Engine
{

    Camera::Camera(SceneGraphNode *node) :
        Entity(node),
        name(""),
        clippingPlane{0.0f, 0.0f},
        aspect(0.0f),
        fov(0.0f),
        up(glm::vec3(0.0f)),
        lookat(glm::vec3(0.0f)),
        position(glm::vec3(0.0f))
    {
        // nothing to do.
    }

    Camera::Camera(const aiCamera *assimpCamera, SceneGraphNode *node) :
        Entity(node),
        name(assimpCamera->mName.C_Str()),
        clippingPlane{assimpCamera->mClipPlaneNear, assimpCamera->mClipPlaneFar},
        aspect(assimpCamera->mAspect),
        fov(assimpCamera->mHorizontalFOV * 2.0f),
        up(glm::vec3(0.0f)),
        lookat(glm::vec3(0.0f)),
        position(glm::vec3(0.0f))
    {
        auto convert = [&](const aiVector3D &v) {return glm::vec3(v.x, v.y, v.z);};
        this->up = convert(assimpCamera->mUp);
        this->lookat = convert(assimpCamera->mLookAt);
        this->position = convert(assimpCamera->mPosition);
    }

    Camera::~Camera(void)
    {
        // nothing to do.
    }



    const std::string &
    Camera::getName(void) const
    {
         return this->name;
    }
}
