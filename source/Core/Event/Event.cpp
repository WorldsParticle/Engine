#include "Engine/Core/Event/Event.hpp"

namespace   WorldParticles
{
    namespace   Engine
    {
        Event::Event() : _consumed(false)
        {

        }

        bool Event::isConsumed() const
        {
            return (_consumed);
        }

        void Event::consume()
        {
           _consumed = true;
        }
    }
}
