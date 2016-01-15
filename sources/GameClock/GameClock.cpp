///
/// \file GameClock.cpp
///
/// \author Martin-Pierrat Louis (mart_p)
///
/// \date Fri, 15 Jan 2016 13:29:54
///
/// \version 1.0.1
///

# include "GameClock.hpp"

namespace WorldParticles
{
    namespace Engine
    {

        QTime   GameClock::_clock = QTime();
        int     GameClock::_surplus = 0;
    }
}
