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

        BufferObject::~BufferObject(void)
        {
            GLWindow::m_funcs->glDeleteBuffers(1, &this->id);
        }



        void
        BufferObject::bind(void)
        {
            if (this->id == 0) throw std::runtime_error("The BufferObject id should not be equal to 0 here.");
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


        ///
        /// PUBLIC SETTER
        ///

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

        ///
        /// PUBLIC GETTER
        ///

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
