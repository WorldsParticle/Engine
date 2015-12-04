#include    "Shader.hpp"
#include    "glwindow.h"

//#if     __DEBUG__
# include   <log4cpp/Category.hh>
//#endif [> !__DEBUG__ <]

namespace   WorldParticles
{
    namespace Engine
    {
        Shader::Shader(const Shader::Type &shaderType, const std::string &shaderData) :
            _shaderId(CreateShaderFromType(shaderType)),
            _isCompiled(false),
            _shaderType(shaderType)
        {
            const char *c_str = shaderData.c_str();
            GLWindow::m_funcs->glShaderSource(this->_shaderId, 1, &c_str, 0);
        }

        Shader::~Shader(void)
        {
            GLWindow::m_funcs->glDeleteShader(this->_shaderId);
        }



        bool Shader::Compile(void)
        {
            int     result;
            GLWindow::m_funcs->glCompileShader(this->_shaderId);
            GLWindow::m_funcs->glGetShaderiv(this->_shaderId, GL_COMPILE_STATUS, &result);
            this->_isCompiled = result == GL_TRUE;

//#if     __DEBUG__

            if (this->_isCompiled == false)
            {
                GLWindow::m_funcs->glGetShaderiv(this->_shaderId, GL_INFO_LOG_LENGTH, &result);
                if (result > 1)
                {
                    char *info = new char[result + 1];
                    GLWindow::m_funcs->glGetShaderInfoLog(this->_shaderId, result, 0, info);
                    log4cpp::Category &root = log4cpp::Category::getRoot();
                    root << log4cpp::Priority::ERROR << info;
                    delete info;
                }
            }

//#endif
            return this->_isCompiled;
        }



        /// TODO : should be unit tested.
        unsigned int    Shader::CreateShaderFromType(const Shader::Type &type)
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
