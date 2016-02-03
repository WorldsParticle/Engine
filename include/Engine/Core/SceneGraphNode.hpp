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

#ifndef     __ENGINE_SCENE_GRAPH_NODE_HPP__
# define    __ENGINE_SCENE_GRAPH_NODE_HPP__

#include    <string>
#include    <list>
#include    <assimp/scene.h>

#include    "Engine/Core/Transform.hpp"

namespace   Engine
{

    class       Entity;
    class       SceneGraph;
    class       Scene;
    class       AssimpScene;

    ///
    /// \brief A Node of the scene graph.
    ///
    class       SceneGraphNode final
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
                    SceneGraphNode *parent = nullptr);

            ///
            /// \brief Copy constructor.
            ///
            SceneGraphNode(const SceneGraphNode &other) = default; // TODO TOTALEMENT FAUX

            ///
            /// \brief Move constructor.
            ///
            SceneGraphNode(SceneGraphNode &&other) noexcept = default; // TODO TOTALEMENT FAUX

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
            /// \brief Getter for the scene attribute.
            ///
            Scene               *getScene(void) const;

            ///
            /// \brief Getter for the tranformation of the node.
            ///
            const Transform     &getTransform(void) const;

        public:
            ///
            /// \brief Setter for the name attribute.
            ///
            void    setName(const std::string &name);

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
            /// \brief The scene that contain the scene graph related to this node.
            ///
            Scene   *m_scene; // TODO GSL NOT NULL

            ///
            /// \brief The entity related to the node.
            ///
            Entity  *m_entity; // TODO OWNER

            ///
            /// \brief The transformation affecting the node.
            ///
            Transform   m_transform;
    };
}

#endif /* !__ENGINE_SCENE_GRAPH_NODE_HPP__ */
