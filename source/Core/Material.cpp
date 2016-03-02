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
#include    "Engine/Core/Texture.hpp"
#include    "Engine/Core/TextureLibrary.hpp"

namespace   Engine
{

    Material::Material(const std::shared_ptr<ShaderProgram> &shaderprogram) :
        m_name("Default"),
        m_shaderprogram(shaderprogram),
        m_texture(nullptr)
    {
        // nothing to do
    }

    Material::Material(const aiMaterial *assimpMaterial,
            const std::shared_ptr<ShaderProgram> &shaderprogram,
            const TextureLibrary &texture_library) :
        m_name("Default"),
        m_shaderprogram(shaderprogram),
        m_texture(nullptr)
    {
        aiString assimpName;

        assimpMaterial->Get(AI_MATKEY_NAME, assimpName);
        this->m_name = assimpName.C_Str();

        if (assimpMaterial->GetTextureCount(aiTextureType_DIFFUSE) > 0)
        {
            aiString texture_path;
            assimpMaterial->GetTexture(aiTextureType_DIFFUSE, 0, &texture_path);
            this->m_texture = texture_library.get(texture_path.data);
        }
    }

    Material::~Material(void) noexcept
    {
        // nothind to do.
    }



    const std::string &
    Material::getName(void) const
    {
        return this->m_name;
    }

    void
    Material::setName(const std::string &name)
    {
        this->m_name = name;
    }

    const std::shared_ptr<ShaderProgram> &
    Material::getShaderProgram(void) const
    {
        return this->m_shaderprogram;
    }



    void
    Material::bind(void) const
    {
        this->m_shaderprogram->bind();
        if (this->m_texture != nullptr)
        {
            this->m_texture->bind();
        }
    }

    void
    Material::unbind(void) const
    {
        this->m_shaderprogram->unbind();
        if (this->m_texture != nullptr)
        {
             this->m_texture->unbind();
        }
    }
}
