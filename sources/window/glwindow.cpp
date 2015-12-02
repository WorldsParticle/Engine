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

    _mouseTracking = false;

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
    ::WorldParticles::Engine::GameEngine     _gameEngine;

    _gEngine = &(_gameEngine);
    ::WorldParticles::Engine::GameClock::start();
    resizeWindow();
    while (isVisible())
    {
        _gameEngine.update();
        ::WorldParticles::Engine::GameClock::restart();
        _context.makeCurrent(this);
        _gameEngine.draw();
        _context.swapBuffers(this);

        QCoreApplication::processEvents();
    }
}

void    GLWindow::keyPressEvent(QKeyEvent *e)
{
    if (e->isAutoRepeat())
        return;
    static bool scr = false; // Miroir, miroir, qui est la plus belle des horreurs dans ce code ?
    e->accept();

    if (e->key() == Qt::Key_Escape)
        exit(1);
    else if (e->key() == Qt::Key_A) {
        if (scr == false) {
            showMaximized();
            scr = true;
        }
        else {
            showNormal();
            scr = false;
        }
        resizeWindow();
    }
    else if (e->key() == Qt::Key_Z){
    }
    else if (e->key() == Qt::Key_Q){
    }
    else if (e->key() == Qt::Key_S){
    }
    else if (e->key() == Qt::Key_D){
    }
}

void    GLWindow::keyReleaseEvent(QKeyEvent *e)
{
    if (e->isAutoRepeat())
        return;
    if (e->key() == Qt::Key_Z){
    }
    if (e->key() == Qt::Key_Q){
    }
    if (e->key() == Qt::Key_S){
    }
    if (e->key() == Qt::Key_D){
    }
}

void GLWindow::resizeEvent(QResizeEvent* event)
{

   // GLWindow::resizeEvent(event);
    resizeWindow();
}

void GLWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton){
        setCursor(Qt::BlankCursor);
        QPoint glob = mapToGlobal(QPoint(width()/2,height()/2));
        QCursor::setPos(glob);
        _mouseTracking = true;
    }
    else if (event->button() == Qt::RightButton){
    setCursor(Qt::ArrowCursor);
    _mouseTracking = false;
    }
}

void GLWindow::mouseMoveEvent(QMouseEvent *event){
    if (_mouseTracking)
    {
        QPoint glob = mapToGlobal(QPoint(width()/2,height()/2));
        QCursor::setPos(glob);
    }
}

void GLWindow::resizeWindow()
{
}
