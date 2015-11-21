#ifndef     __CUBE_RENDERER_HPP__
# define    __CUBE_RENDERER_HPP__

#include    "Renderer.hpp"

class   CubeRenderer : public Renderer
{
public:
    CubeRenderer(void);
    ~CubeRenderer(void) {}

public:
    void    Draw(const Mesh &mesh,
                 Material &material,
                 const glm::mat4 &projection,
                 const glm::mat4 &view,
                 const glm::mat4 &model);
};

#endif /* !__CUBE_RENDERER_HPP__ */
