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

#include    "Engine/Event/EventRegister.hpp"
#include    "Engine/Event/Event.hpp"

namespace   Engine
{
    namespace   Event
    {
        EventRegister::EventRegister(void) :
            m_temporary()
        {

        }

        EventRegister::~EventRegister(void)
        {

        }

        void
        EventRegister::push_event(const Event &event)
        {
            const Type   event_type = event.get_type();
            for (std::function<void(const Event &event)> &callback : this->m_temporary[event_type])
            {
                callback(event);
            }
        }

        void
        EventRegister::register_callback(const Type &event_type,
                const std::function<void(const Event &)> &callback)
        {
            this->m_temporary[event_type].push_back(callback);
        }
    }
}
