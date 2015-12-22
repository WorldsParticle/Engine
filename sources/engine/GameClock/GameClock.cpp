# include "GameClock.hpp"

namespace WorldParticles
{
    namespace Engine
    {

        QTime   GameClock::_clock = QTime();
        int     GameClock::_surplus = 0;
    }
}
