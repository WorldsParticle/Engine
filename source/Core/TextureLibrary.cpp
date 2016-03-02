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

#include    <IL/il.h>
#include    <IL/ilu.h>
#include    <IL/ilut.h>
#include    <GL/gl.h>
#include    <log4cpp/Category.hh>

#include    "Engine/Core/TextureLibrary.hpp"

using namespace     log4cpp;

namespace   Engine
{
    TextureLibrary::TextureLibrary(void) :
        Library<std::string, Texture *>()
    {
        // nothing to do.
    }

    TextureLibrary::TextureLibrary(aiTexture **assimpTextures, unsigned int size) :
        Library<std::string, Texture *>()
    {
        if (size > 0)
        {
            Category& root = Category::getRoot();
            root << Priority::DEBUG << "Support for meshes with embedded"
                << " textures is not implemented";
        }
    }

    TextureLibrary::TextureLibrary(const AssimpScene &ai_scene) :
        Library<std::string, Texture *>()
    {
        aiMaterial **materials = ai_scene.getMaterials();
        unsigned int materials_number = ai_scene.getMaterialsNumber();

        // iterate over each materials
        for (unsigned int material_index = 0 ;
                material_index < materials_number ; ++material_index)
        {
            const aiMaterial *material = materials[material_index];
            int texture_index = 0;
            aiString texture_name;

            // get each textures used by the material and insert it.
            while (material->GetTexture(aiTextureType_DIFFUSE, texture_index,
                        &texture_name) == AI_SUCCESS)
            {
                // WARNING potential problem with material sharing the same texture.
                this->m_resources.insert(std::make_pair(texture_name.data,
                            new Texture(texture_name.data)));
                ++texture_index;
            }
        }
    }

    TextureLibrary::TextureLibrary(const TextureLibrary &other) :
        Library<std::string, Texture *>()
    {
        for (const auto &key_value : other.m_resources)
        {
            this->m_resources.insert(
                    std::make_pair(key_value.first, new Texture(*key_value.second)));
        }
    }

    TextureLibrary::~TextureLibrary(void)
    {
        for (const auto &key_value : this->m_resources)
        {
             delete key_value.second;
        }
        // nothing to do.
    }



    TextureLibrary &
    TextureLibrary::operator=(const TextureLibrary &other)
    {
        for (const auto &resource : other.m_resources)
        {
            this->m_resources.insert(
                    std::make_pair(resource.first, new Texture(*resource.second)));
        }
        return *this;
    }

}
