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

#pragma once

#include    <assimp/scene.h>

#include    "Engine/Configuration.hpp"

namespace   Engine
{
    class       Scene;
    class       SceneGraphNode;
    class       AssimpScene;
    class	ShaderProgramLibrary;

    class ENGINE_EXPORTS SceneGraph final
    {
        public:
            ///
            /// \brief Default constructor for the scene graph.
            ///
            /// This constructor will generate a empty scene graph.
            ///
            SceneGraph(Scene *scene, ShaderProgramLibrary &shaderprograms);

            ///
            /// \brief Constructor from an assimp scene graph.
            ///
            /// TODO GSL NOT NULL
            ///
            SceneGraph(const AssimpScene &assimpScene, Scene *scene, ShaderProgramLibrary &shaderprograms);

            ///
            /// \brief Copy constructor.
            ///
            SceneGraph(const SceneGraph &other);

            ///
            /// \brief Move constructor.
            ///
            SceneGraph(SceneGraph &&other) noexcept;

            ///
            /// \brief Destructor
            ///
            virtual ~SceneGraph(void) noexcept;

        public:
            ///
            /// \brief Copy assignment operator.
            ///
            SceneGraph  &operator=(const SceneGraph &other);

            ///
            /// \brief Move assignment operator.
            ///
            SceneGraph  &operator=(SceneGraph &&other) noexcept;

        public:
            ///
            /// \brief This method is used to recursively update the node in the scene graph.
            ///
            void    update(void);

        public:
            ///
            /// \brief Getter for the scene attribute.
            ///
            Scene   *getScene(void) const;

            ///
            /// \brief Getter for the root node.
            ///
            SceneGraphNode   *getRootNode(void) const;

        private:
            ///
            /// \brief The Scene represented by the scene graph.
            ///
            Scene   *m_scene; // TODO GSL NOT NULL

            ///
            /// \brief The root node of the graph.
            ///
            SceneGraphNode  *m_rootNode; // TODO GSL OWNER

            ///
            /// \brief The shader library
            ///
            ShaderProgramLibrary &m_shaderprograms;
    };
}
