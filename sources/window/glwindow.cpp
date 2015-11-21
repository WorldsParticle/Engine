#include "glwindow.h"
#include "qdebug.h"
#include <QPushButton>
#include <QGridLayout>
#include <QCoreApplication>
#include "GameClock.hpp"
#include "GameEngine.hpp"

QSurface        *GLWindow::surface = NULL;
QOpenGLContext      *GLWindow::context = NULL;
QOpenGLFunctions_4_2_Core *GLWindow::m_funcs = NULL;

GLWindow::GLWindow(QWindow *parent) :
    QWindow(parent),
    _context(this),
    _format()
{
    setSurfaceType(OpenGLSurface);

    _format.setMajorVersion(4);
    _format.setMinorVersion(2);
    _format.setProfile(QSurfaceFormat::CoreProfile); //whatever this is

    this->setFormat(_format);
    _context.setFormat(_format);

    create();
    _context.create();

    GLWindow::context = &_context;
    GLWindow::surface = this;

    resize(1024, 768);

    if(!_context.isValid())
        qCritical()<<"The OpenGL context is invalid!"; //I allways get this message

    _context.makeCurrent(this);
    m_funcs = (QOpenGLFunctions_4_2_Core *)_context.versionFunctions();

    m_funcs->initializeOpenGLFunctions();

    //now another test:
    //the next line prints: "Window format version is: 4.2" which is correct
    qDebug()<<"Window format version is: "<<this->format().majorVersion()<<"."<<this->format().minorVersion();
    //the next line prints: "Context format version is: 2.0" Which is ofcourse not correct! WTF?
    qDebug()<<"Context format version is: "<<_context.format().majorVersion()<<"."<<_context.format().minorVersion();

    GLuint VertexArrayID;
    m_funcs->glGenVertexArrays(1, &VertexArrayID);
    m_funcs->glBindVertexArray(VertexArrayID);

}


GLWindow::~GLWindow()
{

}

void    GLWindow::start(Model *model)
{
    GameClock::start();
    GameEngine     _gameEngine;

    _gEngine = &(_gameEngine);
    while (isVisible())
    {
        _gameEngine.update();
        GameClock::restart(); //timeElapsed renverra le temps depuis le dernier start / restart
                              //si on commente cette ligne, ce sera le temps depuis le start

        _context.makeCurrent(this);
        _gameEngine.draw();
        _context.swapBuffers(this);

        QCoreApplication::processEvents();
    }
}

void    GLWindow::keyPressEvent(QKeyEvent *e)
{
    e->accept();
    if (e->key() == Qt::Key_Escape)
        exit(1);
    else if (e->key() == Qt::Key_A)
    {
        showMaximized();
        resizeWindow();
    }
    else if (e->key() == Qt::Key_Z)
    {
        showNormal();
        resizeWindow();
    }
}

void GLWindow::resizeEvent(QResizeEvent* event)
{

   // GLWindow::resizeEvent(event);
    resizeWindow();
}

void GLWindow::resizeWindow()
{
    glViewport((width() - (height() * 1.33333f)) / 2, 0, height() * 1.33333f, height());
   _gEngine->changeRatio(height() * 1.33333f / height());
}
