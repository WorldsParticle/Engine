#ifndef GLWINDOW_H
#define GLWINDOW_H

#include <QWindow>
#include <QOpenGLFunctions>
#include <QOpenGLContext>
#include <QKeyEvent>
#include "graphic/myglpainter.h"
#include "model/model.h"
#include <QTime>

class GLWindow : public QWindow//, protected QOpenGLFunctions
{
    Q_OBJECT
    public:
        explicit GLWindow(QWindow *parent = 0);
        ~GLWindow();

    void    start(Model *model);

protected:
    virtual void    keyPressEvent(QKeyEvent *e);

private:
        QOpenGLContext _context;
        QSurfaceFormat _format;
};

#endif // GLWINDOW_H
