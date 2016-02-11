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

#include    <iostream>
#include    <IL/il.h>
#include    <IL/ilu.h>
#include    <IL/ilut.h>
#include    "Engine/Core/Texture.hpp"

namespace   Engine
{
    Texture::Texture(void)
    {
	// nothing to do atm.
    }

    Texture::Texture(const aiTexture *assimpTexture)
    {
	// nothing to do atm.
    }

    Texture::Texture(GLuint id, const std::string &texturePath) : _name(texturePath), _id(id)
    {
	if (ilLoadImage(texturePath.c_str())) /* If no error occured: */
	{
	    // Convert every colour component into unsigned byte.If your image contains
	    // alpha channel you can replace IL_RGB with IL_RGBA
	    //success = ilConvertImage(IL_RGB, IL_UNSIGNED_BYTE);
	    if (!ilConvertImage(IL_RGB, IL_UNSIGNED_BYTE))
	    {
		// Error occured
		std::cout << "Couldn't convert image" << std::endl;
		return;
	    }
	    // Binding of texture name
	    glBindTexture(GL_TEXTURE_2D, _id);
	    // redefine standard texture values
	    // use linear interpolation for magnification filter
	    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	    // Texture specification
	    glTexImage2D(GL_TEXTURE_2D, 0, ilGetInteger(IL_IMAGE_FORMAT), ilGetInteger(IL_IMAGE_WIDTH),
	    ilGetInteger(IL_IMAGE_HEIGHT), 0, ilGetInteger(IL_IMAGE_FORMAT), GL_UNSIGNED_BYTE,
	    ilGetData());
	    // we also want to be able to deal with odd texture dimensions
	    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	    glPixelStorei(GL_UNPACK_ROW_LENGTH, 0);
	    glPixelStorei(GL_UNPACK_SKIP_PIXELS, 0);
	    glPixelStorei(GL_UNPACK_SKIP_ROWS, 0);
	}
	else
	{
	    /* Error occured */
	    std::cout << "ERROR: Couldn't load Image: " << _name << std::endl;;
	}
    }

    void Texture::bind(void)
    {
	glBindTexture(GL_TEXTURE_2D, _id);
    }

    Texture::~Texture(void)
    {
	// nothing to do atm.
    }
}
