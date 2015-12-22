#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include <QTimer>
#include "model/tools.h"

class GLWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit GLWidget(QWidget *parent = 0);

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);

    void draw();
    //void drawFire(); // temporary, for demo

signals:

public slots:
    void updateAnimation();

private:
    QTimer  _timer;
    Vec3D   _point;

    float _elapsedTime; // have to merge _timer and this (QElapsedTimer)
};

#endif // GLWIDGET_H
