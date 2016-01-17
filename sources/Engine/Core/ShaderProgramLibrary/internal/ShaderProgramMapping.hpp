///
/// \file ShaderProgramMapping.hpp
///
/// \author Martin-Pierrat Louis (mart_p)
///
/// \date Sat, 16 Jan 2016 20:59:58
///
/// \version 1.0.4
///

#ifndef     __INTERNAL_ENGINE_SHADER_PROGRAM_MAPPING_HPP__
# define    __INTERNAL_ENGINE_SHADER_PROGRAM_MAPPING_HPP__

#include    <map>
#include    <vector>

#include    <Engine/ShaderProgram.hpp>
#include    <Engine/ShaderNames.hpp>
#include    <Engine/ShaderProgramNames.hpp>

namespace   WorldParticles
{
    namespace   Engine
    {
        struct      ShaderProgramProperty
        {
            std::vector<ShaderName>  associatedShaders;
        };

        const std::map<ShaderProgramName, ShaderProgramProperty>    MappedShaderProgram = {
            {DEFAULT_SHADER_PROGRAM, {{DEFAULT_VERTEX_SHADER, DEFAULT_FRAGMENT_SHADER}}},
            {TEST_SHADER_PROGRAM, {{TEST_VERTEX_SHADER, TEST_FRAGMENT_SHADER}}}
        };
    }
}

#endif /* !__INTERNAL_ENGINE_SHADER_PROGRAM_MAPPING_HPP__ */
