#include "Engine/Core/Event/MouseMoveEvent.hpp"

namespace   WorldParticles
{
    namespace   Engine
    {

        MouseMoveEvent::MouseMoveEvent(int x, int y) : _x(x),
                                                       _y(y)
        {

        }

        int MouseMoveEvent::getX() const
        {
            return _x;
        }

        int MouseMoveEvent::getY() const
        {
            return _y;
        }
    }
}
