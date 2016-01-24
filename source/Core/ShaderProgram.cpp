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
#include    <glm/gtc/type_ptr.hpp>
# include   <log4cpp/Category.hh>

#include    "Engine/Core/ShaderProgram.hpp"

namespace   Engine
{

    ShaderProgram::ShaderProgram(void) :
        id(glCreateProgram()),
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
        glDeleteProgram(this->id);
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
        glAttachShader(this->id, shader->getId());
    }

    bool
    ShaderProgram::link(void)
    {
        int     result = GL_FALSE;

        glLinkProgram(this->id);
        glGetProgramiv(this->id, GL_LINK_STATUS, &result);
        this->linked = (result == GL_TRUE);
        if (this->linked == false)
        {
            glGetProgramiv(this->id, GL_INFO_LOG_LENGTH, &result);
            if (result > 1)
            {
                char *info = new char[result + 1];
                glGetProgramInfoLog(this->id, result, 0, info);
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
        glUseProgram(this->id);
    }

    void
    ShaderProgram::unbind(void) const
    {
        glUseProgram(0);
    }



    bool
    ShaderProgram::isLinked(void) const
    {
        return this->linked;
    }



    void
    ShaderProgram::setUniform(const std::string &name, float value) const
    {
        int location = glGetUniformLocation(this->id, name.c_str());
        if (location == -1) throw std::runtime_error("the uniform name " + name + " is invalid.");
        glUniform1f(location, value);
    }

    void
    ShaderProgram::setUniform(const std::string &name, const glm::vec2 &value) const
    {
        int location = glGetUniformLocation(this->id, name.c_str());
        if (location == -1) throw std::runtime_error("the uniform name " + name + " is invalid.");
        glUniform2f(location, value.x, value.y);
    }

    void
    ShaderProgram::setUniform(const std::string &name, const glm::vec3 &value) const
    {
        int location = glGetUniformLocation(this->id, name.c_str());
        if (location == -1) throw std::runtime_error("the uniform name " + name + " is invalid.");
        glUniform3f(location, value.x, value.y, value.z);
    }

    void
    ShaderProgram::setUniform(const std::string &name, const glm::vec4 &value) const
    {
        int location = glGetUniformLocation(this->id, name.c_str());
        if (location == -1) throw std::runtime_error("the uniform name " + name + " is invalid.");
        glUniform4f(location, value.x, value.y, value.z, value.w);
    }

    void
    ShaderProgram::setUniform(const std::string &name, int value) const
    {
        int location = glGetUniformLocation(this->id, name.c_str());
        if (location == -1) throw std::runtime_error("the uniform name " + name + " is invalid.");
        glUniform1i(location, value);
    }

    void
    ShaderProgram::setUniform(const std::string &name, const glm::ivec2 &value) const
    {
        int location = glGetUniformLocation(this->id, name.c_str());
        if (location == -1) throw std::runtime_error("the uniform name " + name + " is invalid.");
        glUniform2i(location, value.x, value.y);
    }

    void
    ShaderProgram::setUniform(const std::string &name, const glm::ivec3 &value) const
    {
        int location = glGetUniformLocation(this->id, name.c_str());
        if (location == -1) throw std::runtime_error("the uniform name " + name + " is invalid.");
        glUniform3i(location, value.x, value.y, value.z);
    }

    void
    ShaderProgram::setUniform(const std::string &name, const glm::ivec4 &value) const
    {
        int location = glGetUniformLocation(this->id, name.c_str());
        if (location == -1) throw std::runtime_error("the uniform name " + name + " is invalid.");
        glUniform4i(location, value.x, value.y, value.z, value.w);
    }

    void
    ShaderProgram::setUniform(const std::string &name, unsigned int value) const
    {
        int location = glGetUniformLocation(this->id, name.c_str());
        if (location == -1) throw std::runtime_error("the uniform name " + name + " is invalid.");
        glUniform1ui(location, value);
    }

    void
    ShaderProgram::setUniform(const std::string &name, const glm::uvec2 &value) const
    {
        int location = glGetUniformLocation(this->id, name.c_str());
        if (location == -1) throw std::runtime_error("the uniform name " + name + " is invalid.");
        glUniform2ui(location, value.x, value.y);
   }

    void
    ShaderProgram::setUniform(const std::string &name, const glm::uvec3 &value) const
    {
        int location = glGetUniformLocation(this->id, name.c_str());
        if (location == -1) throw std::runtime_error("the uniform name " + name + " is invalid.");
        glUniform3ui(location, value.x, value.y, value.z);
   }

    void
    ShaderProgram::setUniform(const std::string &name, const glm::uvec4 &value) const
    {
        int location = glGetUniformLocation(this->id, name.c_str());
        if (location == -1) throw std::runtime_error("the uniform name " + name + " is invalid.");
        glUniform4ui(location, value.x, value.y, value.z, value.w);
    }

    void
    ShaderProgram::setUniform(const std::string &name, const std::vector<float> &value) const
    {
        int location = glGetUniformLocation(this->id, name.c_str());
        if (location == -1) throw std::runtime_error("the uniform name " + name + " is invalid.");
        glUniform1fv(location, value.size(), value.data());
   }

    void
    ShaderProgram::setUniform(const std::string &name, const std::vector<glm::vec2> &value) const
    {
        int location = glGetUniformLocation(this->id, name.c_str());
        if (location == -1) throw std::runtime_error("the uniform name " + name + " is invalid.");
        glUniform2fv(location, value.size(), reinterpret_cast<const float *>(value.data()));
   }

    void
    ShaderProgram::setUniform(const std::string &name, const std::vector<glm::vec3> &value) const
    {
        int location = glGetUniformLocation(this->id, name.c_str());
        if (location == -1) throw std::runtime_error("the uniform name " + name + " is invalid.");
        glUniform3fv(location, value.size(), reinterpret_cast<const float *>(value.data()));
   }

    void
    ShaderProgram::setUniform(const std::string &name, const std::vector<glm::vec4> &value) const
    {
        int location = glGetUniformLocation(this->id, name.c_str());
        if (location == -1) throw std::runtime_error("the uniform name " + name + " is invalid.");
        glUniform4fv(location, value.size(), reinterpret_cast<const float *>(value.data()));
   }

    void
    ShaderProgram::setUniform(const std::string &name, const std::vector<int> &value) const
    {
        int location = glGetUniformLocation(this->id, name.c_str());
        if (location == -1) throw std::runtime_error("the uniform name " + name + " is invalid.");
        glUniform1iv(location, value.size(), value.data());
    }

    void
    ShaderProgram::setUniform(const std::string &name, const std::vector<glm::ivec2> &value) const
    {
        int location = glGetUniformLocation(this->id, name.c_str());
        if (location == -1) throw std::runtime_error("the uniform name " + name + " is invalid.");
        glUniform2iv(location, value.size(), reinterpret_cast<const int *>(value.data()));
    }

    void
    ShaderProgram::setUniform(const std::string &name, const std::vector<glm::ivec3> &value) const
    {
        int location = glGetUniformLocation(this->id, name.c_str());
        if (location == -1) throw std::runtime_error("the uniform name " + name + " is invalid.");
        glUniform3iv(location, value.size(), reinterpret_cast<const int *>(value.data()));
    }

    void
    ShaderProgram::setUniform(const std::string &name, const std::vector<glm::ivec4> &value) const
    {
        int location = glGetUniformLocation(this->id, name.c_str());
        if (location == -1) throw std::runtime_error("the uniform name " + name + " is invalid.");
        glUniform4iv(location, value.size(), reinterpret_cast<const int *>(value.data()));
    }

    void
    ShaderProgram::setUniform(const std::string &name, const std::vector<unsigned int> &value) const
    {
        int location = glGetUniformLocation(this->id, name.c_str());
        if (location == -1) throw std::runtime_error("the uniform name " + name + " is invalid.");
        glUniform1uiv(location, value.size(), value.data());
    }

    void
    ShaderProgram::setUniform(const std::string &name, const std::vector<glm::uvec2> &value) const
    {
        int location = glGetUniformLocation(this->id, name.c_str());
        if (location == -1) throw std::runtime_error("the uniform name " + name + " is invalid.");
        glUniform2uiv(location, value.size(), reinterpret_cast<const unsigned int *>(value.data()));
    }

    void
    ShaderProgram::setUniform(const std::string &name, const std::vector<glm::uvec3> &value) const
    {
        int location = glGetUniformLocation(this->id, name.c_str());
        if (location == -1) throw std::runtime_error("the uniform name " + name + " is invalid.");
        glUniform3uiv(location, value.size(), reinterpret_cast<const unsigned int *>(value.data()));
    }

    void
    ShaderProgram::setUniform(const std::string &name, const std::vector<glm::uvec4> &value) const
    {
        int location = glGetUniformLocation(this->id, name.c_str());
        if (location == -1) throw std::runtime_error("the uniform name " + name + " is invalid.");
        glUniform4uiv(location, value.size(), reinterpret_cast<const unsigned int *>(value.data()));
    }

    void
    ShaderProgram::setUniform(const std::string &name, const glm::mat2 &value) const
    {
        int location = glGetUniformLocation(this->id, name.c_str());
        if (location == -1) throw std::runtime_error("the uniform name " + name + " is invalid.");
        glUniformMatrix2fv(location, 1, GL_FALSE, glm::value_ptr(value));
    }

    void
    ShaderProgram::setUniform(const std::string &name, const glm::mat3 &value) const
    {
        int location = glGetUniformLocation(this->id, name.c_str());
        if (location == -1) throw std::runtime_error("the uniform name " + name + " is invalid.");
        glUniformMatrix3fv(location, 1, GL_FALSE, glm::value_ptr(value));
    }

    void
    ShaderProgram::setUniform(const std::string &name, const glm::mat4 &value) const
    {
        int location = glGetUniformLocation(this->id, name.c_str());
        if (location == -1) throw std::runtime_error("the uniform name " + name + " is invalid.");
        glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(value));
    }

    void
    ShaderProgram::setUniform(const std::string &name, const glm::mat2x3 &value) const
    {
        int location = glGetUniformLocation(this->id, name.c_str());
        if (location == -1) throw std::runtime_error("the uniform name " + name + " is invalid.");
        glUniformMatrix2x3fv(location, 1, GL_FALSE, glm::value_ptr(value));
    }

    void
    ShaderProgram::setUniform(const std::string &name, const glm::mat3x2 &value) const
    {
        int location = glGetUniformLocation(this->id, name.c_str());
        if (location == -1) throw std::runtime_error("the uniform name " + name + " is invalid.");
        glUniformMatrix3x2fv(location, 1, GL_FALSE, glm::value_ptr(value));
    }

    void
    ShaderProgram::setUniform(const std::string &name, const glm::mat2x4 &value) const
    {
        int location = glGetUniformLocation(this->id, name.c_str());
        if (location == -1) throw std::runtime_error("the uniform name " + name + " is invalid.");
        glUniformMatrix2x4fv(location, 1, GL_FALSE, glm::value_ptr(value));
    }

    void
    ShaderProgram::setUniform(const std::string &name, const glm::mat4x2 &value) const
    {
        int location = glGetUniformLocation(this->id, name.c_str());
        if (location == -1) throw std::runtime_error("the uniform name " + name + " is invalid.");
        glUniformMatrix4x2fv(location, 1, GL_FALSE, glm::value_ptr(value));
    }

    void
    ShaderProgram::setUniform(const std::string &name, const glm::mat3x4 &value) const
    {
        int location = glGetUniformLocation(this->id, name.c_str());
        if (location == -1) throw std::runtime_error("the uniform name " + name + " is invalid.");
        glUniformMatrix3x4fv(location, 1, GL_FALSE, glm::value_ptr(value));
    }

    void
    ShaderProgram::setUniform(const std::string &name, const glm::mat4x3 &value) const
    {
        int location = glGetUniformLocation(this->id, name.c_str());
        if (location == -1) throw std::runtime_error("the uniform name " + name + " is invalid.");
        glUniformMatrix4x3fv(location, 1, GL_FALSE, glm::value_ptr(value));
    }

    void
    ShaderProgram::setUniform(const std::string &name, const std::vector<glm::mat2> &value) const
    {
        int location = glGetUniformLocation(this->id, name.c_str());
        if (location == -1) throw std::runtime_error("the uniform name " + name + " is invalid.");
        glUniformMatrix2fv(location, value.size(), GL_FALSE, reinterpret_cast<const float *>(value.data()));
    }

    void
    ShaderProgram::setUniform(const std::string &name, const std::vector<glm::mat3> &value) const
    {
        int location = glGetUniformLocation(this->id, name.c_str());
        if (location == -1) throw std::runtime_error("the uniform name " + name + " is invalid.");
        glUniformMatrix3fv(location, value.size(), GL_FALSE, reinterpret_cast<const float *>(value.data()));
    }

    void
    ShaderProgram::setUniform(const std::string &name, const std::vector<glm::mat4> &value) const
    {
        int location = glGetUniformLocation(this->id, name.c_str());
        if (location == -1) throw std::runtime_error("the uniform name " + name + " is invalid.");
        glUniformMatrix4fv(location, value.size(), GL_FALSE, reinterpret_cast<const float *>(value.data()));
    }

    void
    ShaderProgram::setUniform(const std::string &name, const std::vector<glm::mat2x3> &value) const
    {
        int location = glGetUniformLocation(this->id, name.c_str());
        if (location == -1) throw std::runtime_error("the uniform name " + name + " is invalid.");
        glUniformMatrix2x3fv(location, value.size(), GL_FALSE, reinterpret_cast<const float *>(value.data()));
    }

    void
    ShaderProgram::setUniform(const std::string &name, const std::vector<glm::mat3x2> &value) const
    {
        int location = glGetUniformLocation(this->id, name.c_str());
        if (location == -1) throw std::runtime_error("the uniform name " + name + " is invalid.");
        glUniformMatrix3x2fv(location, value.size(), GL_FALSE, reinterpret_cast<const float *>(value.data()));
    }

    void
    ShaderProgram::setUniform(const std::string &name, const std::vector<glm::mat2x4> &value) const
    {
        int location = glGetUniformLocation(this->id, name.c_str());
        if (location == -1) throw std::runtime_error("the uniform name " + name + " is invalid.");
        glUniformMatrix2x4fv(location, value.size(), GL_FALSE, reinterpret_cast<const float *>(value.data()));
    }

    void
    ShaderProgram::setUniform(const std::string &name, const std::vector<glm::mat4x2> &value) const
    {
        int location = glGetUniformLocation(this->id, name.c_str());
        if (location == -1) throw std::runtime_error("the uniform name " + name + " is invalid.");
        glUniformMatrix4x2fv(location, value.size(), GL_FALSE, reinterpret_cast<const float *>(value.data()));
    }

    void
    ShaderProgram::setUniform(const std::string &name, const std::vector<glm::mat3x4> &value) const
    {
        int location = glGetUniformLocation(this->id, name.c_str());
        if (location == -1) throw std::runtime_error("the uniform name " + name + " is invalid.");
        glUniformMatrix3x4fv(location, value.size(), GL_FALSE, reinterpret_cast<const float *>(value.data()));
    }

    void
    ShaderProgram::setUniform(const std::string &name, const std::vector<glm::mat4x3> &value) const
    {
        int location = glGetUniformLocation(this->id, name.c_str());
        if (location == -1) throw std::runtime_error("the uniform name " + name + " is invalid.");
        glUniformMatrix4x3fv(location, value.size(), GL_FALSE, reinterpret_cast<const float *>(value.data()));
    }

}
