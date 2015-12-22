#include    "ArrayObject.hpp"
#include    "glwindow.h"

namespace   WorldParticles
{
    namespace   Engine
    {

        ArrayObject::ArrayObject(void)
        {
            GLWindow::m_funcs->glGenVertexArrays(1, &this->id);
        }

        ArrayObject::~ArrayObject(void)
        {
            GLWindow::m_funcs->glDeleteVertexArrays(1, &this->id);
        }



        void
        ArrayObject::bind(void) const
        {
            GLWindow::m_funcs->glBindVertexArray(this->id);
        }

        void
        ArrayObject::unbind(void) const
        {
            GLWindow::m_funcs->glBindVertexArray(0);
        }

    }
}
