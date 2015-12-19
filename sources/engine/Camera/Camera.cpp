#include    "Camera.hpp"

#include    <glm/gtc/matrix_transform.hpp>

/// TODO C'est totalement pas cohérent de devoir inclure le GLWindow pour faire
/// de l'opengl.
#include    "glwindow.h"

namespace WorldParticles
{
    namespace Engine
    {

        Camera::Camera(const glm::vec3 &position,
                const glm::vec3 &rotation,
                const glm::vec3 &scale) :
            transform(position, rotation, scale),
            fieldOfView(60),
            zNear(0.1),
            zFar(1000.0)
        {
            projection = glm::perspective(glm::radians(45.0f), 1024.0f / 768.0f, 0.1f, 1000.0f);
            view = glm::lookAt(this->transform.getPosition(), glm::vec3(0.0), glm::vec3(0.0, 1.0, 0.0));
        }

        Camera::~Camera(void)
        {

        }

        const glm::mat4 &
        Camera::getProjection(void) const
        {
            return projection;
        }

        const glm::mat4 &
        Camera::getView(void) const
        {
            return view;
        }


        bool    Camera::initialise(void)
        {
            // nothing to do ?
            return true;
        }

        void    Camera::update(void)
        {
        }

        void    Camera::draw(void)
        {
            GLWindow::m_funcs->glClearColor(0.3, 0.1, 0.1, 0.0);
            GLWindow::m_funcs->glViewport(0, 0, 1024, 768);
            GLWindow::m_funcs->glClear(GL_COLOR_BUFFER_BIT);
        }

    }
}
