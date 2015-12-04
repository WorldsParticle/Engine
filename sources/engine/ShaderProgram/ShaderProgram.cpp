#include    <glm/gtc/type_ptr.hpp>

#include    "ShaderProgram.hpp"
#include    "glwindow.h"

//#if     __DEBUG__
# include   <log4cpp/Category.hh>
//#endif [> !__DEBUG__<]

namespace   WorldParticles
{
    namespace   Engine
    {

        ShaderProgram::ShaderProgram(void) :
            _programId(GLWindow::m_funcs->glCreateProgram()),
            _isLinked(false)
        {
        }

        ShaderProgram::~ShaderProgram(void)
        {
        }



        ShaderProgram &ShaderProgram::operator<<(const std::shared_ptr<Shader> &shader)
        {
            this->AddShader(shader);
            return *this;
        }



        void ShaderProgram::AddShader(const std::shared_ptr<Shader> &shader)
        {
            GLWindow::m_funcs->glAttachShader(this->_programId, shader->GetShaderId());
        }

        bool ShaderProgram::Link(void)
        {
            int     result;

            GLWindow::m_funcs->glLinkProgram(this->_programId);
            GLWindow::m_funcs->glGetProgramiv(this->_programId, GL_LINK_STATUS, &result);
            this->_isLinked = result == GL_TRUE;

//#if     __DEBUG__

            if (this->_isLinked == false)
            {
                GLWindow::m_funcs->glGetProgramiv(this->_programId, GL_INFO_LOG_LENGTH, &result);
                if (result > 1)
                {
                    char *info = new char[result + 1];
                    GLWindow::m_funcs->glGetProgramInfoLog(this->_programId, result, 0, info);
                    log4cpp::Category &root = log4cpp::Category::getRoot();
                    root << log4cpp::Priority::ERROR << info;
                    delete info;
                }
            }

//#endif [> !__DEBUG__ <]

            return this->_isLinked;
        }

        void    ShaderProgram::Bind(void) const
        {
            GLWindow::m_funcs->glUseProgram(this->_programId);
        }

        void    ShaderProgram::Unbind(void) const
        {
            GLWindow::m_funcs->glUseProgram(0);
        }



        void    ShaderProgram::SetUniform(const std::string &name, const glm::mat4 &matrix) const
        {
            int matrixUniformLocation = GLWindow::m_funcs->glGetUniformLocation(this->_programId, name.c_str());
            GLWindow::m_funcs->glUniformMatrix4fv(matrixUniformLocation, 1, GL_FALSE, glm::value_ptr(matrix));
        }

    }
}
