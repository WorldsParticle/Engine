#ifndef     __SCENE_GRAPH_NODE_HPP__
# define    __SCENE_GRAPH_NODE_HPP__

namespace   WorldParticles
{
    namespace   Engine
    {
        class       SceneGraphNode
        {
            public:
                ///
                /// \brief Default constructor. Create an empty node.
                ///
                SceneGraphNode(SceneGraphNode *parent = 0);

                ///
                /// \brief Destructor.
                ///
                ~SceneGraphNode(void);

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
                ///
                ///
                std::list<std::shared_ptr<Mesh>>    meshes;
        };
    }
}
