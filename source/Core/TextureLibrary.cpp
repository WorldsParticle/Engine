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
