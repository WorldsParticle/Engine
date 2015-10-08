#include "glwindow.h"
#include "qdebug.h"
#include <QPushButton>
#include <QGridLayout>
#include <QCoreApplication>
#include "engine/gameclock.h"

GLWindow::GLWindow(QWindow *parent) :
    QWindow(parent),
    _context(this),
    _format(),
    _gameEngine()
{   
    setSurfaceType(OpenGLSurface);

    _format.setMajorVersion(4);
    _format.setMinorVersion(2);
    _format.setProfile(QSurfaceFormat::CoreProfile); //whatever this is

    this->setFormat(_format);
    _context.setFormat(_format);

    create();
    _context.create();

    resize(720, 540);

    if(!_context.isValid())
        qCritical()<<"The OpenGL context is invalid!"; //I allways get this message

    //now another test:
    //the next line prints: "Window format version is: 4.2" which is correct
    qDebug()<<"Window format version is: "<<this->format().majorVersion()<<"."<<this->format().minorVersion();
    //the next line prints: "Context format version is: 2.0" Which is ofcourse not correct! WTF?
    qDebug()<<"Context format version is: "<<_context.format().majorVersion()<<"."<<_context.format().minorVersion();

}


GLWindow::~GLWindow()
{

}

void    GLWindow::start(Model *model)
{
    GameClock::start();

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
    /*e->accept();
    if (e->key() == Qt::Key_A)
        ;*/
}
