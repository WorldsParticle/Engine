#ifndef     __BASIC_RENDERER_HPP__
# define    __BASIC_RENDERER_HPP__

#include    "IRenderer.hpp"

namespace   WorldParticles
{
    namespace   Engine
    {
        ///
        /// \brief This renderer is used to draw a simple gameobject.
        ///
        class   BasicRenderer : public IRenderer
        {
            public:
                ///
                /// \brief Default constructor
                ///
                BasicRenderer(void);

                ///
                /// \brief Destructor
                ///
                ~BasicRenderer(void);

            public:
                ///
                // TODO description
                ///
                void    draw(const GameObject *gameobject,
                        const glm::mat4 &projection,
                        const glm::mat4 &view,
                        const glm::mat4 &model);
        };
    }
}

#endif /* !__BASIC_RENDERER_HPP__ */
