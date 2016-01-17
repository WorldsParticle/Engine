///
/// \file BufferObject.cpp
///
/// \author Martin-Pierrat Louis (mart_p)
///
/// \date Sun, 17 Jan 2016 07:33:08
///
/// \version 1.0.16
///

#include    <GL/glew.h>
#include    <log4cpp/Category.hh>

#include    "Engine/Core/BufferObject.hpp"

using namespace log4cpp;

namespace   Engine
{

    BufferObject::BufferObject(const Type &type, const Usage &usage) :
        type(type),
        usage(usage),
        size(0)
    {
        glGenBuffers(1, &this->id);
    }

    BufferObject::BufferObject(BufferObject &&other) noexcept :
        id(std::move(other.id)),
        type(std::move(other.type)),
        usage(std::move(other.usage)),
        size(std::move(other.size))
    {
        other.id = 0;
    }

    BufferObject::~BufferObject(void)
    {
        glDeleteBuffers(1, &this->id);
    }



    BufferObject &
    BufferObject::operator=(BufferObject &&other) noexcept
    {
         this->id = std::move(other.id);
         other.id = 0;
         this->type = std::move(other.type);
         this->usage = std::move(other.usage);
         this->size = std::move(other.size);
         return *this;
    }

    void
    BufferObject::bind(void)
    {
        glBindBuffer(this->convert(this->type), this->id);
    }

    void
    BufferObject::unbind(void)
    {
        glBindBuffer(this->convert(this->type), 0);
    }

    void
    BufferObject::update(void *data, unsigned int length)
    {
        if (length > this->size)
        {
            this->bind();
            glBufferData(this->convert(this->type), length, data, this->convert(this->usage));
            this->size = length;
            this->unbind();
        }
        else
        {
            this->bind();
            glBufferSubData(this->convert(this->type), 0, length, data);
            this->unbind();
        }
    }



    void
    BufferObject::setType(const Type &type)
    {
        this->type = type;
    }

    void
    BufferObject::setUsage(const Usage &usage)
    {
        this->usage = usage;
    }



    const BufferObject::Type &
    BufferObject::getType(void) const
    {
        return this->type;
    }

    const BufferObject::Usage &
    BufferObject::getUsage(void) const
    {
         return this->usage;
    }



    ///
    /// TODO temporary method
    unsigned int
    BufferObject::convert(const Type &type) const
    {
        switch (type)
        {
            case Type::ARRAY_BUFFER:
                return GL_ARRAY_BUFFER;
            case Type::ELEMENT_ARRAY_BUFFER:
                return GL_ELEMENT_ARRAY_BUFFER;
        }
        return 0;
    }

    unsigned int
    BufferObject::convert(const Usage &usage) const
    {
        switch (usage)
        {
            case Usage::STATIC_DRAW:
                return GL_STATIC_DRAW;
            case Usage::DYNAMIC_DRAW:
                return GL_DYNAMIC_DRAW;
            case Usage::STREAM_DRAW:
                return GL_STREAM_DRAW;
        }
        return 0;
    }
}
