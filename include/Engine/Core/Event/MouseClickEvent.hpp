#ifndef     __MOUSE_KEY_EVENT_HPP__
#define     __MOUSE_KEY_EVENT_HPP__

#include "Event.hpp"

namespace   WorldParticles
{
    namespace   Engine
    {

        class MouseClickEvent : public Event {
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
};

#endif // __MOUSE_KEY_EVENT_HPP__
