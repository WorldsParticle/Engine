#ifndef GAMECLOCK_H
#define GAMECLOCK_H

#include <QTime>

// TODO refaire la class de clock time.

namespace WorldParticles
{
    namespace Engine
    {
        ///
        /// \brief This class is used to represent the clock between frame and the world clock.
        ///
        /// This class should be entirely reworked.
        ///
        class GameClock
        {
            public:

                static inline void start()
                {
                    _surplus = 0;
                    _clock.start();
                }

                ///
                /// \brief Sets this time to the current time and returns the number of milliseconds
                /// that have elapsed since the last time start() or restart() was called.
                ///
                /// TODO : faire une abstraction de la clock avec un restart qui renvois directement le time elapsed.
                /// Cependant je ne peut pas faire les modifications car je ne comprend pas a quoi sert le "surplus".
                ///
                static inline void restart() {
                    _surplus = _clock.restart();
                }

                static inline int elapsedTime() {
                    return _clock.elapsed() + _surplus;
                }

            private:

                static QTime  _clock;

                // je sais pas comment dire en anglais ^^
                // Je comprend pas l'intéret en fait.
                static int    _surplus;
        };

    }
}

#endif // GAMECLOCK_H
