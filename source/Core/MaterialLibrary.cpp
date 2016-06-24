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
        Library<unsigned int, Material *>()
    {
        // nothing to do.
    }

    MaterialLibrary::MaterialLibrary(const ShaderProgramLibrary &shaderprograms,
            aiMaterial **ai_materials, unsigned int size,
            const TextureLibrary &texture_library) :
        Library<unsigned int, Material *>()
    {
        Category& root = Category::getRoot();

        for (unsigned int i = 0 ; i < size ; ++i)
        {
            const auto &shaderprogram = shaderprograms.get(TEXTURE_SHADER_PROGRAM);
            root << Priority::DEBUG << "using texture shader";
            this->m_resources.insert(std::make_pair(i,
                        new Material(ai_materials[i], shaderprogram,
                            texture_library)));
        }
    }

    MaterialLibrary::MaterialLibrary(const MaterialLibrary &other) :
        Library<unsigned int, Material *>()
    {
        for (const auto &key_value : other.m_resources)
        {
            this->m_resources.insert(
                    std::make_pair(key_value.first,
                        new Material(*key_value.second)));
        }
    }

    MaterialLibrary::~MaterialLibrary(void)
    {
        for (const auto &key_value : this->m_resources)
        {
            delete key_value.second;
        }
    }


    MaterialLibrary &
    MaterialLibrary::operator=(const MaterialLibrary &other)
    {
        for (const auto &key_value : other.m_resources)
        {
            this->m_resources.insert(
                    std::make_pair(key_value.first,
                        new Material(*key_value.second)));
        }
        return *this;
    }
    template<>
    void Library<unsigned int, Material*>::append(const Library<unsigned int, Material*> &other)
    {
        unsigned int previousSize = this->getSize();
        for (const auto &key_value : other.m_resources)
        {
        	this->m_resources.insert(
			std::make_pair(key_value.first + previousSize,
			    new Material(*key_value.second)));
        }
    }
}
