///
/// \file ShaderProgramMapping.hpp
///
/// \author Martin-Pierrat Louis (mart_p)
///
/// \date Sun, 17 Jan 2016 07:53:59
///
/// \version 1.0.7
///

#ifndef     __INTERNAL_ENGINE_SHADER_PROGRAM_MAPPING_HPP__
# define    __INTERNAL_ENGINE_SHADER_PROGRAM_MAPPING_HPP__

#include    <map>
#include    <vector>

#include    "Engine/Core/ShaderProgram.hpp"
#include    "Engine/Core/ShaderNames.hpp"
#include    "Engine/Core/ShaderProgramNames.hpp"

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

#endif /* !__INTERNAL_ENGINE_SHADER_PROGRAM_MAPPING_HPP__ */
