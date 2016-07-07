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

#define     GLM_SWIZZLE
#define     GLM_SWIZZLE_XYZW
#include    <glm/glm.hpp>
#include    <glm/gtx/transform.hpp>
#include    <glm/gtc/matrix_transform.hpp>
#include    <log4cpp/Category.hh>
#include    <functional>

#include    "Engine/Core/Scene.hpp"
#include    "Engine/Core/SceneGraphNode.hpp"
#include    "Engine/Core/FreeflyCamera.hpp"
#include    "Engine/Event/Event.hpp"
#include    "Engine/Event/KeyPressed.hpp"
#include    "Engine/Event/MouseButtonPressed.hpp"
#include    "Engine/Event/MouseMove.hpp"
#include    "Engine/Input/Keyboard/Key.hpp"
#include    "Engine/Input/Mouse/Button.hpp"

using namespace     log4cpp;

namespace   Engine
{

    FreeflyCamera::FreeflyCamera(SceneGraphNode *node, ShaderProgramLibrary &shaderprograms) :
        PerspectiveCamera(node, shaderprograms),
        m_right(0.0f, 0.0f, 0.0f),
        m_look(0.0f, 1.0f, 0.0f),
        m_speed(2.0f),
        m_mouse_sensibility(0.0005f)
    {
        this->m_right = glm::normalize(glm::cross(glm::vec3(0.0f, 0.0f, 1.0f), this->m_look));
        this->m_up = glm::cross(this->m_look, this->m_right);
        this->update_matrix();

        using namespace     std::placeholders;
        node->getScene()->register_callback(Event::Type::KEY_PRESSED,
                std::bind(&FreeflyCamera::on_key_pressed, this, _1));
        node->getScene()->register_callback(Event::Type::MOUSE_MOVE,
                std::bind(&FreeflyCamera::on_mouse_move, this, _1));
    }

    FreeflyCamera::~FreeflyCamera(void)
    {

    }



    void
    FreeflyCamera::on_key_pressed(const Event::Event &event)
    {
        const Event::KeyPressed *key_pressed_event =
            dynamic_cast<const Event::KeyPressed *>(&event);

        if (key_pressed_event != nullptr)
        {
            switch (key_pressed_event->get_key())
            {
                case Keyboard::Key::Z:
                    this->forward(this->m_speed); break;
                case Keyboard::Key::Q:
                    this->left(this->m_speed); break;
                case Keyboard::Key::S:
                    this->backward(this->m_speed); break;
                case Keyboard::Key::D:
                    this->right(this->m_speed); break;
                default:
                    break;
            }
        }
    }

    void
    FreeflyCamera::on_mouse_move(const Event::Event &event)
    {
        const Event::MouseMove    *e = dynamic_cast<const Event::MouseMove *>(&event);

        if (e != nullptr)
        {
            float delta_x = static_cast<float>(this->m_size.x) / 2.0f - e->get_position().x;
            float delta_y = static_cast<float>(this->m_size.y) / 2.0f - e->get_position().y;
            this->yaw(delta_x * this->m_mouse_sensibility);
            this->pitch(delta_y * this->m_mouse_sensibility);
        }
    }

    void
    FreeflyCamera::forward(float distance)
    {
        this->m_position += this->m_look * distance;
        this->update_matrix();
    }

    void
    FreeflyCamera::backward(float distance)
    {
        this->m_position -= this->m_look * distance;
        this->update_matrix();
    }

    void
    FreeflyCamera::left(float distance)
    {
        this->m_position -= this->m_right * distance;
        this->update_matrix();
    }

    void
    FreeflyCamera::right(float distance)
    {
        this->m_position += this->m_right * distance;
        this->update_matrix();
    }

    /// horizontal rotation
    void
    FreeflyCamera::yaw(float degree)
    {
        glm::mat4   m = glm::rotate(degree, this->m_up);
        this->m_look = (m * glm::vec4(this->m_look, 0.0f)).xyz();
        this->m_right = (m * glm::vec4(this->m_right, 0.0f)).xyz();
        this->update_matrix();
    }

    /// vertical rotation
    void
    FreeflyCamera::pitch(float degree)
    {
        glm::mat4   m = glm::rotate(degree, this->m_right);
        this->m_look = (m * glm::vec4(this->m_look, 1.0f)).xyz();
        this->m_up = (m * glm::vec4(this->m_up, 1.0f)).xyz();
        this->update_matrix();
    }

    /// don't know how to explain that XD
    void
    FreeflyCamera::roll(float degree)
    {
        glm::mat4   m = glm::rotate(degree, this->m_look);
        this->m_up = (m * glm::vec4(this->m_up, 1.0f)).xyz();
        this->m_right = (m * glm::vec4(this->m_right, 1.0f)).xyz();
        this->update_matrix();
    }

    void
    FreeflyCamera::update_matrix(void)
    {
        this->m_view = glm::mat4(
                glm::vec4(this->m_right.x, this->m_up.x, -this->m_look.x, 0.0f),
                glm::vec4(this->m_right.y, this->m_up.y, -this->m_look.y, 0.0f),
                glm::vec4(this->m_right.z, this->m_up.z, -this->m_look.z, 0.0f),
                glm::vec4(glm::dot(this->m_right, this->m_position.xyz()) * -1.0f,
                    glm::dot(this->m_up, this->m_position.xyz()) * -1.0f,
                    glm::dot(-this->m_look, this->m_position.xyz()) * -1.0f, 1.0f)
            );
    }

}
