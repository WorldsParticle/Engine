#ifndef __CUBE_HPP__
# define    __CUBE_HPP__

#include    "GameObject.hpp"

class   Cube : public GameObject
{
public:
    Cube(const glm::vec3 &position = glm::vec3(0.0),
         const glm::vec3 &rotation = glm::vec3(0.0),
         const glm::vec3 &scale = glm::vec3(1.0));

public:
    void    Draw(const glm::mat4 &projection, const glm::mat4 &view);
    void    Update(void);

private:
    Renderer    *renderer;
};

#endif /* !__CUBE_HPP__ */
