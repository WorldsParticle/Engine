#ifndef     __MOUSE_MOVE_EVENT_HPP__
#define     __MOUSE_MOVE_EVENT_HPP__

#include "Event.hpp"

namespace   WorldParticles
{
    namespace   Engine
    {

        class MouseMoveEvent : public Event {
        public :
            MouseMoveEvent(int x, int y);

            int getX() const;
            int getY() const;
        private :
            int _x;
            int _y;
        };
    }
};

#endif // __MOUSE_MOVE_EVENT_HPP__
