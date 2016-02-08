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

#ifndef     __MOUSE_MOVE_EVENT_HPP__
#define     __MOUSE_MOVE_EVENT_HPP__

#include    <glm/glm.hpp>

#include    "Engine/Event/Event.hpp"
#include    "Engine/Input/Mouse/Button.hpp"

namespace   Engine
{
    namespace   Event
    {
        class MouseMove : public Event
        {
            public:
                ///
                /// \brief Default constructor.
                ///
                MouseMove(const Mouse::Button &code, const glm::vec2 &position);

                ///
                /// \brief Destructor.
                ///
                virtual ~MouseMove(void) noexcept;

            public:
                ///
                /// \brief Get the mouse position.
                ///
                const glm::vec2     &get_position(void) const;

                ///
                /// \brief Get the button.
                ///
                const Mouse::Button &get_button(void) const;

            private:
                ///
                /// \brief The mouse position.
                ///
                glm::vec2           m_position;

                ///
                /// \brief The button pressed if existing.
                ///
                Mouse::Button       m_code;
        };
    }
}

#endif // __MOUSE_MOVE_EVENT_HPP__
