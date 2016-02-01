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

#include    "Engine/Core/Shader.hpp"

using namespace     log4cpp;

namespace Engine
{

    Shader::Shader(const Shader::Type &type, const std::string &shaderData) :
        m_id(createShaderFromType(type)),
        m_compiled(false),
        m_type(type)
    {
        const char *c_str = shaderData.c_str();
        glShaderSource(this->m_id, 1, &c_str, nullptr);
    }

    Shader::Shader(Shader &&other) noexcept :
        m_id(std::move(other.m_id)),
        m_compiled(std::move(other.m_compiled)),
        m_type(std::move(other.m_type))
    {
        other.m_id = 0;
    }

    Shader::~Shader(void)
    {
        glDeleteShader(this->m_id);
    }



    Shader &
    Shader::operator=(Shader &&other) noexcept
    {
        this->m_id = std::move(other.m_id);
        other.m_id = 0;
        this->m_compiled = std::move(other.m_compiled);
        this->m_type = std::move(other.m_type);
        return *this;
    }



    bool Shader::compile(void)
    {
        int     result;

        glCompileShader(this->m_id);
        glGetShaderiv(this->m_id, GL_COMPILE_STATUS, &result);
        this->m_compiled = result == GL_TRUE;
        if (this->m_compiled == false)
        {
            glGetShaderiv(this->m_id, GL_INFO_LOG_LENGTH, &result);
            if (result > 1)
            {
                char *info = new char[result + 1];
                glGetShaderInfoLog(this->m_id, result, nullptr, info);
                Category &root = Category::getRoot();
                root << Priority::ERROR << info;
                delete info;
            }
        }
        return this->m_compiled;
    }



    const Shader::Type &
    Shader::getType(void) const
    {
         return this->m_type;
    }

    unsigned int
    Shader::getId(void) const
    {
        return this->m_id;
    }

    bool
    Shader::isCompiled(void) const
    {
         return this->m_compiled;
    }



    /// TODO : should be unit tested.
    unsigned int    Shader::createShaderFromType(const Shader::Type &type)
    {
        switch (type)
        {
            case Shader::Type::VERTEX_SHADER:
                return glCreateShader(GL_VERTEX_SHADER);
            case Shader::Type::TESSELATION_CONTROL_SHADER:
                return glCreateShader(GL_TESS_CONTROL_SHADER);
            case Shader::Type::EVALUATION_SHADER:
                return glCreateShader(GL_TESS_EVALUATION_SHADER);
            case Shader::Type::GEOMETRY_SHADER:
                return glCreateShader(GL_GEOMETRY_SHADER);
            case Shader::Type::FRAGMENT_SHADER:
                return glCreateShader(GL_FRAGMENT_SHADER);
            case Shader::Type::COMPUTE_SHADER:
                return glCreateShader(GL_COMPUTE_SHADER);
            default:
                return 0;
        }
    }

}
