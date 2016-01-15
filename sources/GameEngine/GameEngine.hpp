///
/// \file GameEngine.hpp
///
/// \author Martin-Pierrat Louis (mart_p)
///
/// \date Fri, 15 Jan 2016 13:37:37
///
/// \version 1.0.1
///

#ifndef     __GAME_ENGINE_HPP__
#define     __GAME_ENGINE_HPP__

#include    "worldparticles.hpp"

#include    "Scene.hpp"
#include    "AssimpImporter.hpp"

namespace WorldParticles
{
    namespace Engine
    {
        ///
        /// \brief This class is the entry point for the engine.
        ///
        class GameEngine
        {
            public:
                ///
                /// \brief Default constructor.
                ///
                GameEngine(void);

                ///
                /// \brief Copy constructor.
                ///
                GameEngine(const GameEngine &other);

                ///
                /// \brief Move constructor.
                ///
                GameEngine(GameEngine &&other) noexcept;

                ///
                /// \brief Destructor
                ///
                virtual ~GameEngine(void) noexcept;

            public:
                ///
                /// \brief Copy assignement operator.
                ///
                GameEngine  &operator=(const GameEngine &other);

                ///
                /// \brief Move assignement operator.
                ///
                GameEngine  &operator=(GameEngine &&other) noexcept;

            public:
                ///
                /// \brief This function is used to update the world.
                ///
                void    update(void);

                ///
                /// \brief This function is used to render the world on the screen.
                ///
                void    render(void);

            public:
                ///
                /// \brief This method load a 3d scene from a file.
                ///
                /// Supported files : http://assimp.sourceforge.net/main_features_formats.html
                ///
                void    load(const std::string &filename);

            protected:
                ///
                /// \brief This attribute is used to store all scenes present in the engine.
                ///
                std::list<Scene *>      scenes; // TODO GSL NOT NULL && OWNER

                ///
                /// \brief The importer used to import new scene.
                ///
                AssimpImporter          importer;
        };

    }
}

#endif // __GAMEENGINE_HPP__
