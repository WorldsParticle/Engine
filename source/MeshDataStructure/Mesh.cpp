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

#include    "Engine/MeshDataStructure/Mesh.hpp"

namespace   Engine
{
    Mesh::Mesh(Material *material) :
        m_name("DefaultMesh"),
        m_half_edges(),
        m_faces(),
        m_vertices(),
        m_vertices_buffer(std::make_shared<BufferObject>(BufferObject::Type::ARRAY_BUFFER, BufferObject::Usage::DYNAMIC_DRAW)),
        m_elements_buffer(std::make_shared<BufferObject>(BufferObject::Type::ELEMENT_ARRAY_BUFFER, BufferObject::Usage::DYNAMIC_DRAW)),
        m_array_object(std::make_shared<ArrayObject>()),
        m_material(material)
    {

    }

    Mesh::Mesh(const aiMesh *assimp_mesh, Material *material) :
        m_name(assimp_mesh->mName.C_Str()),
        m_half_edges(),
        m_faces(),
        m_vertices(),
        m_vertices_buffer(std::make_shared<BufferObject>(BufferObject::Type::ARRAY_BUFFER, BufferObject::Usage::DYNAMIC_DRAW)),
        m_elements_buffer(std::make_shared<BufferObject>(BufferObject::Type::ELEMENT_ARRAY_BUFFER, BufferObject::Usage::DYNAMIC_DRAW)),
        m_array_object(std::make_shared<ArrayObject>()),
        m_material(material)
    {
        //std::set<std::pair<unsigned int, unsigned int>>   edges;

        //this->build_edge(assimp_mesh);

        // list de face avec des int => faces

        // Face && Vertex && Edge.

    }

    Mesh::~Mesh(void) noexcept
    {
    }



    void
    Mesh::draw(const glm::mat4 &model, const glm::mat4 &view, const glm::mat4 &projection)
    {
    }

    void
    Mesh::increase(void)
    {
    }

    void
    Mesh::reduce(void)
    {
    }


    std::vector<Vertex *> &&
    Mesh::build_vertices(const aiMesh *assimp_mesh)
    {
        std::vector<Vertex *> vertices;

        vertices.reserve(assimp_mesh->mNumVertices);
        for (unsigned int i_vertex = 0 ; i_vertex < assimp_mesh->mNumVertices ; ++i_vertex)
        {
            auto it = this->m_vertices.emplace(this->m_vertices.end());
            (*it).iterator() = it;
            vertices[i_vertex] = &(*it);
        }
        return std::move(vertices);
    }

    std::vector<Face *> &&
    Mesh::build_faces(const aiMesh *assimp_mesh)
    {
        std::vector<Face *>     faces;

        faces.reserve(assimp_mesh->mNumFaces);
        for (unsigned int i_faces = 0 ; i_faces < assimp_mesh->mNumFaces ; ++i_faces)
        {
            auto it = this->m_faces.emplace(this->m_faces.end());
            (*it).iterator() = it;
            faces[i_faces] = &(*it);
        }
        return std::move(faces);
    }

    std::set<std::pair<std::size_t, std::size_t>> &&
    Mesh::build_edges(const aiMesh *assimp_mesh)
    {
        std::set<std::pair<std::size_t, std::size_t>> edges;

        for (unsigned int i_faces = 0 ; i_faces < assimp_mesh->mNumFaces ; ++i_faces)
        {
            const aiFace &assimp_face = assimp_mesh->mFaces[i_faces];
            edges.insert(std::make_pair(std::min(assimp_face.mIndices[0], assimp_face.mIndices[1]), std::max(assimp_face.mIndices[0], assimp_face.mIndices[1])));
            edges.insert(std::make_pair(std::min(assimp_face.mIndices[1], assimp_face.mIndices[2]), std::max(assimp_face.mIndices[1], assimp_face.mIndices[2])));
            edges.insert(std::make_pair(std::min(assimp_face.mIndices[2], assimp_face.mIndices[0]), std::max(assimp_face.mIndices[2], assimp_face.mIndices[0])));
        }
        return std::move(edges);
    }

    std::map<std::pair<std::size_t, std::size_t>, Face *> &&
    Mesh::build_ordered_edge_to_face_map(const aiMesh *assimp_mesh, const std::vector<Face *> &faces)
    {
        std::map<std::pair<std::size_t, std::size_t>, Face *>   ordered_edge_to_face_map;

        for (unsigned int i_faces = 0 ; i_faces < assimp_mesh->mNumFaces ; ++i_faces)
        {
            const aiFace &assimp_face = assimp_mesh->mFaces[i_faces];
            ordered_edge_to_face_map[std::make_pair(assimp_face.mIndices[0], assimp_face.mIndices[1])] = faces[i_faces];
            ordered_edge_to_face_map[std::make_pair(assimp_face.mIndices[1], assimp_face.mIndices[2])] = faces[i_faces];
            ordered_edge_to_face_map[std::make_pair(assimp_face.mIndices[2], assimp_face.mIndices[0])] = faces[i_faces];
        }
        return std::move(ordered_edge_to_face_map);
    }

    void
    Mesh::build_connectivity(const std::set<std::pair<std::size_t, std::size_t>> &edges,
            const std::vector<Vertex *> &vertices, const std::vector<Face *> &faces,
            const std::map<std::pair<std::size_t, std::size_t>, Face *> &ordered_edge_to_face_map)
    {
        for (const std::pair<std::size_t, std::size_t> &edge : edges)
        {
            HalfEdge    *he1 = this->build_half_edge();
            HalfEdge    *he2 = this->build_half_edge();

            he1->face() = ordered_edge_to_face_map.at(std::make_pair(edge.first, edge.second));
            he2->face() = ordered_edge_to_face_map.at(std::make_pair(edge.second, edge.first));

            he1->vertex() = vertices[edge.second];
            he2->vertex() = vertices[edge.first];

            he1->pair() = he2;
            he2->pair() = he1;

            if (he1->vertex()->half_edge() == nullptr || he1->face() == nullptr)
                he1->vertex()->half_edge() = he1->pair();
            if (he2->vertex()->half_edge() == nullptr || he2->face() == nullptr)
                he2->vertex()->half_edge() = he2->pair();

            if (he1->face() != nullptr && he1->face()->half_edge() == nullptr)
                he1->face()->half_edge() = he1;
            if (he2->face() != nullptr && he2->face()->half_edge() == nullptr)
                he2->face()->half_edge() = he2;
        }
    }

    HalfEdge *
    Mesh::build_half_edge(void)
    {
        auto it = this->m_half_edges.emplace(this->m_half_edges.end());
        (*it).iterator() = it;
        return &(*it);
    }

}
