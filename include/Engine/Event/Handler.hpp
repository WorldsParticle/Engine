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

#ifndef     __EVENT_HANDLER_HPP__
#define     __EVENT_HANDLER_HPP__

#include <deque>

#include "Engine/Event/MouseClickEvent.hpp"
#include "Engine/Event/MouseMoveEvent.hpp"
#include "Engine/Event/KeyEvent.hpp"

namespace   Engine
{
    class EventHandler
    {
        public :

            static void init();
            static Event & getEvent(int eventType);
            static int getEventCount(int eventType);
            static void pushKeyEvent(int key, int action);
            static void pushMouseMoveEvent(int x, int y);
            static void pushMouseClickEvent(int key, int x, int y);

        private :
            static EventHandler * self;

            std::deque<MouseClickEvent> _mouseClickEvents;
            std::deque<MouseMoveEvent> _mouseMoveEvents;
            std::deque<KeyEvent> _keyEvents;
    };
}

#endif // __EVENTHANDLER_HPP__
