///
/// \file SceneGraph.hpp
///
/// \author Martin-Pierrat Louis (mart_p)
///
/// \date Sat, 16 Jan 2016 21:02:06
///
/// \version 1.0.3
///

#ifndef     __ENGINE_SCENE_GRAPH_HPP__
# define    __ENGINE_SCENE_GRAPH_HPP__

#include    <assimp/scene.h>

namespace   WorldParticles
{
    namespace   Engine
    {
        class       Scene;
        class       SceneGraphNode;
        class       AssimpScene;

        class       SceneGraph
        {
            public:
                ///
                /// \brief Default constructor for the scene graph.
                ///
                /// This constructor will generate a empty scene graph.
                ///
                SceneGraph(Scene *scene);

                ///
                /// \brief Constructor from an assimp scene graph.
                ///
                /// TODO GSL NOT NULL
                ///
                SceneGraph(const AssimpScene &assimpScene, Scene *scene);

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

            private:
                ///
                /// \brief The Scene represented by the scene graph.
                ///
                Scene                   *scene; // TODO GSL NOT NULL

                ///
                /// \brief The root node of the graph.
                ///
                SceneGraphNode          *rootNode; // TODO GSL OWNER

        };
    }
}

#endif /* !__ENGINE_SCENE_GRAPH_HPP__ */
