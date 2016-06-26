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

#include    <log4cpp/Category.hh>
#include    <IL/il.h>
#include    <IL/ilu.h>
#include    <IL/ilut.h>
#include    <GL/gl.h>

#include    "Engine/Configuration.hpp"
#include    "Engine/Core/Texture.hpp"

using namespace     log4cpp;

namespace   Engine
{

    Texture::Texture(void) :
        m_name("Default"),
        m_id(0)
    {
        glGenTextures(1, &this->m_id);
        // nothing to do atm.
    }

    Texture::Texture(const aiTexture *assimpTexture) :
        m_name("HEY"),
        m_id(0)
    {
        if (assimpTexture == assimpTexture)
        {
            // UNUSED VARIABLE
        }
        glGenTextures(1, &this->m_id);
        // nothing to do atm.
    }

    Texture::Texture(const std::string &texture_name) :
        m_name(texture_name),
        m_id()
    {
        Category& root = Category::getRoot();
        unsigned int    devil_id;

        glGenTextures(1, &this->m_id);
        ilGenImages(1, &devil_id);

        ilBindImage(devil_id);
        /* If no error occured: */
        if (ilLoadImage((RESOURCES_PATH "/textures/" + texture_name).c_str()))
        {
            // Convert every colour component into unsigned byte.If your image contains
            // alpha channel you can replace IL_RGB with IL_RGBA
            //success = ilConvertImage(IL_RGB, IL_UNSIGNED_BYTE);
            if (!ilConvertImage(IL_RGB, IL_UNSIGNED_BYTE))
            {
                // Error occured
                root << Priority::ERROR << "Couldn't convert image " << m_name;
                return;
            }
            // Binding of texture name
            glBindTexture(GL_TEXTURE_2D, this->m_id);
            root << Priority::DEBUG << "Texture " << m_name << " " << m_id << " created";

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
            root << Priority::ERROR << "Couldn't load image: " << m_name;
        }
        ilDeleteImages(1, &devil_id);
    }

    Texture::~Texture(void)
    {
        glDeleteTextures(1, &this->m_id);
    }



    void Texture::bind(void)
    {
        glBindTexture(GL_TEXTURE_2D, this->m_id);
    }

    void
    Texture::unbind(void)
    {
        glBindTexture(GL_TEXTURE_2D, 0);
    }

}
