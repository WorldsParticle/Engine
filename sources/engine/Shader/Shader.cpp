#include    "Shader.hpp"
#include    "glwindow.h"
#include    <log4cpp/Category.hh>

namespace   WorldParticles
{
    namespace Engine
    {

        Shader::Shader(const Shader::Type &type, const std::string &shaderData) :
            id(createShaderFromType(type)),
            compiled(false),
            type(type)
        {
            const char *c_str = shaderData.c_str();
            GLWindow::m_funcs->glShaderSource(this->id, 1, &c_str, 0);
        }

        Shader::Shader(Shader &&other) noexcept :
            id(std::move(other.id)),
            compiled(std::move(other.compiled)),
            type(std::move(other.type))
        {
            other.id = 0;
        }

        Shader::~Shader(void)
        {
            GLWindow::m_funcs->glDeleteShader(this->id);
        }



        Shader &
        Shader::operator=(Shader &&other) noexcept
        {
            this->id = std::move(other.id);
            other.id = 0;
            this->compiled = std::move(other.compiled);
            this->type = std::move(other.type);
            return *this;
        }



        bool Shader::compile(void)
        {
            int     result;
            GLWindow::m_funcs->glCompileShader(this->id);
            GLWindow::m_funcs->glGetShaderiv(this->id, GL_COMPILE_STATUS, &result);
            this->compiled = result == GL_TRUE;
            if (this->compiled == false)
            {
                GLWindow::m_funcs->glGetShaderiv(this->id, GL_INFO_LOG_LENGTH, &result);
                if (result > 1)
                {
                    char *info = new char[result + 1];
                    GLWindow::m_funcs->glGetShaderInfoLog(this->id, result, 0, info);
                    log4cpp::Category &root = log4cpp::Category::getRoot();
                    root << log4cpp::Priority::ERROR << info;
                    delete info;
                }
            }
            return this->compiled;
        }



        const Shader::Type &
        Shader::getType(void) const
        {
             return this->type;
        }

        unsigned int
        Shader::getId(void) const
        {
            return this->id;
        }

        bool
        Shader::isCompiled(void) const
        {
             return this->compiled;
        }



        /// TODO : should be unit tested.
        unsigned int    Shader::createShaderFromType(const Shader::Type &type)
        {
            switch (type)
            {
                case Shader::Type::VERTEX_SHADER:
                    return GLWindow::m_funcs->glCreateShader(GL_VERTEX_SHADER);
                case Shader::Type::TESSELATION_CONTROL_SHADER:
                    return GLWindow::m_funcs->glCreateShader(GL_TESS_CONTROL_SHADER);
                case Shader::Type::EVALUATION_SHADER:
                    return GLWindow::m_funcs->glCreateShader(GL_TESS_EVALUATION_SHADER);
                case Shader::Type::GEOMETRY_SHADER:
                    return GLWindow::m_funcs->glCreateShader(GL_GEOMETRY_SHADER);
                case Shader::Type::FRAGMENT_SHADER:
                    return GLWindow::m_funcs->glCreateShader(GL_FRAGMENT_SHADER);
                case Shader::Type::COMPUTE_SHADER:
                    return GLWindow::m_funcs->glCreateShader(GL_COMPUTE_SHADER);
                default:
                    return 0;
            }
        }

    }
}
