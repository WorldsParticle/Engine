#include "Engine/Core/Event/KeyEvent.hpp"

namespace   WorldParticles
{
    namespace   Engine
    {

        KeyEvent::KeyEvent(int key, int action) : _key(key), _action(action)
        {

        }

        int KeyEvent::getKey()
        {
            return _key;
        }

        int KeyEvent::getAction()
        {
            return _action;
        }
    }
}
