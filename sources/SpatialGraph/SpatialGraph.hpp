///
/// \file SpatialGraph.hpp
///
/// \author Martin-Pierrat Louis (mart_p)
///
/// \date Fri, 15 Jan 2016 13:34:52
///
/// \version 1.0.1
///

#ifndef     __SPATIAL_GRAPH_HPP__
# define    __SPATIAL_GRAPH_HPP__

#include    <list>

namespace   WorldParticles
{
    namespace   Engine
    {
        class   Renderer;
        class   Scene;
        class   Camera;
        class   Object;
        class   Light;

        ///
        /// \brief This class will be used to implement an occlusion culling algorithm.
        ///
        /// Actually, this class doesn't implement any occlusion culling, everything is rendered.
        ///
        class       SpatialGraph
        {
            public:
                ///
                /// \brief Default constructor.
                ///
                SpatialGraph(Renderer *renderer, Scene *scene);

                ///
                /// \brief Copy constructor.
                ///
                SpatialGraph(const SpatialGraph &other) = default;

                ///
                /// \brief Move constructor.
                ///
                SpatialGraph(SpatialGraph &&other) noexcept = default;

                ///
                /// \brief Destructor.
                ///
                ~SpatialGraph(void) noexcept;

            public:
                ///
                /// \brief Copy assignment operator.
                ///
                SpatialGraph    &operator=(const SpatialGraph &other) = default;

                ///
                /// \brief Move assignment operator.
                ///
                SpatialGraph    &operator=(SpatialGraph &&other) noexcept = default;

            public:
                ///
                /// \brief This method is used to do the culling process and
                /// prepare the renderer for rendering process.
                ///
                void    cull(void);

            public:
                ///
                /// \brief This method add the object in the spatial graph,
                /// it's used to reduce the rendering time.
                ///
                void    add(Object *object);

                ///
                /// \brief This method add the light in the spatial graph,
                /// it's used to reduce the rendering time.
                ///
                void    add(Light *light);

                ///
                /// \brief This method add the camera in the spatial graph,
                /// it's used to reduce the rendering time.
                ///
                void    add(Camera *camera);

            protected:
                ///
                /// \brief The scene which the spatial graph act.
                ///
                Scene                   *scene;

                ///
                /// \brief The renderer used to display non hidden objects.
                ///
                Renderer                *renderer;

            protected:
                ///
                /// \brief The cameras present in the scene.
                ///
                std::list<Camera *>     cameras;

                ///
                /// \brief The objects present in the scene.
                ///
                std::list<Object *>     objects;

                ///
                /// \brief The lights existing in the scene.
                ///
                std::list<Light *>      lights;
        };
    }
}

#endif /* !__SPATIAL_GRAPH_HPP__ */
