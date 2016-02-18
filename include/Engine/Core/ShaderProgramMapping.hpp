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
        {TEST_SHADER_PROGRAM, {{TEST_VERTEX_SHADER, TEST_FRAGMENT_SHADER}}},
        {TEXTURE_SHADER_PROGRAM, {{TEXTURE_VERTEX_SHADER, TEXTURE_FRAGMENT_SHADER}}}
    };
}

#endif /* !__INTERNAL_ENGINE_SHADER_PROGRAM_MAPPING_HPP__ */
