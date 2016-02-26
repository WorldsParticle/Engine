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
	Library<std::pair<std::string, Texture *>>()
    {
	// nothing to do.
    }

    TextureLibrary::TextureLibrary(aiTexture **assimpTextures, unsigned int size) :
	Library<std::pair<std::string, Texture *>>()
    {
	this->m_resources.reserve(size);
	for (unsigned int i = 0 ; i < size ; ++i)
	{
	    this->m_resources.push_back(std::make_pair("", new Texture(assimpTextures[i])));
	}
    }

    TextureLibrary::TextureLibrary(const AssimpScene &assimpScene, const std::string &modelPath) :
	Library<std::pair<std::string, Texture *>>()
    {
	Category& root = Category::getRoot();

	if (assimpScene.getTexturesNumber() != 0)
	    root << Priority::DEBUG << "Support for meshes with embedded textures is not implemented";

	/* getTexture Filenames and Numb of Textures */
	aiMaterial **mat = assimpScene.getMaterials();;
	unsigned int numTextures = 0;
	std::vector<std::string> textureNames;
	for (unsigned int m=0; m<assimpScene.getMaterialsNumber(); m++)
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

	/* array with DevIL image IDs */
	ILuint* imageIds = nullptr;
	imageIds = new ILuint[numTextures];

	/* generate DevIL Image IDs */
	ilGenImages(numTextures, imageIds); /* Generation of numTextures image names */

	/* create and fill array with GL texture ids */
	GLuint*	    textureIds = new GLuint[numTextures];
	glGenTextures(numTextures, textureIds); /* Texture name generation */

	for (unsigned int i=0; i<numTextures; i++)
	{
	    //save IL image ID
	    std::string filename = modelPath + textureNames[i];  // get filename
	    ilBindImage(imageIds[i]); /* Binding of DevIL image name */
	    //std::string fileloc = RESOURCES_PATH + filename;  /* Loading of image */
	    root << Priority::DEBUG << "Texture: " << filename << " loaded";
	    Texture *tmp = new Texture(textureIds[i], filename); // save texture id for filename in map
	    m_resources.push_back(std::make_pair(textureNames[i], tmp));
	}
	// Because we have already copied image data into texture data  we can release memory used by image.
	ilDeleteImages(numTextures, imageIds);

	// Cleanup
	delete [] imageIds;
	imageIds = NULL;
    }

    TextureLibrary::TextureLibrary(const TextureLibrary &other) :
	Library<std::pair<std::string, Texture *>>()
    {
	this->m_resources.reserve(other.m_resources.size());
	for (std::pair<std::string, Texture *> resource : other.m_resources)
	{
	    this->m_resources.push_back(std::make_pair(resource.first, new Texture(*(resource.second))));
	}
    }

    TextureLibrary::~TextureLibrary(void)
    {
	// nothing to do.
    }

    void TextureLibrary::BindTexture(const std::string &name)
    {
	Texture *tmp = this->FindTexture(name);
	if (tmp != nullptr)
	{
	    tmp->bind();
	}
    }

    Texture *TextureLibrary::FindTexture(const std::string &name) const
    {
	for (std::pair<std::string, Texture *> resource : this->m_resources)
	{
	    if (name == resource.first)
	    {
		return resource.second;
	    }
	}
	return nullptr;
    }

    TextureLibrary &
	TextureLibrary::operator=(const TextureLibrary &other)
	{
	    this->m_resources.reserve(other.m_resources.size());
	    for (std::pair<std::string, Texture *> resource : other.m_resources)
	    {
		this->m_resources.push_back(std::make_pair(resource.first, new Texture(*(resource.second))));
	    }
	    return *this;
	}
}
