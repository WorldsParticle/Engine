#include "Engine/Core/EventHandler.hpp"

namespace   WorldParticles
{
        namespace   Engine
        {

        EventHandler * EventHandler::self;

        void EventHandler::init()
        {
            EventHandler::self = new EventHandler();
        }

        Event & EventHandler::getEvent(int eventType)
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
        }


        int EventHandler::getEventCount(int eventType)
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

        void EventHandler::pushKeyEvent(int key, int action)
        {
            self->_keyEvents.emplace_back(key, action);
        }

        void EventHandler::pushMouseClickEvent(int key, int x, int y)
        {
            self->_mouseClickEvents.emplace_back(key, x, y);
        }

        void EventHandler::pushMouseMoveEvent(int x, int y)
        {

            self->_mouseMoveEvents.emplace_back(x, y);
        }

        }
}
