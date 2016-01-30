#ifndef     __KEY_EVENT_HPP__
#define     __KEY_EVENT_HPP__

#include "Event.hpp"



namespace   WorldParticles
{
    namespace   Engine
    {

        class KeyEvent : public Event {
        public :

            enum Key {
            Z,
            Q,
            S,
            D,
            ESC
            };

            enum Action {
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
};

#endif // __KEY_EVENT_HPP__
