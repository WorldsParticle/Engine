//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 3 of the License, or
// any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this program; If not, see <http://www.gnu.org/licenses/>.
//
// Copyright (C) 2016 Martin-Pierrat Louis (louismartinpierrat@gmail.com)
//

#include    <GL/glew.h>
#include    <log4cpp/Category.hh>

#include    "Engine/Core/BufferObject.hpp"

using namespace log4cpp;

namespace   Engine
{

    BufferObject::BufferObject(const Type &type, const Usage &usage) :
        m_id(0),
        m_type(type),
        m_usage(usage),
        m_size(0)
    {
        glGenBuffers(1, &this->m_id);
    }

    BufferObject::BufferObject(BufferObject &&other) noexcept :
        m_id(std::move(other.m_id)),
        m_type(std::move(other.m_type)),
        m_usage(std::move(other.m_usage)),
        m_size(std::move(other.m_size))
    {
        other.m_id = 0;
    }

    BufferObject::~BufferObject(void)
    {
        glDeleteBuffers(1, &this->m_id);
    }



    BufferObject &
    BufferObject::operator=(BufferObject &&other) noexcept
    {
         this->m_id = std::move(other.m_id);
         other.m_id = 0;
         this->m_type = std::move(other.m_type);
         this->m_usage = std::move(other.m_usage);
         this->m_size = std::move(other.m_size);
         return *this;
    }

    void
    BufferObject::bind(void)
    {
        glBindBuffer(this->convert(this->m_type), this->m_id);
    }

    void
    BufferObject::unbind(void)
    {
        glBindBuffer(this->convert(this->m_type), 0);
    }

    void
    BufferObject::update(void *data, std::size_t length)
    {
        if (length > this->m_size)
        {
            this->bind();
            glBufferData(this->convert(this->m_type), length, data, this->convert(this->m_usage));
            this->m_size = length;
            this->unbind();
        }
        else
        {
            this->bind();
            glBufferSubData(this->convert(this->m_type), 0, length, data);
            this->unbind();
        }
    }



    void
    BufferObject::setType(const Type &type)
    {
        this->m_type = type;
    }

    void
    BufferObject::setUsage(const Usage &usage)
    {
        this->m_usage = usage;
    }



    const BufferObject::Type &
    BufferObject::getType(void) const
    {
        return this->m_type;
    }

    const BufferObject::Usage &
    BufferObject::getUsage(void) const
    {
         return this->m_usage;
    }



//#warning temporary method
    unsigned int
    BufferObject::convert(const Type &type) const
    {
        switch (type)
        {
            case Type::ARRAY_BUFFER:
                return GL_ARRAY_BUFFER;
            case Type::ELEMENT_ARRAY_BUFFER:
                return GL_ELEMENT_ARRAY_BUFFER;
            default:
                throw std::runtime_error("type value unrecognized.");
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
            default:
                throw std::runtime_error("Usage value unrecognized.");
        }
        return 0;
    }
}
