#ifndef     __CAMERA_HPP__
# define    __CAMERA_HPP__

#include    <glm/glm.hpp>
#include    "Transform.hpp"
#include     "GameObject.hpp"

class   Camera
{
public:
    Camera(const glm::vec3 &position = glm::vec3(0.0),
           const glm::vec3 &rotation = glm::vec3(0.0),
           const glm::vec3 &scale = glm::vec3(1.0));
    ~Camera(void);

public:
    glm::mat4   GetProjection(void) const;
    glm::mat4   GetView(void) const;
    void    changeRatio(float ratio);

public:
    void    Update();
    void    Draw();

private:
    Transform   transform;
    float       fieldOfView;
    float       ratio;
    float       zNear;
    float       zFar;

};

#endif /* !__CAMERA_HPP__ */
