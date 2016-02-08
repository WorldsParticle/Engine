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

#ifndef     __ENGINE_EVENT_TYPES_HPP__
# define    __ENGINE_EVENT_TYPES_HPP__

namespace   Engine
{
    namespace   Event
    {
        ///
        /// \brief existing event type
        ///
        enum    Type
        {
            KEY_PRESSED, // \brief TODO
            KEY_RELEASED,
            MOUSE_BUTTON_PRESSED,
            MOUSE_BUTTON_RELEASED,
            MOUSE_MOVE,
            RESIZE
        };
    }
}

#endif // !__ENGINE_EVENT_TYPES_HPP__