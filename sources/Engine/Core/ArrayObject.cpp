///
/// \file ArrayObject.cpp
///
/// \author Martin-Pierrat Louis (mart_p)
///
/// \date Sun, 17 Jan 2016 07:32:40
///
/// \version 1.0.11
///

#include    <GL/glew.h>
#include    <utility>

#include    "Engine/Core/ArrayObject.hpp"

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
