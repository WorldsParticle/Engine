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

#include    "Engine/Event/KeyReleased.hpp"

namespace   Engine
{
    KeyReleased::KeyReleased(const Keyboard::Key &code) :
        Event(Event::Type::KEY_RELEASED),
        m_code(code)
    {

    }

    KeyReleased::~KeyReleased(void)
    {

    }



    const Keyboard::Key &
    KeyReleased::get_key(void) const
    {
         return this->m_code;
    }
}
