///
/// \file ShaderProgramMapping.hpp
///
/// \author Martin-Pierrat Louis (mart_p)
///
/// \date Fri, 15 Jan 2016 13:34:44
///
/// \version 1.0.1
///

#ifndef     __INTERNAL_SHADER_PROGRAM_MAPPING_HPP__
# define    __INTERNAL_SHADER_PROGRAM_MAPPING_HPP__

#include    <map>
#include    <vector>

#include    "ShaderProgram.hpp"
#include    "ShaderNames.hpp"
#include    "ShaderProgramNames.hpp"

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

#endif /* !__INTERNAL_SHADER_PROGRAM_MAPPING_HPP__ */
