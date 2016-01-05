#include    "ArrayObject.hpp"

/// TODO change for a real opengl context.
#include    "glwindow.hpp"

namespace   WorldParticles
{
    namespace   Engine
    {

        ArrayObject::ArrayObject(void)
        {
            GLWindow::m_funcs->glGenVertexArrays(1, &this->id);
        }

        ArrayObject::ArrayObject(ArrayObject &&other) noexcept :
            id(std::move(other.id))
        {
            other.id = 0;
        }

        ArrayObject::~ArrayObject(void)
        {
            GLWindow::m_funcs->glDeleteVertexArrays(1, &this->id);
        }



        ArrayObject &
        ArrayObject::operator=(ArrayObject &&other) noexcept
        {
            this->id = std::move(id);
            other.id = 0;
            return *this;
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
