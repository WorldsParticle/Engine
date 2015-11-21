#include "camera.h"

Camera::Camera(QVector3D const &e) : eye(e.x(),e.y(),e.z())
{
}

Camera::Camera(float x, float y, float z) : eye(x, y, z)
{
}

Camera::Camera() : eye(0,0,-5)
{
}

void Camera::resize(int w, int h)
{
    // Calculate aspect ratio
    qreal aspect = qreal(w) / qreal(h ? h : 1);

    // Set near plane to 3.0, far plane to 7.0, field of view 45 degrees
    const qreal zNear = 3.0, zFar = 7.0, fov = 45.0;

    // Reset projection
    projection.setToIdentity();

    // Set perspective projection
    projection.perspective(fov, aspect, zNear, zFar);
}
