//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 3 of the License, or
// any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this program; If not, see <http://www.gnu.org/licenses/>.
//
// Copyright (C) 2016 Martin-Pierrat Louis (louismartinpierrat@gmail.com)
//

#ifndef     __ENGINE_CORE_HPP__
#define     __ENGINE_CORE_HPP__

#include    "Engine/Configuration.hpp"
#include    "Engine/Core/AssimpImporter.hpp"

namespace Engine
{

    namespace   Event
    {
        class       Event;
    }

    class   Scene;
    ///
    /// \brief This class is the entry point for the engine library.
    ///
    class ENGINE_EXPORTS Core
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

            ///
            /// \brief This function is used to produce an event on the engine.
            ///
            void    push_event(const Event::Event &event);

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
            std::list<Scene *>      m_scenes; // TODO GSL NOT NULL && OWNER

            ///
            /// \brief The importer used to import new scene.
            ///
            AssimpImporter          m_importer;
    };
}

#endif // __ENGINE_CORE_HPP__
