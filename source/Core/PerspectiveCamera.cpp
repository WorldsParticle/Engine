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
#include    "Engine/Core/SceneGraphNode.hpp"
#include    "Engine/Event/Resize.hpp"

using namespace     log4cpp;

namespace   Engine
{
    PerspectiveCamera::PerspectiveCamera(SceneGraphNode *node, ShaderProgramLibrary &shaderprograms) :
        Camera(node, shaderprograms),
        m_projection(glm::perspective(this->m_fov, this->m_aspect,
                this->m_clippingPlane.near, this->m_clippingPlane.far)),
        m_view(glm::lookAt(this->m_position, this->m_lookat, this->m_up))
    {
        node->getScene()->register_callback(Event::Type::RESIZE,
                std::bind(&PerspectiveCamera::on_resize_event, this, std::placeholders::_1));
        this->m_scene->add(this);
        m_transform_zero_test.translate(glm::vec3(0, 0, -500));
        m_transform_zero_test.print();
    }

    PerspectiveCamera::PerspectiveCamera(const aiCamera *assimpCamera,
            SceneGraphNode *node, ShaderProgramLibrary &shaderprograms) :
        Camera(assimpCamera, node, shaderprograms),
        m_projection(glm::mat4(1)),
        m_view(glm::mat4(1))
    {
        const Transform &transform = this->getTransform();
//        m_transform_zero_test.translate(glm::vec3(0, 0, 100));
//        m_transform_zero_test.print();

        glm::vec4 pos = transform.getMatrix() * glm::vec4(this->m_position, 1.0);
        glm::vec4 look = transform.getMatrix() * glm::vec4(this->m_lookat, 1.0);
        this->m_projection = glm::perspective(this->m_fov, this->m_aspect,
                this->m_clippingPlane.near, this->m_clippingPlane.far);
        this->m_view = glm::lookAt(pos.xyz(), look.xyz(), this->m_up);

        this->m_scene->add(this);

        std::cout << "look : " << look.x << "," << look.y << "," << look.z << std::endl;
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


    void
    PerspectiveCamera::on_resize_event(const Event::Event &event)
    {
        const Event::Resize     *resize_event = dynamic_cast<const Event::Resize *>(&event);

        if (resize_event != nullptr)
        {
            float   width = static_cast<float>(resize_event->size().x);
            float   height = static_cast<float>(resize_event->size().y);
            this->m_size = resize_event->size();
            this->m_aspect = width / height;
            this->m_projection = glm::perspective(this->m_fov, this->m_aspect,
            this->m_clippingPlane.near, this->m_clippingPlane.far);
	    //TODO koziar_c resize framebuffer
        }
    }
}
