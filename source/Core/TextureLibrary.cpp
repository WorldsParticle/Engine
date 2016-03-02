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

    TextureLibrary::TextureLibrary(const AssimpScene &assimpScene,
            const std::string &modelPath) :
        Library<std::string, Texture *>()
    {
        aiMaterial **mat = assimpScene.getMaterials();;
        unsigned int numTextures = 0;
        std::vector<std::string> textureNames;
        for (unsigned int m = 0 ; m < assimpScene.getMaterialsNumber(); m++)
        {
            int texIndex = 0;
            aiReturn texFound = AI_SUCCESS;

            aiString path;  // filename

            while (texFound == AI_SUCCESS)
            {
                texFound = mat[m]->GetTexture(aiTextureType_DIFFUSE, texIndex, &path);
                numTextures++;
                textureNames.push_back(path.data);
                texIndex++;
            }
        }

        for (unsigned int i = 0; i < numTextures ; ++i)
        {
            std::string filename = modelPath + textureNames[i];  // get filename
            //std::string fileloc = RESOURCES_PATH + filename;  /* Loading of image */
            //root << Priority::DEBUG << "Texture: " << filename << " loaded";
            this->m_resources.insert(std::make_pair(textureNames[i],
                        new Texture(filename)));
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
