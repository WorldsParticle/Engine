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

#include <iostream>
#include    <IL/il.h>
#include    <IL/ilu.h>
#include    <IL/ilut.h>
#include    "Engine/Core/TextureLibrary.hpp"

namespace   Engine
{
    TextureLibrary::TextureLibrary(void) :
        Library<Texture *>()
    {
        // nothing to do.
    }

    TextureLibrary::TextureLibrary(aiTexture **assimpTextures, unsigned int size) :
        Library<Texture *>()
    {
        this->m_resources.reserve(size);
        for (unsigned int i = 0 ; i < size ; ++i)
        {
            this->m_resources.push_back(new Texture(assimpTextures[i]));
        }
    }

    TextureLibrary::TextureLibrary(const AssimpScene &assimpScene)
    {
	ilInit(); /* Initialization of DevIL */

	if (assimpScene.getTexturesNumber() != 0)
	    std::cout <<"Support for meshes with embedded textures is not implemented" << std::endl;

	/* getTexture Filenames and Numb of Textures */
	aiMaterial **mat = assimpScene.getMaterials();;
	for (unsigned int m=0; m<assimpScene.getMaterialsNumber(); m++)
	{
	    int texIndex = 0;
	    aiReturn texFound = AI_SUCCESS;

	    aiString path;  // filename

	    while (texFound == AI_SUCCESS)
	    {
		texFound = mat[m]->GetTexture(aiTextureType_DIFFUSE, texIndex, &path);
		_textureMap[path.data] = NULL; //fill map with textures, pointers still NULL yet
		texIndex++;
	    }
	}

	int numTextures = _textureMap.size();

	/* array with DevIL image IDs */
	ILuint* imageIds = NULL;
	imageIds = new ILuint[numTextures];

	/* generate DevIL Image IDs */
	ilGenImages(numTextures, imageIds); /* Generation of numTextures image names */

	/* create and fill array with GL texture ids */
	GLuint*	    textureIds = new GLuint[numTextures];
	glGenTextures(numTextures, textureIds); /* Texture name generation */

	/* get iterator */
	std::map<std::string, Texture*>::iterator itr = _textureMap.begin();

	for (int i=0; i<numTextures; i++)
	{
	    //save IL image ID
	    std::string filename = (*itr).first;  // get filename
	    ilBindImage(imageIds[i]); /* Binding of DevIL image name */
	    //std::string fileloc = /*RESOURCES_PATH*/ filename;  /* Loading of image */
	    (*itr).second = new Texture(textureIds[i], filename);//&textureIds[i];      // save texture id for filename in map
	    itr++;				      // next texture
	}
	// Because we have already copied image data into texture data  we can release memory used by image.
	ilDeleteImages(numTextures, imageIds);

	// Cleanup
	delete [] imageIds;
	imageIds = NULL;
    }

    TextureLibrary::TextureLibrary(const TextureLibrary &other) :
        Library<Texture *>()
    {
        this->m_resources.reserve(other.m_resources.size());
        for (Texture *resource : other.m_resources)
        {
            this->m_resources.push_back(new Texture(*resource));
        }
    }

    TextureLibrary::~TextureLibrary(void)
    {
        // nothing to do.
    }

    void TextureLibrary::BindTexture(const std::string &name)
    {
	if (_textureMap.find(name) != _textureMap.end())
	{
	    _textureMap[name]->bind();
	}
    }

    Texture *TextureLibrary::FindTexture(const std::string &name) const
    {
	if (_textureMap.find(name) != _textureMap.end())
	{
	    //Texture *tmp = _textureMap[_textureMap.find(name)];
	    return _textureMap.find(name)->second;
	}
	return NULL;
    }

    TextureLibrary &
    TextureLibrary::operator=(const TextureLibrary &other)
    {
         this->m_resources.reserve(other.m_resources.size());
         for (Texture *resource : other.m_resources)
         {
             this->m_resources.push_back(new Texture(*resource));
         }
         return *this;
    }
}
