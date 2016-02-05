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

#ifndef     __ENGINE_EVENT_MOUSE_BUTTON_PRESSED_HPP__
#define     __ENGINE_EVENT_MOUSE_BUTTON_PRESSED_HPP__

#include "Event.hpp"

namespace   Engine
{

    ///
    /// \brief Mouse Click.
    ///
    class   MouseButtonPressed : public Event
    {
        public:
            ///
            /// \brief Default constructor.
            ///
            MouseButtonPressed(int key, int x, int y);

            ///
            /// \brief Destructor.
            ///
            ~MouseButtonPressed(void) noexcept;

        public:
            ///
            /// \brief Get the mouse button key code.
            ///
            int     getKey();

            ///
            /// \brief Get the position of the mouse when the event happened.
            ///
            const glm::vec2     &get_position(void) const;

        private:
            ///
            /// \brief The pressed button code of the mouse.
            ///
            int         m_key;

            ///
            /// \brief The position of the mouse when the button has been pressed.
            ///
            glm::vec2   m_position;
    };
}

#endif // __ENGINE_EVENT_MOUSE_BUTTON_PRESSED_HPP__
