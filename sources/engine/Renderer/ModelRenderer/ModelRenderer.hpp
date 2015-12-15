
#ifndef         __MODEL_RENDERER_HPP__
# define        __MODEL_RENDERER_HPP__

#include    "IRenderer.hpp"

namespace   WorldParticles
{
    namespace   Engine
    {
        class   ModelRenderer : public IRenderer
        {
            public:
                ///
                /// \brief Default constructor.
                ///
                ModelRenderer(void);

                ///
                /// \brief Destructor.
                ///
                ~ModelRenderer(void);

            public:
                ///
                /// \brief TODO description
                ///
                void    draw(const GameObject *gameobject,
                        const glm::mat4 &projection,
                        const glm::mat4 &view,
                        const glm::mat4 &model);
        }
    }
}

#endif /* !__MODEL_RENDERER_HPP__ */
