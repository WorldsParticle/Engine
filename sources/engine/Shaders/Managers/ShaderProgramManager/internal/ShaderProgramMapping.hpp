
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
