///
/// \file ShaderMapping.hpp
///
/// \author Martin-Pierrat Louis (mart_p)
///
/// \date Sat, 16 Jan 2016 21:01:12
///
/// \version 1.0.4
///

#ifndef     __INTERNAL_ENGINE_SHADER_MAPPING_HPP__
# define    __INTERNAL_ENGINE_SHADER_MAPPING_HPP__

#include    <map>

#include    <Engine/Shader.hpp>
#include    <Engine/ShaderNames.hpp>

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

#endif /* !__INTERNAL_ENGINE_SHADER_MAPPING_HPP__ */
