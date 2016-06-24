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

#include    <list>
#include    <assimp/scene.h>

#include    "Engine/Configuration.hpp"
#include    "Engine/Core/Entity.hpp"

namespace   Engine
{

    class   Mesh;

    ///
    /// \brief This class is used to represent a physical entity.
    ///
    class ENGINE_EXPORTS Object : public Entity
    {
        public:
            ///
            /// \brief Default constructor.
            /// \param node the node related to the object.
            ///
            Object(SceneGraphNode *node); // TODO GSL NOT NULL

            ///
            /// \brief Construct from scene.
            /// \param scene related to the object.
            ///
            Object(Scene *scene);

            ///
            /// \brief Construct an object from an assimp node.
            ///
            Object(const aiNode *assimpNode, SceneGraphNode *node, unsigned int previousMeshNumber); // TODO GSL NOT NULL

            ///
            /// \brief Copy constructor.
            ///
            Object(const Object &other) = default;

            ///
            /// \brief Move constructor.
            ///
            Object(Object &&other) noexcept = default;

            ///
            /// \brief Destructor.
            ///
            virtual ~Object(void) noexcept;

        public:
            ///
            /// \brief Copy assignment operator.
            ///
            Object  &operator=(const Object &other) = default;

            ///
            /// \brief Move assigment operator.
            ///
            Object  &operator=(Object &&other) noexcept = default;

        public:
            ///
            /// \brief This method is used to clone the object.
            ///
            Object  *clone(void) const override;

            ///
            /// \brief Update the object.
            ///
            void    update(void) override;
            
            ///
            /// \brief Change the scene in which the object is.
            /// \param node the node related to the object in the new scene
            ///
            void    moveToScene(SceneGraphNode *node);


        public:
            ///
            /// \brief Getter for the mesh list.
            ///
            const std::list<Mesh *>     &getMeshes(void) const;

        protected:
            ///
            /// \brief The meshes associated with the object.
            ///
            std::list<Mesh *>     m_meshes; // TODO GSL NOT NULL
    };
}
