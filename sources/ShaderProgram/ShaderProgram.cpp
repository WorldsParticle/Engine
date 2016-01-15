///
/// \file ShaderProgram.cpp
///
/// \author Martin-Pierrat Louis (mart_p)
///
/// \date Fri, 15 Jan 2016 13:34:15
///
/// \version 1.0.3
///

#include    <glm/gtc/type_ptr.hpp>
# include   <log4cpp/Category.hh>

#include    "ShaderProgram.hpp"

namespace   WorldParticles
{
    namespace   Engine
    {

        ShaderProgram::ShaderProgram(void) :
            id(GLWindow::m_funcs->glCreateProgram()),
            linked(false)
        {
            // nothing to do
        }

        ShaderProgram::ShaderProgram(ShaderProgram &&other) noexcept :
            id(std::move(other.id)),
            linked(std::move(other.linked))
        {
            other.id = 0;
        }

        ShaderProgram::~ShaderProgram(void) noexcept
        {
            GLWindow::m_funcs->glDeleteProgram(this->id);
        }



        ShaderProgram &
        ShaderProgram::operator=(ShaderProgram &&other) noexcept
        {
            this->id = std::move(other.id);
            other.id = 0;
            this->linked = std::move(other.linked);
            return *this;
        }

        ShaderProgram &
        ShaderProgram::operator<<(const std::shared_ptr<Shader> &shader)
        {
            this->add(shader);
            return *this;
        }



        void
        ShaderProgram::add(const std::shared_ptr<Shader> &shader)
        {
            GLWindow::m_funcs->glAttachShader(this->id, shader->getId());
        }

        bool
        ShaderProgram::link(void)
        {
            int     result = GL_FALSE;

            GLWindow::m_funcs->glLinkProgram(this->id);
            GLWindow::m_funcs->glGetProgramiv(this->id, GL_LINK_STATUS, &result);
            this->linked = (result == GL_TRUE);
            if (this->linked == false)
            {
                GLWindow::m_funcs->glGetProgramiv(this->id, GL_INFO_LOG_LENGTH, &result);
                if (result > 1)
                {
                    char *info = new char[result + 1];
                    GLWindow::m_funcs->glGetProgramInfoLog(this->id, result, 0, info);
                    log4cpp::Category &root = log4cpp::Category::getRoot();
                    root << log4cpp::Priority::ERROR << info;
                    delete info;
                }
            }
            return this->linked;
        }

        void
        ShaderProgram::bind(void) const
        {
            GLWindow::m_funcs->glUseProgram(this->id);
        }

        void
        ShaderProgram::unbind(void) const
        {
            GLWindow::m_funcs->glUseProgram(0);
        }



        bool
        ShaderProgram::isLinked(void) const
        {
            return this->linked;
        }



        void
        ShaderProgram::setUniform(const std::string &name, float value) const
        {
            int location = GLWindow::m_funcs->glGetUniformLocation(this->id, name.c_str());
            if (location == -1) throw std::runtime_error("the uniform name " + name + " is invalid.");
            GLWindow::m_funcs->glUniform1f(location, value);
        }

        void
        ShaderProgram::setUniform(const std::string &name, const glm::vec2 &value) const
        {
            int location = GLWindow::m_funcs->glGetUniformLocation(this->id, name.c_str());
            if (location == -1) throw std::runtime_error("the uniform name " + name + " is invalid.");
            GLWindow::m_funcs->glUniform2f(location, value.x, value.y);
        }

        void
        ShaderProgram::setUniform(const std::string &name, const glm::vec3 &value) const
        {
            int location = GLWindow::m_funcs->glGetUniformLocation(this->id, name.c_str());
            if (location == -1) throw std::runtime_error("the uniform name " + name + " is invalid.");
            GLWindow::m_funcs->glUniform3f(location, value.x, value.y, value.z);
        }

        void
        ShaderProgram::setUniform(const std::string &name, const glm::vec4 &value) const
        {
            int location = GLWindow::m_funcs->glGetUniformLocation(this->id, name.c_str());
            if (location == -1) throw std::runtime_error("the uniform name " + name + " is invalid.");
            GLWindow::m_funcs->glUniform4f(location, value.x, value.y, value.z, value.w);
        }

        void
        ShaderProgram::setUniform(const std::string &name, int value) const
        {
            int location = GLWindow::m_funcs->glGetUniformLocation(this->id, name.c_str());
            if (location == -1) throw std::runtime_error("the uniform name " + name + " is invalid.");
            GLWindow::m_funcs->glUniform1i(location, value);
        }

        void
        ShaderProgram::setUniform(const std::string &name, const glm::ivec2 &value) const
        {
            int location = GLWindow::m_funcs->glGetUniformLocation(this->id, name.c_str());
            if (location == -1) throw std::runtime_error("the uniform name " + name + " is invalid.");
            GLWindow::m_funcs->glUniform2i(location, value.x, value.y);
        }

        void
        ShaderProgram::setUniform(const std::string &name, const glm::ivec3 &value) const
        {
            int location = GLWindow::m_funcs->glGetUniformLocation(this->id, name.c_str());
            if (location == -1) throw std::runtime_error("the uniform name " + name + " is invalid.");
            GLWindow::m_funcs->glUniform3i(location, value.x, value.y, value.z);
        }

        void
        ShaderProgram::setUniform(const std::string &name, const glm::ivec4 &value) const
        {
            int location = GLWindow::m_funcs->glGetUniformLocation(this->id, name.c_str());
            if (location == -1) throw std::runtime_error("the uniform name " + name + " is invalid.");
            GLWindow::m_funcs->glUniform4i(location, value.x, value.y, value.z, value.w);
        }

        void
        ShaderProgram::setUniform(const std::string &name, unsigned int value) const
        {
            int location = GLWindow::m_funcs->glGetUniformLocation(this->id, name.c_str());
            if (location == -1) throw std::runtime_error("the uniform name " + name + " is invalid.");
            GLWindow::m_funcs->glUniform1ui(location, value);
        }

        void
        ShaderProgram::setUniform(const std::string &name, const glm::uvec2 &value) const
        {
            int location = GLWindow::m_funcs->glGetUniformLocation(this->id, name.c_str());
            if (location == -1) throw std::runtime_error("the uniform name " + name + " is invalid.");
            GLWindow::m_funcs->glUniform2ui(location, value.x, value.y);
       }

        void
        ShaderProgram::setUniform(const std::string &name, const glm::uvec3 &value) const
        {
            int location = GLWindow::m_funcs->glGetUniformLocation(this->id, name.c_str());
            if (location == -1) throw std::runtime_error("the uniform name " + name + " is invalid.");
            GLWindow::m_funcs->glUniform3ui(location, value.x, value.y, value.z);
       }

        void
        ShaderProgram::setUniform(const std::string &name, const glm::uvec4 &value) const
        {
            int location = GLWindow::m_funcs->glGetUniformLocation(this->id, name.c_str());
            if (location == -1) throw std::runtime_error("the uniform name " + name + " is invalid.");
            GLWindow::m_funcs->glUniform4ui(location, value.x, value.y, value.z, value.w);
        }

        void
        ShaderProgram::setUniform(const std::string &name, const std::vector<float> &value) const
        {
            int location = GLWindow::m_funcs->glGetUniformLocation(this->id, name.c_str());
            if (location == -1) throw std::runtime_error("the uniform name " + name + " is invalid.");
            GLWindow::m_funcs->glUniform1fv(location, value.size(), value.data());
       }

        void
        ShaderProgram::setUniform(const std::string &name, const std::vector<glm::vec2> &value) const
        {
            int location = GLWindow::m_funcs->glGetUniformLocation(this->id, name.c_str());
            if (location == -1) throw std::runtime_error("the uniform name " + name + " is invalid.");
            GLWindow::m_funcs->glUniform2fv(location, value.size(), reinterpret_cast<const float *>(value.data()));
       }

        void
        ShaderProgram::setUniform(const std::string &name, const std::vector<glm::vec3> &value) const
        {
            int location = GLWindow::m_funcs->glGetUniformLocation(this->id, name.c_str());
            if (location == -1) throw std::runtime_error("the uniform name " + name + " is invalid.");
            GLWindow::m_funcs->glUniform3fv(location, value.size(), reinterpret_cast<const float *>(value.data()));
       }

        void
        ShaderProgram::setUniform(const std::string &name, const std::vector<glm::vec4> &value) const
        {
            int location = GLWindow::m_funcs->glGetUniformLocation(this->id, name.c_str());
            if (location == -1) throw std::runtime_error("the uniform name " + name + " is invalid.");
            GLWindow::m_funcs->glUniform4fv(location, value.size(), reinterpret_cast<const float *>(value.data()));
       }

        void
        ShaderProgram::setUniform(const std::string &name, const std::vector<int> &value) const
        {
            int location = GLWindow::m_funcs->glGetUniformLocation(this->id, name.c_str());
            if (location == -1) throw std::runtime_error("the uniform name " + name + " is invalid.");
            GLWindow::m_funcs->glUniform1iv(location, value.size(), value.data());
        }

        void
        ShaderProgram::setUniform(const std::string &name, const std::vector<glm::ivec2> &value) const
        {
            int location = GLWindow::m_funcs->glGetUniformLocation(this->id, name.c_str());
            if (location == -1) throw std::runtime_error("the uniform name " + name + " is invalid.");
            GLWindow::m_funcs->glUniform2iv(location, value.size(), reinterpret_cast<const int *>(value.data()));
        }

        void
        ShaderProgram::setUniform(const std::string &name, const std::vector<glm::ivec3> &value) const
        {
            int location = GLWindow::m_funcs->glGetUniformLocation(this->id, name.c_str());
            if (location == -1) throw std::runtime_error("the uniform name " + name + " is invalid.");
            GLWindow::m_funcs->glUniform3iv(location, value.size(), reinterpret_cast<const int *>(value.data()));
        }

        void
        ShaderProgram::setUniform(const std::string &name, const std::vector<glm::ivec4> &value) const
        {
            int location = GLWindow::m_funcs->glGetUniformLocation(this->id, name.c_str());
            if (location == -1) throw std::runtime_error("the uniform name " + name + " is invalid.");
            GLWindow::m_funcs->glUniform4iv(location, value.size(), reinterpret_cast<const int *>(value.data()));
        }

        void
        ShaderProgram::setUniform(const std::string &name, const std::vector<unsigned int> &value) const
        {
            int location = GLWindow::m_funcs->glGetUniformLocation(this->id, name.c_str());
            if (location == -1) throw std::runtime_error("the uniform name " + name + " is invalid.");
            GLWindow::m_funcs->glUniform1uiv(location, value.size(), value.data());
        }

        void
        ShaderProgram::setUniform(const std::string &name, const std::vector<glm::uvec2> &value) const
        {
            int location = GLWindow::m_funcs->glGetUniformLocation(this->id, name.c_str());
            if (location == -1) throw std::runtime_error("the uniform name " + name + " is invalid.");
            GLWindow::m_funcs->glUniform2uiv(location, value.size(), reinterpret_cast<const unsigned int *>(value.data()));
        }

        void
        ShaderProgram::setUniform(const std::string &name, const std::vector<glm::uvec3> &value) const
        {
            int location = GLWindow::m_funcs->glGetUniformLocation(this->id, name.c_str());
            if (location == -1) throw std::runtime_error("the uniform name " + name + " is invalid.");
            GLWindow::m_funcs->glUniform3uiv(location, value.size(), reinterpret_cast<const unsigned int *>(value.data()));
        }

        void
        ShaderProgram::setUniform(const std::string &name, const std::vector<glm::uvec4> &value) const
        {
            int location = GLWindow::m_funcs->glGetUniformLocation(this->id, name.c_str());
            if (location == -1) throw std::runtime_error("the uniform name " + name + " is invalid.");
            GLWindow::m_funcs->glUniform4uiv(location, value.size(), reinterpret_cast<const unsigned int *>(value.data()));
        }

        void
        ShaderProgram::setUniform(const std::string &name, const glm::mat2 &value) const
        {
            int location = GLWindow::m_funcs->glGetUniformLocation(this->id, name.c_str());
            if (location == -1) throw std::runtime_error("the uniform name " + name + " is invalid.");
            GLWindow::m_funcs->glUniformMatrix2fv(location, 1, GL_FALSE, glm::value_ptr(value));
        }

        void
        ShaderProgram::setUniform(const std::string &name, const glm::mat3 &value) const
        {
            int location = GLWindow::m_funcs->glGetUniformLocation(this->id, name.c_str());
            if (location == -1) throw std::runtime_error("the uniform name " + name + " is invalid.");
            GLWindow::m_funcs->glUniformMatrix3fv(location, 1, GL_FALSE, glm::value_ptr(value));
        }

        void
        ShaderProgram::setUniform(const std::string &name, const glm::mat4 &value) const
        {
            int location = GLWindow::m_funcs->glGetUniformLocation(this->id, name.c_str());
            if (location == -1) throw std::runtime_error("the uniform name " + name + " is invalid.");
            GLWindow::m_funcs->glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(value));
        }

        void
        ShaderProgram::setUniform(const std::string &name, const glm::mat2x3 &value) const
        {
            int location = GLWindow::m_funcs->glGetUniformLocation(this->id, name.c_str());
            if (location == -1) throw std::runtime_error("the uniform name " + name + " is invalid.");
            GLWindow::m_funcs->glUniformMatrix2x3fv(location, 1, GL_FALSE, glm::value_ptr(value));
        }

        void
        ShaderProgram::setUniform(const std::string &name, const glm::mat3x2 &value) const
        {
            int location = GLWindow::m_funcs->glGetUniformLocation(this->id, name.c_str());
            if (location == -1) throw std::runtime_error("the uniform name " + name + " is invalid.");
            GLWindow::m_funcs->glUniformMatrix3x2fv(location, 1, GL_FALSE, glm::value_ptr(value));
        }

        void
        ShaderProgram::setUniform(const std::string &name, const glm::mat2x4 &value) const
        {
            int location = GLWindow::m_funcs->glGetUniformLocation(this->id, name.c_str());
            if (location == -1) throw std::runtime_error("the uniform name " + name + " is invalid.");
            GLWindow::m_funcs->glUniformMatrix2x4fv(location, 1, GL_FALSE, glm::value_ptr(value));
        }

        void
        ShaderProgram::setUniform(const std::string &name, const glm::mat4x2 &value) const
        {
            int location = GLWindow::m_funcs->glGetUniformLocation(this->id, name.c_str());
            if (location == -1) throw std::runtime_error("the uniform name " + name + " is invalid.");
            GLWindow::m_funcs->glUniformMatrix4x2fv(location, 1, GL_FALSE, glm::value_ptr(value));
        }

        void
        ShaderProgram::setUniform(const std::string &name, const glm::mat3x4 &value) const
        {
            int location = GLWindow::m_funcs->glGetUniformLocation(this->id, name.c_str());
            if (location == -1) throw std::runtime_error("the uniform name " + name + " is invalid.");
            GLWindow::m_funcs->glUniformMatrix3x4fv(location, 1, GL_FALSE, glm::value_ptr(value));
        }

        void
        ShaderProgram::setUniform(const std::string &name, const glm::mat4x3 &value) const
        {
            int location = GLWindow::m_funcs->glGetUniformLocation(this->id, name.c_str());
            if (location == -1) throw std::runtime_error("the uniform name " + name + " is invalid.");
            GLWindow::m_funcs->glUniformMatrix4x3fv(location, 1, GL_FALSE, glm::value_ptr(value));
        }

        void
        ShaderProgram::setUniform(const std::string &name, const std::vector<glm::mat2> &value) const
        {
            int location = GLWindow::m_funcs->glGetUniformLocation(this->id, name.c_str());
            if (location == -1) throw std::runtime_error("the uniform name " + name + " is invalid.");
            GLWindow::m_funcs->glUniformMatrix2fv(location, value.size(), GL_FALSE, reinterpret_cast<const float *>(value.data()));
        }

        void
        ShaderProgram::setUniform(const std::string &name, const std::vector<glm::mat3> &value) const
        {
            int location = GLWindow::m_funcs->glGetUniformLocation(this->id, name.c_str());
            if (location == -1) throw std::runtime_error("the uniform name " + name + " is invalid.");
            GLWindow::m_funcs->glUniformMatrix3fv(location, value.size(), GL_FALSE, reinterpret_cast<const float *>(value.data()));
        }

        void
        ShaderProgram::setUniform(const std::string &name, const std::vector<glm::mat4> &value) const
        {
            int location = GLWindow::m_funcs->glGetUniformLocation(this->id, name.c_str());
            if (location == -1) throw std::runtime_error("the uniform name " + name + " is invalid.");
            GLWindow::m_funcs->glUniformMatrix4fv(location, value.size(), GL_FALSE, reinterpret_cast<const float *>(value.data()));
        }

        void
        ShaderProgram::setUniform(const std::string &name, const std::vector<glm::mat2x3> &value) const
        {
            int location = GLWindow::m_funcs->glGetUniformLocation(this->id, name.c_str());
            if (location == -1) throw std::runtime_error("the uniform name " + name + " is invalid.");
            GLWindow::m_funcs->glUniformMatrix2x3fv(location, value.size(), GL_FALSE, reinterpret_cast<const float *>(value.data()));
        }

        void
        ShaderProgram::setUniform(const std::string &name, const std::vector<glm::mat3x2> &value) const
        {
            int location = GLWindow::m_funcs->glGetUniformLocation(this->id, name.c_str());
            if (location == -1) throw std::runtime_error("the uniform name " + name + " is invalid.");
            GLWindow::m_funcs->glUniformMatrix3x2fv(location, value.size(), GL_FALSE, reinterpret_cast<const float *>(value.data()));
        }

        void
        ShaderProgram::setUniform(const std::string &name, const std::vector<glm::mat2x4> &value) const
        {
            int location = GLWindow::m_funcs->glGetUniformLocation(this->id, name.c_str());
            if (location == -1) throw std::runtime_error("the uniform name " + name + " is invalid.");
            GLWindow::m_funcs->glUniformMatrix2x4fv(location, value.size(), GL_FALSE, reinterpret_cast<const float *>(value.data()));
        }

        void
        ShaderProgram::setUniform(const std::string &name, const std::vector<glm::mat4x2> &value) const
        {
            int location = GLWindow::m_funcs->glGetUniformLocation(this->id, name.c_str());
            if (location == -1) throw std::runtime_error("the uniform name " + name + " is invalid.");
            GLWindow::m_funcs->glUniformMatrix4x2fv(location, value.size(), GL_FALSE, reinterpret_cast<const float *>(value.data()));
        }

        void
        ShaderProgram::setUniform(const std::string &name, const std::vector<glm::mat3x4> &value) const
        {
            int location = GLWindow::m_funcs->glGetUniformLocation(this->id, name.c_str());
            if (location == -1) throw std::runtime_error("the uniform name " + name + " is invalid.");
            GLWindow::m_funcs->glUniformMatrix3x4fv(location, value.size(), GL_FALSE, reinterpret_cast<const float *>(value.data()));
        }

        void
        ShaderProgram::setUniform(const std::string &name, const std::vector<glm::mat4x3> &value) const
        {
            int location = GLWindow::m_funcs->glGetUniformLocation(this->id, name.c_str());
            if (location == -1) throw std::runtime_error("the uniform name " + name + " is invalid.");
            GLWindow::m_funcs->glUniformMatrix4x3fv(location, value.size(), GL_FALSE, reinterpret_cast<const float *>(value.data()));
        }

    }
}
