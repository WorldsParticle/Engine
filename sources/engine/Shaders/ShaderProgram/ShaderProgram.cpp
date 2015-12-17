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

        ///
        /// PUBLIC CONSTRUCTOR
        ///

        ShaderProgram::ShaderProgram(void) :
            _programId(GLWindow::m_funcs->glCreateProgram()),
            _isLinked(false)
        {
        }

        ShaderProgram::~ShaderProgram(void)
        {
        }


        ///
        /// PUBLIC OPERATOR
        ///

        ShaderProgram &ShaderProgram::operator<<(const std::shared_ptr<Shader> &shader)
        {
            this->add(shader);
            return *this;
        }


        ///
        /// PUBLIC METHOD
        ///

        void
        ShaderProgram::add(const std::shared_ptr<Shader> &shader)
        {
            GLWindow::m_funcs->glAttachShader(this->_programId, shader->getShaderId());
        }

        bool ShaderProgram::Link(void)
        {
            int     result;

            GLWindow::m_funcs->glLinkProgram(this->_programId);
            GLWindow::m_funcs->glGetProgramiv(this->_programId, GL_LINK_STATUS, &result);
            this->linked = result == GL_TRUE;

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

            return this->linked;
        }

        void    ShaderProgram::bind(void) const
        {
            GLWindow::m_funcs->glUseProgram(this->id);
        }

        void    ShaderProgram::unbind(void) const
        {
            GLWindow::m_funcs->glUseProgram(0);
        }


        bool
        ShaderProgram::isLinked(void) const
        {
            return this->linked;
        }



        void
        ShaderProgram::setUniform(const std::string &name, float value)
        {
            int uniLocation = GLWindow::m_funcs->glGetUniformLocation(this->id, name.c_str());
            GLWindow::m_funcs->glUniform1f(uniLocation, value);
        }

        void
        ShaderProgram::setUniform(const std::string &name, const glm::vec2 &vec)
        {
            int uniLocation = GLWindow::m_funcs->glGetUniformLocation(this->id, name.c_str());
            GLWindow::m_funcs->glUniform2f(uniLocation, vec.x, vec.y);
        }

        void
        ShaderProgram::setUniform(const std::string &name, const glm::vec3 &vec)
        {
            int uniLocation = GLWindow::m_funcs->glGetUniformLocation(this->id, name.c_str());
            GLWindow::m_funcs->glUniform3f(uniLocation, vec.x, vec.y, vec.z);
        }

        void
        ShaderProgram::setUniform(const std::string &name, const glm::vec4 &vec)
        {
            int uniLocation = GLWindow::m_funcs->glGetUniformLocation(this->id, name.c_str());
            GLWindow::m_funcs->glUniform4f(uniLocation, vec.x, vec.y, vec.z, vec.w);
        }

        void
        ShaderProgram::setUniform(const std::string &name, int value) const
        {
        }

        void
        ShaderProgram::setUniform(const std::string &name, const glm::ivec2 &value) const
        {

        }

        void
        ShaderProgram::setUniform(const std::string &name, const glm::ivec3 &value) const
        {

        }

        void
        ShaderProgram::setUniform(const std::string &name, const glm::ivec3 &value) const
        {

        }

        void
        ShaderProgram::setUniform(const std::string &name, const glm::ivec4 &value) const
        {
        }

        void
        ShaderProgram::setUniform(const std::string &name, const glm::mat4 &matrix) const
        {
            int uniLocation = GLWindow::m_funcs->glGetUniformLocation(this->id, name.c_str());
            GLWindow::m_funcs->glUniformMatrix4fv(uniLocation, 1, GL_FALSE, glm::value_ptr(matrix));
        }

        void
        ShaderProgram::setUniform(const std::string &name, const glm::vec3 &vec) const
        {
            int uniLocation = GLWindow::m_funcs->glGetUniformLocation(this->id, name.c_str());
            GLWindow::m_funcs->glUniformMatrix4fv(uniLocation, 1, GL_FALSE, glm::value_ptr(matrix));
        }
    }
}
