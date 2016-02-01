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

#include    <stdexcept>

#include    "Engine/Event/Handler.hpp"

namespace   Engine
{

    EventHandler * EventHandler::self;

    EventHandler::EventHandler() :
        _mouseClickEvents(),
        _mouseMoveEvents(),
        _keyEvents()
    {

    }

    void
    EventHandler::init()
    {
        EventHandler::self = new EventHandler();
    }

    Event &
    EventHandler::getEvent(int eventType)
    {
        if (eventType == Event::MouseClick)
        {
            if (self->_mouseClickEvents.front().isConsumed())
                self->_mouseClickEvents.pop_front();
            self->_mouseClickEvents.front().consume();
            return (self->_mouseClickEvents.front());
        }
        else if (eventType == Event::MouseMove)
        {
            if (self->_mouseMoveEvents.front().isConsumed())
                self->_mouseMoveEvents.pop_front();
            self->_mouseMoveEvents.front().consume();
            return (self->_mouseMoveEvents.front());
        }
        else if (eventType == Event::Key)
        {
            if (self->_keyEvents.front().isConsumed())
                self->_keyEvents.pop_front();
            self->_keyEvents.front().consume();
            return (self->_keyEvents.front());
        }
        throw std::invalid_argument("evenType value unrecognized.");
    }


    std::size_t
    EventHandler::getEventCount(int eventType)
    {
        if (eventType == Event::MouseClick)
        {
            if (self->_mouseClickEvents.front().isConsumed())
                self->_mouseClickEvents.pop_front();
            return self->_mouseClickEvents.size();
        }
        else if (eventType == Event::MouseMove)
        {
            if (self->_mouseMoveEvents.front().isConsumed())
                self->_mouseMoveEvents.pop_front();
            return self->_mouseMoveEvents.size();
        }
        else if (eventType == Event::Key)
        {
            if (self->_keyEvents.front().isConsumed())
                self->_keyEvents.pop_front();
            return self->_keyEvents.size();
        }
        return (0);
    }

    void
    EventHandler::pushKeyEvent(int key, int action)
    {
        self->_keyEvents.emplace_back(key, action);
    }

    void
    EventHandler::pushMouseClickEvent(int key, int x, int y)
    {
        self->_mouseClickEvents.emplace_back(key, x, y);
    }

    void
    EventHandler::pushMouseMoveEvent(int x, int y)
    {
        self->_mouseMoveEvents.emplace_back(x, y);
    }

}
