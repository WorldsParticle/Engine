#ifndef     __RENDER_GRAPH_HPP__
# define    __RENDER_GRAPH_HPP__

namespace   WorldParticles
{
    namespace   Engine
    {
        class   Scene;

        ///
        /// \brief The render graph is used to render efficiently 3D data.
        ///
        class       RenderGraph
        {
            public:
                ///
                /// \brief Default Constructor.
                ///
                RenderGraph(Scene *scene);

                ///
                /// \brief Copy constructor.
                ///
                RenderGraph(const RenderGraph &other);

                ///
                /// \brief Move constructor.
                ///
                RenderGraph(RenderGraph &&other) noexcept;

                ///
                /// \brief Destructor.
                ///
                ~RenderGraph(void) noexcept;

            public:
                ///
                /// \brief Copy assignment operator.
                ///
                RenderGraph     &operator=(const RenderGraph &other);

                ///
                /// \brief Move assignment operator.
                ///
                RenderGraph     &operator=(RenderGraph &&other) noexcept;

            public:
                ///
                /// \brief This method launch the rendering process.
                ///
                void            render(void);

            private:
                ///
                /// \brief The scene in which the RenderGraph act.
                ///
                Scene           *scene;
        };
    }
}

#endif /* !__RENDER_GRAPH_HPP__ */
