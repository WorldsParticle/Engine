#ifndef     __EVENT_HANDLER_HPP__
#define     __EVENT_HANDLER_HPP__

#include <deque>

#include "Engine/Core/Event/MouseClickEvent.hpp"
#include "Engine/Core/Event/MouseMoveEvent.hpp"
#include "Engine/Core/Event/KeyEvent.hpp"

namespace   WorldParticles
{
    namespace   Engine
    {
        class EventHandler {
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
}

#endif // __EVENTHANDLER_HPP__
