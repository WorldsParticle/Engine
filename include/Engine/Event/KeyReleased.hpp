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

#ifndef         __ENGINE_EVENT_KEYRELEASED_HPP__
# define        __ENGINE_EVENT_KEYRELEASED_HPP__

#include    "Engine/Event/Event.hpp"
#include    "Engine/Input/Keyboard/Key.hpp"

namespace   Engine
{
    namespace   Event
    {
        ///
        /// \brief The KeyReleased event class, containing a key released event.
        ///
        class   KeyReleased : public Event
        {
            public:
                ///
                /// \brief Default constructor.
                ///
                KeyReleased(const Keyboard::Key &code);

                ///
                /// \brief Copy constructor.
                ///
                KeyReleased(const KeyReleased &other);

                ///
                /// \brief Move constructor.
                ///
                KeyReleased(KeyReleased &&other) noexcept;

                ///
                /// \brief Destructor.
                ///
                virtual ~KeyReleased(void) noexcept;

            public:
                ///
                /// \brief Copy assignment operator.
                ///
                void    operator=(const KeyReleased &other);

                ///
                /// \brief Move assignment operator.
                ///
                void    operator=(KeyReleased &&other) noexcept;

            public:
                ///
                /// \brief Get the key value of the keyreleased event.
                ///
                const Keyboard::Key     &get_key(void) const;

            private:
                ///
                /// \brief The key code of the key released.
                ///
                Keyboard::Key   m_code;

        };
    }
}

#endif // !__ENGINE_EVENT_KEYRELEASED_HPP__
