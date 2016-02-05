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

#ifndef     __ENGINE_EVENT_KEYPRESSED_HPP__
#define     __ENGINE_EVENT_KEYPRESSED_HPP__

#include    "Event.hpp"

namespace   Engine
{
    ///
    /// \brief The KeyEvent class, containing key event.
    ///
    class KeyPressed final : public Event
    {
        public:

            enum Key
            {
                Z,
                Q,
                S,
                D,
                ESC
            };

        public:
            ///
            /// \brief Default constructor.
            ///
            KeyEvent(Key value, int action);

            ///
            /// \brief Copy constructor.
            ///
            KeyEvent(const KeyEvent &other);

            ///
            /// \brief Move constructor.
            ///
            KeyEvent(KeyEvent &&other) noexcept;

            ///
            /// \brief Destructor.
            ///
            virtual ~KeyEvent(void) noexcept;

        public:
            ///
            /// \brief Copy assignment operator.
            ///
            void    operator=(const KeyPressed &other);

            ///
            /// \brief Move assignment operator.
            ///
            void    operator=(KeyPressed &&other);

        public:
            int getKey();
            int getAction();

        private:
            ///
            /// \brief The key code of the key pressed.
            ///
            Key     m_key;
    };
}

#endif // __KEY_EVENT_HPP__
