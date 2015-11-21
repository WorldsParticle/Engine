#include    "Camera.hpp"
#include    "qopenglcontext.h"

#include    <glm/gtc/matrix_transform.hpp>

Camera::Camera(const glm::vec3 &position, const glm::vec3 &rotation, const glm::vec3 &scale) :
    transform(position, rotation, scale),
    fieldOfView(60),
    ratio(1024.0 / 768.0),
    zNear(0.1),
    zFar(1000.0)
{
}

Camera::~Camera(void)
{
}

glm::mat4 Camera::GetProjection(void) const
{
    glm::mat4   projection = glm::perspective(glm::radians(45.0f), this->ratio, 0.1f, 100.0f);
    return projection;
}

glm::mat4 Camera::GetView(void) const
{
    glm::mat4   view = glm::lookAt(this->transform.GetPosition(), glm::vec3(0.0), glm::vec3(0.0, 1.0, 0.0));
    return view;
}

void    Camera::Update(void)
{

}

void    Camera::Draw(void)
{
//    glClearColor(0.3, 0.1, 0.1, 0.0);
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
