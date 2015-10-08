#include "myglpainter.h"
#include "qopenglcontext.h"
#include "qdebug.h"

MyGLPainter::MyGLPainter()
{
}

void    MyGLPainter::draw()
{
    glClearColor(0.0, 0.0, 1, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
}
