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
#include    "Engine/Core/MaterialLibrary.hpp"
#include    "Engine/Core/Material.hpp"
#include    "Engine/Core/ShaderProgramLibrary.hpp"

using namespace     log4cpp;

namespace   Engine
{
    MaterialLibrary::MaterialLibrary(void) :
        Library<Material *>()
    {
        // nothing to do.
    }

    MaterialLibrary::MaterialLibrary(const ShaderProgramLibrary &shaderprograms,
            aiMaterial **assimpMaterials, unsigned int size, const TextureLibrary &texLib) :
        Library<Material *>()
    {
        Category& root = Category::getRoot();
        this->m_resources.reserve(size);
        for (unsigned int i = 0 ; i < size ; ++i)
        {
            const auto &shaderprogram = shaderprograms.get(TEXTURE_SHADER_PROGRAM);
	    root << Priority::DEBUG << "using texture shader";
            this->m_resources.push_back(new Material(assimpMaterials[i], shaderprogram, texLib));
        }
    }

    MaterialLibrary::MaterialLibrary(const MaterialLibrary &other) :
        Library<Material *>()
    {
        this->m_resources.reserve(other.m_resources.size());
        for (Material *resource : other.m_resources)
        {
            this->m_resources.push_back(new Material(*resource));
        }
    }

    MaterialLibrary::~MaterialLibrary(void)
    {
        for (Material *resource : this->m_resources)
        {
            delete resource;
        }
    }


    MaterialLibrary &
    MaterialLibrary::operator=(const MaterialLibrary &other)
    {
         this->m_resources.reserve(other.m_resources.size());
         for (Material *resource : other.m_resources)
         {
             this->m_resources.push_back(new Material(*resource));
         }
         return *this;
    }
}
