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
#include    <list>
#include    <assimp/scene.h>

#include    "Engine/Configuration.hpp"
#include    "Engine/Core/Transform.hpp"

namespace   Engine
{

    class       Entity;
    class       SceneGraph;
    class       Scene;
    class       AssimpScene;
    class	ShaderProgramLibrary;

    ///
    /// \brief A Node of the scene graph.
    ///
    class ENGINE_EXPORTS SceneGraphNode final
    {
        public:
            ///
            /// \brief Default constructor. Create an empty node with a
            /// object entity.
            ///
            SceneGraphNode(SceneGraph *scenegraph,
                    SceneGraphNode *parent = nullptr);

            ///
            /// \brief Construct a SceneGraphNode from an assimp node.
            ///
            SceneGraphNode(const AssimpScene &assimpScene,
                    const aiNode *assimpNode, SceneGraph *scenegraph,
		    ShaderProgramLibrary &shaderprograms,
                    SceneGraphNode *parent = nullptr, bool meshOnly = false, unsigned int previousMeshNumber = 0);

            ///
            /// \brief Copy constructor.
            ///
            SceneGraphNode(const SceneGraphNode &other);

            ///
            /// \brief Move constructor.
            ///
            SceneGraphNode(SceneGraphNode &&other) noexcept;

            ///
            /// \brief Destructor.
            ///
            virtual ~SceneGraphNode(void) noexcept;

        public:
            ///
            /// \brief Copy assignment operator.
            ///
            SceneGraphNode  &operator=(const SceneGraphNode &other) = default; // TODO TOTALEMENT FAUX

            ///
            /// \brief Move assignment operator.
            ///
            SceneGraphNode  &operator=(SceneGraphNode &&other) noexcept = default; // TODO TOTALEMENT FAUX

        public:
            ///
            /// \brief This method is used to update the node and the node children.
            ///
            void    update(void);

        public:
            ///
            /// \brief Getter for the name attribute.
            ///
            const std::string   &getName(void) const;

            ///
            /// \brief Getter for the parent node.
            ///
            SceneGraphNode      *getParent(void) const;

            ///
            /// \brief Getter for the scene that contain the scene graph related to this node
            ///
            Scene               *getScene(void) const;

            Entity              *getEntity(void) const;

            ///
            /// \brief Getter for the tranformation of the node.
            ///
            Transform            &getTransform(void);

        public:
            ///
            /// \brief Setter for the name attribute.
            ///
            void    setName(const std::string &name);

            ///
            /// \brief Change the previous parent of the node by the one provided.
            ///
            void    setParent(SceneGraphNode *parent);

            ///
            /// \brief Change the previous entity of the node by the one provided.
            ///
            void    setEntity(Entity *entity);

            void    setTransform(Transform const& transform);

//#warning Temporary function
            ///
            /// \brief Add a children in this node.
            ///
            /// This method automaticaly change the parent of the node provided.
            ///
            /// TODO GSL NOT NULL && OWNER
            ///
            void    addChildren(SceneGraphNode *child);

        private:
            ///
            /// \brief Optional name for the node. Can be empty.
            ///
            std::string     m_name;

            ///
            /// \brief The node parent, can be null if this node is a root node.
            ///
            SceneGraphNode  *m_parent;

            ///
            /// \brief The childrens of the node.
            ///
            std::list<SceneGraphNode*>  m_childrens; // TODO GSL NOT NULL && OWNER

            ///
            /// \brief The scene graph that contain this node.
            ///
            SceneGraph  *m_scenegraph;

            ///
            /// \brief The entity related to the node.
            ///
            Entity  *m_entity; // TODO OWNER

            ///
            /// \brief The local transformation affecting the node.
            ///
            Transform   m_transform;

            ///
            /// \brief The real transformation affecting the node
            /// (taking its parents into account).
            ///
            Transform   m_worldTransform;
    };
}
