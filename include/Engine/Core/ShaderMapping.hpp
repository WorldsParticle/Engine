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

#pragma once

#include    <map>

#include    "Engine/Core/Shader.hpp"
#include    "Engine/Core/ShaderNames.hpp"

namespace   Engine
{

    struct ShaderProperty
    {
        Shader::Type    shaderType;
        std::string     filename;
    };

    const std::map<ShaderName, ShaderProperty>    MappedShaders = {
        {DEFAULT_VERTEX_SHADER, {Shader::Type::VERTEX_SHADER, "default.vert"}},
        {DEFAULT_FRAGMENT_SHADER, {Shader::Type::FRAGMENT_SHADER, "default.frag"}},
        {NUAGES_VERTEX_SHADER, {Shader::Type::VERTEX_SHADER, "nuages.vert"}},
        {NUAGES_FRAGMENT_SHADER, {Shader::Type::FRAGMENT_SHADER, "nuages.frag"}},
        {TEST_VERTEX_SHADER, {Shader::Type::VERTEX_SHADER, "light.vert"}},
        {TEST_FRAGMENT_SHADER, {Shader::Type::FRAGMENT_SHADER, "light.frag"}},
        {TEXTURE_VERTEX_SHADER, {Shader::Type::VERTEX_SHADER, "texture.vert"}},
        {TEXTURE_FRAGMENT_SHADER, {Shader::Type::FRAGMENT_SHADER, "texture.frag"}}
    };

}
