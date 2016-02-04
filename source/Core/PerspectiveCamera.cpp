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

#include    <log4cpp/Category.hh>
#define     GLM_SWIZZLE
#define     GLM_SWIZZLE_XYZW
#include    <glm/glm.hpp>
#include    <glm/gtc/matrix_transform.hpp>

#include    "Engine/Core/Transform.hpp"
#include    "Engine/Core/PerspectiveCamera.hpp"
#include    "Engine/Core/Scene.hpp"

using namespace     log4cpp;

namespace   Engine
{
    PerspectiveCamera::PerspectiveCamera(SceneGraphNode *node) :
        Camera(node),
        m_projection(glm::mat4(1)),
        m_view(glm::mat4(1))
    {
        this->m_projection = glm::perspective(this->m_fov, this->m_aspect,
                this->m_clippingPlane.near, this->m_clippingPlane.far);
        this->m_view = glm::lookAt(this->m_position, this->m_lookat, this->m_up);

        this->m_scene->add(this);

    }

    PerspectiveCamera::PerspectiveCamera(const aiCamera *assimpCamera,
            SceneGraphNode *node) :
        Camera(assimpCamera, node),
        m_projection(glm::mat4(1)),
        m_view(glm::mat4(1))
    {
        Category    &root = Category::getRoot();

        const Transform &transform = this->getTransform();
        glm::vec4 realPosition = transform.getMatrix() * glm::vec4(this->m_position, 1.0);

        root << Priority::DEBUG << "Camera fov " << this->m_fov;
        root << Priority::DEBUG << "Camera aspect " << this->m_aspect;
        root << Priority::DEBUG << "Camera near " << this->m_clippingPlane.near;
        root << Priority::DEBUG << "Camera far " << this->m_clippingPlane.far;
        root << Priority::DEBUG << "Camera position " << realPosition.x << " " << realPosition.y << " " << realPosition.z;
        root << Priority::DEBUG << "Camera lookat " << this->m_lookat.x << " " << this->m_lookat.y << " " << this->m_lookat.z;
        root << Priority::DEBUG << "Camera up " << this->m_up.x << " " << this->m_up.y << " " << this->m_up.z;

        this->m_projection = glm::perspective(this->m_fov, this->m_aspect,
                this->m_clippingPlane.near, this->m_clippingPlane.far);
        this->m_view = glm::lookAt(realPosition.xyz(), this->m_lookat, this->m_up);

        this->m_scene->add(this);
    }

    PerspectiveCamera::~PerspectiveCamera(void)
    {
        // nothing to do.
    }



    PerspectiveCamera *
    PerspectiveCamera::clone(void) const
    {
        return new PerspectiveCamera(*this);
    }

    void
    PerspectiveCamera::update(void)
    {
        // nothing to do.
    }



    const glm::mat4 &
    PerspectiveCamera::getProjection(void) const
    {
         return this->m_projection;
    }

    const glm::mat4 &
    PerspectiveCamera::getView(void) const
    {
         return this->m_view;
    }
}