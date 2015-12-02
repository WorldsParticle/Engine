#ifndef     __BASIC_RENDERER_HPP__
# define    __BASIC_RENDERER_HPP__

#include    "Renderer.hpp"

class   BasicRenderer : public Renderer
{
public:
    BasicRenderer(void);
    ~BasicRenderer(void);

public:
    void    Draw(const Mesh &mesh,
                 Material &material,
                 const glm::mat4 &projection,
                 const glm::mat4 &view,
                 const glm::mat4 &model);
};

#endif /* !__BASIC_RENDERER_HPP__ */
