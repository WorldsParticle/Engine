#include    "BufferObject.hpp"
#include    "glwindow.h"

#include    <log4cpp/Category.hh>
using namespace log4cpp;

namespace   WorldParticles
{
    namespace   Engine
    {

        BufferObject::BufferObject(const Type &type, const Usage &usage) :
            type(type),
            usage(usage),
            size(0)
        {
            GLWindow::m_funcs->glGenBuffers(1, &this->id);
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
            GLWindow::m_funcs->glDeleteBuffers(1, &this->id);
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
            GLWindow::m_funcs->glBindBuffer(this->convert(this->type), this->id);
        }

        void
        BufferObject::unbind(void)
        {
            GLWindow::m_funcs->glBindBuffer(this->convert(this->type), 0);
        }

        void
        BufferObject::update(void *data, unsigned int length)
        {
            if (length > this->size)
            {
                this->bind();
                GLWindow::m_funcs->glBufferData(this->convert(this->type), length, data, this->convert(this->usage));
                this->size = length;
                this->unbind();
            }
            else
            {
                this->bind();
                GLWindow::m_funcs->glBufferSubData(this->convert(this->type), 0, length, data);
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
}
