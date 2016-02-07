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

#ifndef     __ENGINE_EVENT_MOUSEBUTTONRELEASED_HPP__
# define    __ENGINE_EVENT_MOUSEBUTTONRELEASED_HPP__

#include    <glm/glm.hpp>

#include    "Engine/Event/Event.hpp"
#include    "Engine/Input/Mouse/Button.hpp"

namespace   Engine
{
    namespace   Event
    {
        class       MouseButtonReleased : public Event
        {
            public:
                ///
                /// \brief Default constructor.
                ///
                MouseButtonReleased(const Mouse::Button &code, const glm::vec2 &position);

                ///
                /// \brief Destructor.
                ///
                ~MouseButtonReleased(void);

            public:
                ///
                /// \brief Get the button code of the event.
                ///
                const Mouse::Button     &get_button(void) const;

                ///
                /// \brief Get the position of the mouse.
                ///
                const glm::vec2         &get_position(void) const;

            private:
                ///
                /// \brief The button code of the mouse.
                ///
                Mouse::Button       m_code;

                ///
                /// \brief The position of the mouse when the event was launch.
                ///
                glm::vec2           m_position;
        };
    }
}

#endif // !__ENGINE_EVENT_MOUSEBUTTONRELEASED_HPP__
