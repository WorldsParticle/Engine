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

#ifndef     __KEY_EVENT_HPP__
#define     __KEY_EVENT_HPP__

#include "Event.hpp"

namespace   Engine
{
    class KeyEvent : public Event
    {
        public :

            enum Key
            {
                Z,
                Q,
                S,
                D,
                ESC
            };

            enum Action
            {
                PRESS,
                RELEASE
            };

            KeyEvent(int key, int action);

            int getKey();
            int getAction();

        private :
            int _key;
            int _action;
    };
}

#endif // __KEY_EVENT_HPP__
