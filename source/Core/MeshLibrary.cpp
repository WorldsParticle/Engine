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

#include    "Engine/Core/MeshLibrary.hpp"
#include    "Engine/Core/MaterialLibrary.hpp"

using namespace     log4cpp;

namespace   Engine
{
    MeshLibrary::MeshLibrary(void) :
        Library<unsigned int, Mesh *>()
    {
        // nothing to do.
    }

    MeshLibrary::MeshLibrary(const MaterialLibrary &materials,
            aiMesh **assimpMeshes, unsigned int size) :
        Library<unsigned int, Mesh *>()
    {
        Category    &root = Category::getRoot();

        root << Priority::DEBUG << "MeshLibrary constructor with size = " << size;
        for (unsigned int i = 0 ; i < size ; ++i)
        {
            const aiMesh *amesh = assimpMeshes[i];
            Material *material = materials.get(amesh->mMaterialIndex);
            this->m_resources.insert(std::make_pair(i,
                        new Mesh(amesh, material)));
        }
    }

    MeshLibrary::MeshLibrary(const MeshLibrary &other) :
        Library<unsigned int, Mesh *>()
    {
        for (const auto &key_value : other.m_resources)
        {
            this->m_resources.insert(std::make_pair(key_value.first,
                        new Mesh(*key_value.second)));
        }
    }

    MeshLibrary::~MeshLibrary(void)
    {
        for (const auto &key_value : this->m_resources)
        {
            delete key_value.second;
        }
    }



    MeshLibrary &
    MeshLibrary::operator=(const MeshLibrary &other)
    {
        for (const auto &key_value : other.m_resources)
        {
            this->m_resources.insert(std::make_pair(key_value.first,
                        new Mesh(*key_value.second)));
        }
        return *this;
    }
    
    void    MeshLibrary::appendMeshes(const MaterialLibrary &materials,
            aiMesh **assimpMeshes, unsigned int size)
    {
        Category    &root = Category::getRoot();

        unsigned int previousSize = static_cast<unsigned int>(this->m_resources.size());
        root << Priority::DEBUG << "appendMeshes with size = " << size << " to previous size " << previousSize;
        
        for (unsigned int i = 0 ; i < size ; ++i)
        {
            const aiMesh *amesh = assimpMeshes[i];
            Material *material = materials.get(amesh->mMaterialIndex);
            root << Priority::DEBUG << "append key = " << i + previousSize << " and mesh " << new Mesh(amesh, material);
            this->m_resources.insert(std::make_pair(i + previousSize,
                        new Mesh(amesh, material)));
        }
    }

}
