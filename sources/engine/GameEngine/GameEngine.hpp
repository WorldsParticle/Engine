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

                ///
                /// \brief Destructor
                ///
                virtual     ~GameEngine(void);

            public:
                ///
                /// \brief This method is used to initialise the game engine itself.
                ///
                bool    initialise(void);

                ///
                /// \brief This function is used to update the scene.
                ///
                void        update(void);

                ///
                /// \brief This function is used to draw the scene on the screen.
                ///
                void        draw(void);

            public:
                ///
                /// \brief This method is used to add a gameview in the gameengine.
                ///
                void        AddGameView(const std::shared_ptr<GameView> &gameview);

            protected:
                ///
                /// \brief This attribute is used to store each gameview present in the engine.
                /// TODO : je ne pense pas que le shared_ptr soit réellement utile ici
                std::list<std::shared_ptr<GameView>>    _gameviewList;
        };

    }
}

#endif // __GAMEENGINE_HPP__
