#include    "BufferObject.hpp"
#include    "glwindow.h"

namespace   WorldParticles
{
    namespace   Engine
    {

        BufferObject::BufferObject(void) :
            dynamic(GL_STATIC_DRAW)
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
            if (this->type == Type::UNDEFINED) throw std::logic_error("the BufferObject type cannot be UNDEFINED at this state.");
            if (this->id == 0) throw std::runtime_error("The BufferObject id should not be equal to 0 here.");
            GLWindow::m_funcs->glBindBuffer(this->type, this->id);
        }

        void
        BufferObject::unbind(void)
        {
            if (this->type == Type::UNDEFINED) throw std::logic_error("the BufferObject type cannot be UNDEFINED at this state.");
            GLWindow::m_funcs->glBindBuffer(this->type, 0);
        }



        void
        BufferObject::setType(const Type &newType)
        {
            switch (newType)
            {
                case Type::ELEMENT_ARRAY:
                    this->type = GL_ELEMENT_ARRAY_BUFFER; break;
                case Type::ARRAY:
                    this->type = GL_ARRAY_BUFFER; break;
                default:
                    this->type = Type::UNDEFINED;
            }
        }

        void
        BufferObject::setData(const std::vector<glm::vec4> &vertices)
        {
            if (this->type == Type::UNDEFINED) throw std::logic_error("the BufferObject type cannot be UNDEFINED at this state.");
            GLWindow::m_funcs->glBufferData(this->type, vertices.size(),
                    vertices.data(), this->dynamic);
        }

        void
        BufferObject::setData(const std::vector<glm::vec3> &vertices)
        {
            if (this->type == Type::UNDEFINED) throw std::logic_error("the BufferObject type cannot be UNDEFINED at this state.");
            GLWindow::m_funcs->glBufferData(this->type, vertices.size(),
                    vertices.data(), this->dynamic);
        }

        void
        BufferObject::setData(const std::vector<glm::vec2> &vertices)
        {
            if (this->type == Type::UNDEFINED) throw std::logic_error("the BufferObject type cannot be UNDEFINED at this state.");
            GLWindow::m_funcs->glBufferData(this->type, vertices.size(),
                    vertices.data(), this->dynamic);
        }

        void
        BufferObject::setData(const std::vector<float> &vertices)
        {
            if (this->type == Type::UNDEFINED) throw std::logic_error("the BufferObject type cannot be UNDEFINED at this state.");
            GLWindow::m_funcs->glBufferData(this->type, vertices.size(),
                    vertices.data(), this->dynamic);
        }



        BufferObject::Type
        BufferObject::getType(void) const
        {
            switch (this->type)
            {
                case GL_ELEMENT_ARRAY_BUFFER:
                    return Type::ELEMENT_ARRAY;
                case GL_ARRAY_BUFFER:
                    return Type::ARRAY;
                default:
                    return Type::UNDEFINED;
            }
        }
    }
}
