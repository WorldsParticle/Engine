///
/// \file Renderer.hpp
///
/// \author Martin-Pierrat Louis (mart_p)
///
/// \date Fri, 15 Jan 2016 13:32:32
///
/// \version 1.0.1
///

#ifndef     __RENDERER_HPP__
# define    __RENDERER_HPP__

#include    <list>

namespace   WorldParticles
{
    namespace   Engine
    {
        class   Scene;
        class   Camera;
        class   Object;
        class   Light;
        ///
        /// \brief The render graph is used to render efficiently 3D data.
        ///
        /// This class must be an interface.
        ///
        /// TODO rework.
        ///
        class       Renderer
        {
            public:
                ///
                /// \brief Default Constructor.
                ///
                Renderer(Scene *scene);

                ///
                /// \brief Copy constructor.
                ///
                Renderer(const Renderer &other);

                ///
                /// \brief Move constructor.
                ///
                Renderer(Renderer &&other) noexcept;

                ///
                /// \brief Destructor.
                ///
                ~Renderer(void) noexcept;

            public:
                ///
                /// \brief Copy assignment operator.
                ///
                Renderer     &operator=(const Renderer &other);

                ///
                /// \brief Move assignment operator.
                ///
                Renderer     &operator=(Renderer &&other) noexcept;

            public:
                ///
                /// \brief This method launch the rendering process.
                ///
                void            render(void);

            public:
                ///
                /// \brief This method is used to add an object for the next rendering.
                ///
                void            add(Object *object);

                ///
                /// \brief This method is used to add a Light for the next rendering.
                ///
                void            add(Light *light);

                ///
                /// \brief This method is used to add a camera for the next rendering.
                ///
                void            add(Camera *camera);

            private:
                ///
                /// \brief The scene in which the Renderer act.
                ///
                Scene           *scene;

                ///
                /// \brief The list of object needed to be rendered with the render method.
                ///
                /// TODO container type
                ///
                std::list<Object *>     objects;

                ///
                /// \brief The list of cameras needed to be rendered with the render method.
                ///
                /// TODO container type
                ///
                std::list<Camera *>     cameras;

                ///
                /// \brief The list of lights needed to be rendered with the light method.
                ///
                /// TODO container type
                ///
                std::list<Light *>      lights;

        };
    }
}

#endif /* !__RENDER_GRAPH_HPP__ */
