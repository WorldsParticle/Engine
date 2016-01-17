///
/// \file ArrayObject.cpp
///
/// \author Martin-Pierrat Louis (mart_p)
///
/// \date Sat, 16 Jan 2016 17:50:23
///
/// \version 1.0.7
///

#include    <GL/glew.h>
#include    <utility>

#include    "ArrayObject.hpp"

namespace   WorldParticles
{
    namespace   Engine
    {

        ArrayObject::ArrayObject(void)
        {
            glGenVertexArrays(1, &this->id);
        }

        ArrayObject::ArrayObject(ArrayObject &&other) noexcept :
            id(std::move(other.id))
        {
            other.id = 0;
        }

        ArrayObject::~ArrayObject(void)
        {
            glDeleteVertexArrays(1, &this->id);
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
            glBindVertexArray(this->id);
        }

        void
        ArrayObject::unbind(void) const
        {
            glBindVertexArray(0);
        }

    }
}
