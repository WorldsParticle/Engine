#ifndef     __SCENE_GRAPH_NODE_HPP__
# define    __SCENE_GRAPH_NODE_HPP__

#include    <string>
#include    <list>
#include    <assimp/scene.h>

#include    "Transform.hpp"

namespace   WorldParticles
{
    namespace   Engine
    {

        class       Entity;
        class       SceneGraph;
        class       Scene;
        class       AssimpScene;

        ///
        /// \brief A Node of the scene graph.
        ///
        class       SceneGraphNode
        {
            public:
                ///
                /// \brief Default constructor. Create an empty node with a
                /// object entity.
                ///
                SceneGraphNode(SceneGraph *scenegraph,
                        SceneGraphNode *parent = 0);

                ///
                /// \brief Construct a SceneGraphNode from an assimp node.
                ///
                SceneGraphNode(const AssimpScene &assimpScene,
                        const aiNode *assimpNode, SceneGraph *scenegraph,
                        SceneGraphNode *parent = 0);

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
                Scene       *getScene(void) const;

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
                std::list<SceneGraphNode*>  childrens; // TODO GSL NOT NULL && OWNER

                ///
                /// \brief The scene graph that contain this node.
                ///
                SceneGraph                  *scenegraph;

                ///
                /// \brief The scene that contain the scene graph related to this node.
                ///
                Scene                       *scene; // TODO GSL NOT NULL

                ///
                /// \brief The entity related to the node.
                ///
                Entity                      *entity; // TODO OWNER

                ///
                /// \brief The transformation affecting the node.
                ///
                Transform                   transform;
        };
    }
}

#endif /* !__SCENE_GRAPH_NODE_HPP__ */
