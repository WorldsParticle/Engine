#ifndef __GAMEENGINE_HPP__
#define __GAMEENGINE_HPP__

#include    "worldparticles.hpp"

#include    "GameView.hpp"
#include    "SoundManager.hpp"

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
                /// \brief This function is use to update the scene.
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

                ///
                /// \brief This method is used to close the audio libs correcty.
                ///
		void	    closeAudio();

            protected:
                ///
                /// \brief This attribute is used to store each gameview present in the engine.
                ///
                std::list<std::shared_ptr<GameView>>    _gameviewList;

                ///
                /// \brief This attribute is used to store the sound manager.
                ///
		SoundManager				_soundManager;
        };

    }
}

#endif // __GAMEENGINE_HPP__
