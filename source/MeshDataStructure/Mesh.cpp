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

    void
    Mesh::build_connectivity(const aiMesh *ai_mesh)
    {
        const auto &vertices = this->build_vertices(ai_mesh->mVertices, ai_mesh->mNumVertices);
        const auto &faces = this->build_faces(ai_mesh->mFaces, ai_mesh->mNumFaces);
        const auto &edges = this->build_edges(ai_mesh->mFaces, ai_mesh->mNumFaces);
        const auto &edge_to_face = this->build_ordered_edge_to_face_map(ai_mesh->mFaces,
                ai_mesh->mNumFaces, faces);
        const auto &edge_to_half_edge = this->build_half_edges(edges, vertices, edge_to_face);
    }

    std::vector<Vertex *> &&
    Mesh::build_vertices(const aiVector3D *ai_vertices, unsigned int ai_vertices_number)
    {
        std::vector<Vertex *> vertices;

        vertices.reserve(ai_vertices_number);
        for (unsigned int i_vertex = 0 ; i_vertex < ai_vertices_number ; ++i_vertex)
        {
            const aiVector3D &ai_vertex = ai_vertices[i_vertex];
            Vertex *vertex = vertices[i_vertex] = this->build_vertex();
            vertex->position() = glm::vec3(ai_vertex.x, ai_vertex.y, ai_vertex.z);
        }
        return std::move(vertices);
    }

    std::vector<Face *> &&
    Mesh::build_faces(const aiFace *ai_faces, unsigned int ai_faces_number)
    {
        std::vector<Face *>     faces;

        faces.reserve(ai_faces_number);
        for (unsigned int i_faces = 0 ; i_faces < ai_faces_number ; ++i_faces)
        {
            faces[i_faces] = this->build_face();
        }
        return std::move(faces);
    }

    std::set<std::pair<std::size_t, std::size_t>> &&
    Mesh::build_edges(const aiFace *ai_faces, unsigned int ai_faces_number)
    {
        std::set<std::pair<std::size_t, std::size_t>> edges;

        for (unsigned int i_faces = 0 ; i_faces < ai_faces_number ; ++i_faces)
        {
            const aiFace &face = ai_faces[i_faces];
            edges.insert(std::make_pair(std::min(face.mIndices[0], face.mIndices[1]), std::max(face.mIndices[0], face.mIndices[1])));
            edges.insert(std::make_pair(std::min(face.mIndices[1], face.mIndices[2]), std::max(face.mIndices[1], face.mIndices[2])));
            edges.insert(std::make_pair(std::min(face.mIndices[2], face.mIndices[0]), std::max(face.mIndices[2], face.mIndices[0])));
        }
        return std::move(edges);
    }

    std::map<std::pair<std::size_t, std::size_t>, Face *> &&
    Mesh::build_ordered_edge_to_face_map(
            const aiFace *ai_faces, unsigned int ai_faces_number,
            const std::vector<Face *> &faces)
    {
        std::map<std::pair<std::size_t, std::size_t>, Face *>   ordered_edge_to_face_map;
        auto check_and_insert = [&](std::size_t index1, std::size_t index2, Face *value) {
            const auto &key = std::make_pair(index1, index2);
            if (ordered_edge_to_face_map.count(key) == 1) {
                std::cerr << "Inconsistency in the mesh, an edge share two different face.\n"
                    << "edge : " << key.first << " => " << key.second << std::endl;
            }
            ordered_edge_to_face_map[key] = value;
        };

        for (unsigned int i_faces = 0 ; i_faces < ai_faces_number ; ++i_faces)
        {
            const aiFace &face = ai_faces[i_faces];
            check_and_insert(face.mIndices[0], face.mIndices[1], faces[i_faces]);
            check_and_insert(face.mIndices[1], face.mIndices[2], faces[i_faces]);
            check_and_insert(face.mIndices[2], face.mIndices[0], faces[i_faces]);
        }
        return std::move(ordered_edge_to_face_map);
    }

    std::map<std::pair<std::size_t, std::size_t>, HalfEdge *> &&
    Mesh::build_half_edges(const std::set<std::pair<std::size_t, std::size_t>> &edges,
            const std::vector<Vertex *> &vertices,
            const std::map<std::pair<std::size_t, std::size_t>, Face *> &ordered_edge_to_face_map)
    {
        std::map<std::pair<std::size_t, std::size_t>, HalfEdge *> ordered_edge_to_half_edge_map;

        for (const std::pair<std::size_t, std::size_t> &edge : edges)
        {
            HalfEdge    *he1 = this->build_half_edge();
            HalfEdge    *he2 = this->build_half_edge();

            const auto &key_he1 = std::make_pair(edge.first, edge.second);
            const auto &key_he2 = std::make_pair(edge.second, edge.first);

            he1->face() = ordered_edge_to_face_map.at(key_he1);
            he2->face() = ordered_edge_to_face_map.at(key_he2);

            ordered_edge_to_half_edge_map[key_he1] = he1;
            ordered_edge_to_half_edge_map[key_he2] = he2;

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
        return std::move(ordered_edge_to_half_edge_map);
    }

    void
    Mesh::build_half_edge_connectivity(const aiMesh *assimp_mesh)
    {
        std::list<HalfEdge *>   boundary_half_edge_list;

        for (HalfEdge &half_edge : this->m_half_edges)
        {

            if (half_edge.face() == nullptr) // we have a boundary half_edge
            {
                // we will set the next component after.
                boundary_half_edge_list.push_back(&half_edge);
                continue;
            }


            half_edge.next() = nullptr;
            // I must set the next component of the half_edge.

        }
    }

    void
    Mesh::build_boundary_half_edge_connectivity(void)
    {

    }



    HalfEdge *
    Mesh::build_half_edge(void)
    {
        auto it = this->m_half_edges.emplace(this->m_half_edges.end());
        (*it).iterator() = it;
        return &(*it);
    }

    Vertex *
    Mesh::build_vertex(void)
    {
        auto it = this->m_vertices.emplace(this->m_vertices.end());
        (*it).iterator() = it;
        return &(*it);
    }

    Face *
    Mesh::build_face(void)
    {
        auto it = this->m_faces.emplace(this->m_faces.end());
        (*it).iterator() = it;
        return &(*it);
    }

}
