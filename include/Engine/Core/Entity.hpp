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

#include    <string>

#include    "Engine/Configuration.hpp"

namespace   Engine
{

    class       Scene;
    class       SceneGraphNode;
    class       Transform;

    ///
    /// \brief This class is used to represent something physically or not in the 3D world.
    ///
    class ENGINE_EXPORTS Entity
    {
        public:
            ///
            /// \brief Default constructor
            /// \param node the node which the entity is attached.
            ///
            Entity(SceneGraphNode *node); // TODO GSL NOT NULL

            ///
            /// \brief Copy constructor.
            ///
            Entity(const Entity &other);

            ///
            /// \brief Move constructor.
            ///
            Entity(Entity &&other);

            ///
            /// \brief Destructor.
            ///
            virtual ~Entity(void) noexcept;

        public:
            ///
            /// \brief Copy assignment operator.
            ///
            Entity  &operator=(const Entity &other);

            ///
            /// \brief Move assignment operator.
            ///
            Entity  &operator=(Entity &&other);

        public:
            ///
            /// \brief clone pattern
            ///
            virtual Entity  *clone(void) const = 0;

        public:
            ///
            /// \brief method used to update the entity.
            ///
            virtual void    update(void) = 0;

        public:
            ///
            /// \brief Getter for the associated node name.
            ///
            virtual const std::string   &getName(void) const;

            ///
            /// \brief Getter for the transformation matrix of the associated node.
            ///
            const Transform             &getTransform(void) const;

        protected:
            ///
            /// \brief The node which the entity is attached.
            ///
            SceneGraphNode  *m_node; // TODO GSL NOT NULL

            ///
            /// \brief The scene that contains the Entity.
            ///
            Scene           *m_scene;
    };
}
