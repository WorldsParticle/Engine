#include "Engine/Core/Event/MouseClickEvent.hpp"

namespace   WorldParticles
{
    namespace   Engine
    {

    MouseClickEvent::MouseClickEvent(int key, int x, int y) :   _key(key),
                                                                _x(x),
                                                                _y(y)
    {

    }

        int MouseClickEvent::getKey()
        {
            return _key;
        }

        int MouseClickEvent::getX()
        {
            return _x;
        }

        int MouseClickEvent::getY()
        {
            return _y;
        }
    }
}
