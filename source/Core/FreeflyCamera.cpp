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

#include    <glm/glm.hpp>
#include    <glm/gtc/matrix_transform.hpp>
#include    <log4cpp/Category.hh>
#include    <functional>

#include    "Engine/Core/Scene.hpp"
#include    "Engine/Core/SceneGraphNode.hpp"
#include    "Engine/Core/FreeflyCamera.hpp"

#include    "Engine/Event/Event.hpp"
#include    "Engine/Event/KeyPressed.hpp"

#include    "Engine/Input/Keyboard/Key.hpp"

using namespace     log4cpp;

namespace   Engine
{

    FreeflyCamera::FreeflyCamera(SceneGraphNode *node) :
        PerspectiveCamera(node),
        m_speed(0.1f)
    {
/*        this->m_projection = glm::perspective(this->m_fov, this->m_aspect,*/
                //this->m_clippingPlane.near, this->m_clippingPlane.far);
        //this->m_view = glm::lookAt(this->m_position, this->m_lookat, this->m_up);
        std::function<void(const Event::Event &)> callback =
            std::bind(&FreeflyCamera::on_key_pressed, this, std::placeholders::_1);

        node->getScene()->register_callback(Event::Type::KEY_PRESSED,
                callback);
    }

    FreeflyCamera::~FreeflyCamera(void)
    {

    }



    void
    FreeflyCamera::on_key_pressed(const Event::Event &event)
    {
        Category    &root = Category::getRoot();

        const Event::KeyPressed *key_pressed_event =
            dynamic_cast<const Event::KeyPressed *>(&event);

        if (key_pressed_event != nullptr)
        {
            root << Priority::DEBUG << "it's a KeyPressed event.";
            switch (key_pressed_event->get_key())
            {
                case Keyboard::Key::Z:
                    this->on_z_pressed(*key_pressed_event); break;
                case Keyboard::Key::Q:
                    root << Priority::DEBUG << "it's a Q"; break;
                case Keyboard::Key::S:
                    this->on_s_pressed(*key_pressed_event); break;
                case Keyboard::Key::D:
                    root << Priority::DEBUG << "it's a D"; break;
                default:
                    root << Priority::DEBUG << "something else."; break;
            }
        }
    }

    void
    FreeflyCamera::on_z_pressed(const Event::KeyPressed &event)
    {
        glm::vec3   dir = this->m_position - this->m_lookat;
        this->m_position -= dir * this->m_speed;
        this->m_view = glm::lookAt(this->m_position, this->m_lookat, this->m_up);
    }

    void
    FreeflyCamera::on_s_pressed(const Event::KeyPressed &event)
    {
        glm::vec3   dir = this->m_position - this->m_lookat;
        this->m_position += dir * this->m_speed;
        this->m_view = glm::lookAt(this->m_position, this->m_lookat, this->m_up);
    }

/*    void*/
    //FreeflyCamera::on_q_pressed(const Event::KeyPressed &event)
    //{
        //glm::vec3   dir = this->m_position - this->m_lookAt;

    //}

}
