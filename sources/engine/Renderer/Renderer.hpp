#ifndef     __RENDERER_HPP__
# define    __RENDERER_HPP__

#include    "worldparticles.hpp"

#include    <glm/glm.hpp>

#include    "Material.hpp"
#include    "Mesh.hpp"

class       Renderer
{
public:
    Renderer(void) {}
    virtual ~Renderer(void) {}

public:
    ///
    /// \brief Draw
    /// \param material
    /// \param projection
    /// \param view
    /// \param model
    ///
    virtual void    Draw(const Mesh &mesh,
                         Material &material,
                         const glm::mat4 &projection,
                         const glm::mat4 &view,
                         const glm::mat4 &model) = 0;
};

#endif /* !__RENDERER_HPP__ */
