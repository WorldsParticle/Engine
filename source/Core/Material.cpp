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
        m_name("Default"),
        m_shaderprogram(shaderprogram),
	_texture(NULL)
    {
        // nothing to do
    }

    Material::Material(const aiMaterial *assimpMaterial,
            const std::shared_ptr<ShaderProgram> &shaderprogram,
	    const TextureLibrary &texLib) :
        m_name("Default"),
        m_shaderprogram(shaderprogram),
	_texture(NULL)
    {
        aiString assimpName;

        assimpMaterial->Get(AI_MATKEY_NAME, assimpName);
        this->m_name = assimpName.C_Str();
	unsigned int count = assimpMaterial->GetTextureCount(aiTextureType_DIFFUSE);
	if (count != 0)
	{
	    aiString texPath;
	    for (unsigned int i = 0; i < count; i++)
	    {
		assimpMaterial->GetTexture(aiTextureType_DIFFUSE, i, &texPath);
		_texture = texLib.FindTexture(texPath.data);
	    }
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
	if (!this->_texture)
	{
	    this->_texture->bind();
	}
    }

    void
    Material::unbind(void) const
    {
         this->m_shaderprogram->unbind();
    }
}
