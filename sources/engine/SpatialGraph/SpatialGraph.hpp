#ifndef     __SPATIAL_GRAPH_HPP__
# define    __SPATIAL_GRAPH_HPP__

namespace   WorldParticles
{
    namespace   Engine
    {
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
                SpatialGraph(Renderer &renderer);

                ///
                /// \brief Copy constructor.
                ///
                SpatialGraph(const SpatialGraph &other);

                ///
                /// \brief Move constructor.
                ///
                SpatialGraph(SpatialGraph &&other) noexcept;

                ///
                /// \brief Destructor.
                ///
                ~SpatialGraph(void) noexcept;

            public:
                ///
                /// \brief Copy assignment operator.
                ///
                SpatialGraph    &operator=(const SpatialGraph &other);

                ///
                /// \brief Move assignment operator.
                ///
                SpatialGraph    &operator=(SpatialGraph &&other) noexcept;


            public:
                ///
                /// \brief This method is used to do the culling process and
                /// prepare the renderer for rendering process.
                ///
                void    cull(void);

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
                ///
                ///
                std::list<Camera *>     cameras;

                ///
                ///
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
