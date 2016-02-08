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

#include "Engine/Event/MouseMove.hpp"

namespace   Engine
{
    namespace   Event
    {
        MouseMove::MouseMove(const Mouse::Button &code, const glm::vec2 &position) :
            Event(Type::MOUSE_MOVE),
            m_position(position),
            m_code(code)
        {

        }

        MouseMove::~MouseMove(void) noexcept
        {

        }


        const Mouse::Button &
        MouseMove::get_button(void) const
        {
            return this->m_code;
        }

        const glm::vec2 &
        MouseMove::get_position(void) const
        {
            return this->m_position;
        }
    }
}
