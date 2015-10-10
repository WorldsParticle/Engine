#ifdef _WIN32
# include "engine/gameclock.h"
#else
# include "gameclock.h"
#endif

QTime   GameClock::_clock = QTime();
int     GameClock::_surplus = 0;
