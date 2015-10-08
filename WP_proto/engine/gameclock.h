#ifndef GAMECLOCK_H
#define GAMECLOCK_H

#include <QTime>

class GameClock
{
public:
    static inline void start() {
        _surplus = 0;
        _clock.start();
    }

    static inline int restart() {
        _surplus = _clock.restart();
    }

    static inline int elapsedTime() {
        return _clock.elapsed() + _surplus;
    }

private:
    static QTime  _clock;
    static int    _surplus; // je sais pas comment dire en anglais ^^
};

#endif // GAMECLOCK_H
