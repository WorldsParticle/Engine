#ifndef __GAMEENGINE_HPP__
#define __GAMEENGINE_HPP__

#include    "worldparticles.hpp"

#include    "GameView.hpp"

namespace WorldParticles
{
    namespace Engine
    {
        ///
        /// \brief This class is used as a entry point of the worldparticle engine.
        ///
        class GameEngine
        {
            public:
                ///
                /// \brief Default constructor
                ///
                GameEngine(void);

                /// \brief Destructor
                ~GameEngine(void);

                ///
                /// \brief This function is use to update the scene.
                ///
                void    update(void);

                ///
                /// \brief This function is used to draw the scene on the screen.
                ///
                void    draw(void);

            private:
                ///
                /// \brief This attribute is used to store each gameview present in the engine.
                ///
                std::list<GameView *>     _gameviewList;
        };

    }
}

#endif // __GAMEENGINE_HPP__
