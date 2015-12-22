#ifndef __GAMEENGINE_HPP__
#define __GAMEENGINE_HPP__

#include    "worldparticles.hpp"
#include    "Scene.hpp"

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
                /// \brief This method is used to initialise the game engine.
                ///
                bool        initialise(void);

                ///
                /// \brief This function is used to update the world.
                ///
                void        update(void);

                ///
                /// \brief This function is used to draw the world on the screen.
                ///
                void        draw(void);

            public:
                ///
                /// \brief This method should be used to load the world from a file.
                ///
                bool        load(const std::string &filename);

                ///
                /// \brief This method is used to add a new scene in the gameengine.
                ///
                void        add(Scene *scene);

            protected:
                ///
                /// \brief This attribute is used to store all scenes present in the engine.
                ///
                std::list<Scene *>      _scenes;
        };

    }
}

#endif // __GAMEENGINE_HPP__
