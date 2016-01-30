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

#ifndef     __MOUSE_KEY_EVENT_HPP__
#define     __MOUSE_KEY_EVENT_HPP__

#include "Event.hpp"

namespace   Engine
{

    class MouseClickEvent : public Event
    {
        public :
            MouseClickEvent(int key, int x, int y);

            int getKey();
            int getX();
            int getY();
        private :
            int _key;
            int _x;
            int _y;
    };
}

#endif // __MOUSE_KEY_EVENT_HPP__
