///
/// \file Engine.hpp
///
/// \author Martin-Pierrat Louis (mart_p)
///
/// \date Sat, 16 Jan 2016 19:56:41
///
/// \version 1.0.7
///

#ifndef     __ENGINE_HPP__
#define     __ENGINE_HPP__

#include    "Scene.hpp"
#include    "AssimpImporter.hpp"

namespace WorldParticles
{
    namespace Engine
    {
        ///
        /// \brief This class is the entry point for the engine.
        ///
        class Engine
        {
            public:
                ///
                /// \brief Default constructor.
                ///
                Engine(void);

                ///
                /// \brief Copy constructor.
                ///
                Engine(const Engine &other);

                ///
                /// \brief Move constructor.
                ///
                Engine(Engine &&other) noexcept;

                ///
                /// \brief Destructor
                ///
                virtual ~Engine(void) noexcept;

            public:
                ///
                /// \brief Copy assignement operator.
                ///
                Engine  &operator=(const Engine &other);

                ///
                /// \brief Move assignement operator.
                ///
                Engine  &operator=(Engine &&other) noexcept;

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
