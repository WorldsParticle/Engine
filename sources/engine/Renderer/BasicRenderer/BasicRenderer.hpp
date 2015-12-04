#ifndef     __BASIC_RENDERER_HPP__
# define    __BASIC_RENDERER_HPP__

#include    "Renderer.hpp"

namespace   WorldParticles
{
    namespace   Engine
    {
        ///
        /// \brief This renderer is used to draw a mesh with a material.
        ///
        class   BasicRenderer : public Renderer
        {
            public:
                BasicRenderer(void);
                ~BasicRenderer(void);

            public:
                void    Draw(const std::shared_ptr<Mesh> &mesh,
                        const Material &material,
                        const glm::mat4 &projection,
                        const glm::mat4 &view,
                        const glm::mat4 &model);
        };
    }
}

#endif /* !__BASIC_RENDERER_HPP__ */
