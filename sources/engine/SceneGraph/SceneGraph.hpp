#ifndef     __SCENE_GRAPH_HPP__
# define    __SCENE_GRAPH_HPP__

#include    "Scene.hpp"
#include    "SceneGraphNode.hpp"

#include    <assimp/scene.h>

namespace   WorldParticles
{
    namespace   Engine
    {
        class       SceneGraph
        {
            public:
                ///
                /// \brief Default constructor for the scene graph.
                ///
                /// This constructor will generate a empty scene graph.
                ///
                SceneGraph(Scene *parent);

                ///
                /// \brief Constructor from an assimp scene graph.
                ///
                SceneGraph(const aiNode *assimp, Scene *parent);

                ///
                /// \brief Destructor
                ///
                ~SceneGraph(void);

            public:
                ///
                /// \brief This method is used to recursively update the node in the scene graph.
                ///
                void    update(void);

            public:

                Mesh        *getMesh(unsigned int id);

                Material    *getMaterial(unsigned int id);

            private:
                ///
                /// \brief The Scene represented by the scene graph.
                ///
                Scene                   *parent; // TODO GSL NOT NULL

                ///
                /// \brief The root node of the graph.
                ///
                SceneGraphNode          *rootNode; // TODO GSL OWNER

        };
    }
}

#endif /* !__SCENE_GRAPH_HPP__ */
