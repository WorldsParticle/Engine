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

#include    "Engine/Core/Material.hpp"
#include    "Engine/Core/ShaderProgram.hpp"

namespace   Engine
{

    Material::Material(const std::shared_ptr<ShaderProgram> &shaderprogram) :
        name("Default"),
        shaderprogram(shaderprogram)
    {
        // nothing to do
    }

    Material::Material(const aiMaterial *assimpMaterial,
            const std::shared_ptr<ShaderProgram> &shaderprogram) :
        name("Default"),
        shaderprogram(shaderprogram)
    {
        aiString assimpName;

        assimpMaterial->Get(AI_MATKEY_NAME, assimpName);
        this->name = assimpName.C_Str();
        // nothing to do atm.
    }

    Material::~Material(void) noexcept
    {
        // nothind to do.
    }



    const std::string &
    Material::getName(void) const
    {
        return this->name;
    }



    void
    Material::setName(const std::string &name)
    {
        this->name = name;
    }



    const std::shared_ptr<ShaderProgram> &
    Material::getShaderProgram(void) const
    {
         return this->shaderprogram;
    }

    void
    Material::bind(void) const
    {
        this->shaderprogram->bind();
    }

    void
    Material::unbind(void) const
    {
         this->shaderprogram->unbind();
    }
}
