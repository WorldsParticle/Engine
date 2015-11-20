#ifndef CAMERA_H_
# define CAMERA_H_

#include <QtOpenGL>
#include <QVector3D>
#include <QMatrix4x4>
#include "qopenglcontext.h"

class Camera {
    private:
    public:
	QVector3D   eye;
	QMatrix4x4  projection;
	Camera(QVector3D eye);
	Camera();
	void resize(int w, int h);
};

#endif /* !CAMERA_H_ */
