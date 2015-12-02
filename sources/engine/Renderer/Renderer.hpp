#ifndef     __RENDERER_HPP__
# define    __RENDERER_HPP__

#include    "worldparticles.hpp"

#include    <glm/glm.hpp>

#include    "Material.hpp"
#include    "Mesh.hpp"

namespace WorldParticles
{
    namespace Engine
    {
        ///
        /// \brief This class is used to store the whole rendering part into a class. This class should be inherited.
        ///
        class       Renderer
        {
            public:
                ///
                /// \brief Default constructor
                ///
                Renderer(void);

                ///
                /// \brief Destructor
                ///
                virtual ~Renderer(void);

            public:
                ///
                /// \brief This method is used to draw a mesh with a particular Material and with a specific MVP matrix.
                /// \param material, the material used to draw the mesh.
                /// \param projection, the projection matrix used to draw the mesh.
                /// \param view, the view matrix used to draw the mesh.
                /// \param model, the view model used to draw the mesh.
                ///
                virtual void    Draw(const Mesh &mesh,
                        Material &material,
                        const glm::mat4 &projection,
                        const glm::mat4 &view,
                        const glm::mat4 &model) = 0;
        };
    }
}

#endif /* !__RENDERER_HPP__ */
