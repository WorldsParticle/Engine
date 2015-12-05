#ifndef     __SKYBOX_RENDERER_HPP__
# define    __SKYBOX_RENDERER_HPP__

#include    <vector>
#include    "glwindow.h"
#include    "Renderer.hpp"

namespace   WorldParticles {
    namespace   Engine {
        ///
        /// \brief This renderer is used to draw a mesh with a material.
        ///
        class   SkyboxRenderer : public Renderer
        {
            public:
                SkyboxRenderer(void);
                ~SkyboxRenderer(void);
		GLuint	LoadCubemap(std::vector<const GLchar*>);

            public:
                void    Draw(const Mesh &mesh,
                        Material &material,
                        const glm::mat4 &projection,
                        const glm::mat4 &view,
                        const glm::mat4 &model);
	    private:
		GLuint _cubemapTexture;
        };
    }
}

#endif /* !__SKYBOX_RENDERER_HPP__ */
