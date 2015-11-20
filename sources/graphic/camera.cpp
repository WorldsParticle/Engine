#include "camera.h"

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

    QMatrix4x4 matrix;
    matrix.translate(_eye.x(), _eye.y(), _eye.z());
    // Set modelview-projection matrix
    program.setUniformValue("mvp_matrix", _projection * matrix);
