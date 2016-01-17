///
/// \file Shader.cpp
///
/// \author Martin-Pierrat Louis (mart_p)
///
/// \date Sat, 16 Jan 2016 17:57:24
///
/// \version 2.0.5
///

#include    <GL/glew.h>
#include    <log4cpp/Category.hh>

#include    "Shader.hpp"

using namespace     log4cpp;

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
            glShaderSource(this->id, 1, &c_str, 0);
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
            glDeleteShader(this->id);
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

            glCompileShader(this->id);
            glGetShaderiv(this->id, GL_COMPILE_STATUS, &result);
            this->compiled = result == GL_TRUE;
            if (this->compiled == false)
            {
                glGetShaderiv(this->id, GL_INFO_LOG_LENGTH, &result);
                if (result > 1)
                {
                    char *info = new char[result + 1];
                    glGetShaderInfoLog(this->id, result, 0, info);
                    Category &root = Category::getRoot();
                    root << Priority::ERROR << info;
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
}
