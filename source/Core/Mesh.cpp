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

#include    "Mesh.hpp"

namespace   Engine
{
    Mesh::Mesh(Material *material) :
        m_name("default"),
        m_edges(),
        m_faces(),
        m_vertex(),
        m_material(material)
    {

    }

    Mesh::Mesh(const aiMesh *assimp_mesh, Material *material) :
        m_name(assimp_mesh->mName.C_Str()),
        m_edges(),
        m_faces(),
        m_vertex(),
        m_material(material)
    {

        for (unsigned int i_vertex ; i_vertex < assimp_mesh->mNumVertices ; ++i_vertex)
        {

        }

        for (unsigned int i_faces = 0 ; i_faces < assimp_mesh->mNumFaces ; ++i_faces)
        {
            const aiFace    *face = &assimp_mesh->mFaces[i_faces];

            this->m_faces[];

            for (unsigned int i_indices = 0 ; i_indices < face->mNumIndices ; ++i_indices)
            {
                face->mIndices[i_indices];
                face->mIndices[i_indices + 1];

                this->m_edges[];

            }
        }

    }
}
