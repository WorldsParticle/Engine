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
        Library<Mesh *>()
    {
        // nothing to do.
    }

    MeshLibrary::MeshLibrary(const MaterialLibrary &materials,
            aiMesh **assimpMeshes, unsigned int size) :
        Library<Mesh *>()
    {
        Category    &root = Category::getRoot();

        root << Priority::DEBUG << "MeshLibrary constructor with size = " << size;
        this->resources.reserve(size);
        for (unsigned int i = 0 ; i < size ; ++i)
        {
            const aiMesh *amesh = assimpMeshes[i];
            Material *material = materials.get(amesh->mMaterialIndex);
            this->resources.push_back(new Mesh(amesh, material));
        }
    }

    MeshLibrary::MeshLibrary(const MeshLibrary &other) :
        Library<Mesh *>()
    {
        this->resources.reserve(other.resources.size());
        for (Mesh *resource : other.resources)
        {
             this->resources.push_back(new Mesh(*resource));
        }
    }

    MeshLibrary::~MeshLibrary(void)
    {
        for (Mesh *resource : this->resources)
        {
            delete resource;
        }
    }



    MeshLibrary &
    MeshLibrary::operator=(const MeshLibrary &other)
    {
         this->resources.reserve(other.resources.size());
         for (Mesh *resource : other.resources)
         {
             this->resources.push_back(new Mesh(*resource));
         }
         return *this;
    }
}
