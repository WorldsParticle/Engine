#ifndef     __INTERNAL_SHADER_MAPPING_HPP__
# define    __INTERNAL_SHADER_MAPPING_HPP__

#include    <map>

#include    "Shader.hpp"
#include    "ShaderNames.hpp"

namespace   WorldParticles
{
    namespace   Engine
    {

        struct  ShaderProperty
        {
            Shader::Type    shaderType;
            std::string     filename;
        };

        const std::map<ShaderName, ShaderProperty>    MappedShaders = {
            {DEFAULT_VERTEX_SHADER, {Shader::Type::VERTEX_SHADER, "default.vert"}},
            {DEFAULT_FRAGMENT_SHADER, {Shader::Type::FRAGMENT_SHADER, "default.frag"}},
            {TEST_VERTEX_SHADER, {Shader::Type::VERTEX_SHADER, "light.vert"}},
            {TEST_FRAGMENT_SHADER, {Shader::Type::FRAGMENT_SHADER, "light.frag"}}
        };

    }
}

#endif /* !__INTERNAL_SHADER_MAPPING_HPP__ */
