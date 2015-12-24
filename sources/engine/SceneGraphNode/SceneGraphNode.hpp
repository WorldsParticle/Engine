#ifndef     __SCENE_GRAPH_NODE_HPP__
# define    __SCENE_GRAPH_NODE_HPP__

#include    "Entity.hpp"

namespace   WorldParticles
{
    namespace   Engine
    {
        class       SceneGraphNode
        {
            public:
                ///
                /// \brief Default constructor. Create an empty node with a object entity.
                ///
                SceneGraphNode(SceneGraphNode *parent = 0);

                ///
                /// \brief Copy constructor.
                ///
                SceneGraphNode(const SceneGraphNode &other);

                ///
                /// \brief Move constructor.
                ///
                SceneGraphNode(SceneGraphNode &&other);

                ///
                /// \brief Destructor.
                ///
                virtual ~SceneGraphNode(void) noexcept;

            public:
                ///
                /// \brief Copy assignment operator.
                ///
                SceneGraphNode  &operator=(const SceneGraphNode &other);

                ///
                /// \brief Move assignment operator.
                ///
                SceneGraphNode  &operator=(SceneGraphNode &&other);

            public:
                ///
                /// \brief This method is used to update the node and the node children.
                ///
                void    update(void);

            private:
                ///
                /// \brief Optional name for the node. Can be empty.
                ///
                std::string                 name;

                ///
                /// \brief The node parent, can be null if this node is a root node.
                ///
                SceneGraphNode              *parent;

                ///
                /// \brief The childrens of the node.
                ///
                std::list<SceneGraphNode*>  childrens;

                ///
                /// \brief The entity related to the node.
                ///
                Entity                      *entity; // TODO GSL NOT NULL & OWNER
        };
    }
}
