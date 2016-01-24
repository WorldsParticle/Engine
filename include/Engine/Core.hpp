///
/// \file Core.hpp
///
/// \author Martin-Pierrat Louis (mart_p)
///
/// \date Sat, 16 Jan 2016 22:29:17
///
/// \version 1.1.1
///

#ifndef     __ENGINE_CORE_HPP__
#define     __ENGINE_CORE_HPP__

#include    "Engine/Core/Scene.hpp"
#include    "Engine/Core/AssimpImporter.hpp"

namespace Engine
{
    ///
    /// \brief This class is the entry point for the engine library.
    ///
    class   Core
    {
        public:
            ///
            /// \brief Default constructor.
            ///
            Core(void);

            ///
            /// \brief Copy constructor.
            ///
            Core(const Core &other);

            ///
            /// \brief Move constructor.
            ///
            Core(Core &&other) noexcept;

            ///
            /// \brief Destructor
            ///
            virtual ~Core(void) noexcept;

        public:
            ///
            /// \brief Copy assignement operator.
            ///
            Core  &operator=(const Core &other);

            ///
            /// \brief Move assignement operator.
            ///
            Core  &operator=(Core &&other) noexcept;

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

#endif // __ENGINE_CORE_HPP__
