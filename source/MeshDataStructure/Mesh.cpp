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

#include    <GL/glew.h>
#include    <iostream>

#include    "Engine/Core/Material.hpp"
#include    "Engine/Core/ShaderProgram.hpp"
#include    "Engine/MeshDataStructure/Mesh.hpp"

namespace   Engine
{
    using Edge = std::pair<Vertex *, Vertex *>;
    using FaceVertices = std::tuple<Vertex *, Vertex *, Vertex *>;

    Mesh::Mesh(Material *material) :
        m_name("DefaultMesh"),
        m_half_edges(),
        m_faces(),
        m_vertices(),
        m_vertices_buffer(std::make_shared<BufferObject>(BufferObject::Type::ARRAY_BUFFER, BufferObject::Usage::DYNAMIC_DRAW)),
        m_elements_buffer(std::make_shared<BufferObject>(BufferObject::Type::ELEMENT_ARRAY_BUFFER, BufferObject::Usage::DYNAMIC_DRAW)),
        m_array_object(std::make_shared<ArrayObject>()),
        m_material(material),
        m_dirty(true)
    {
        this->update_vao();
    }

    Mesh::Mesh(const aiMesh *assimp_mesh, Material *material) :
        m_name(assimp_mesh->mName.C_Str()),
        m_half_edges(),
        m_faces(),
        m_vertices(),
        m_vertices_buffer(std::make_shared<BufferObject>(BufferObject::Type::ARRAY_BUFFER, BufferObject::Usage::DYNAMIC_DRAW)),
        m_elements_buffer(std::make_shared<BufferObject>(BufferObject::Type::ELEMENT_ARRAY_BUFFER, BufferObject::Usage::DYNAMIC_DRAW)),
        m_array_object(std::make_shared<ArrayObject>()),
        m_material(material),
        m_dirty(true)
    {
        this->build_connectivity(assimp_mesh);
        this->update_vao();
    }

    Mesh::~Mesh(void) noexcept
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
    Mesh::collapse(Vertex *v1, Vertex *v2)
    {
        // 1) recuperer le half edge entre les deux, ou return.
        // 2) creer un autre vertex
        //
        // POSER SUR PAPIER EXACTEMENT TOUT LES EDGE A UDPATE.
        //
    }

    void
    Mesh::draw(const glm::mat4 &model, const glm::mat4 &view, const glm::mat4 &projection)
    {
        if (this->is_dirty())
        {
             this->update();
        }
        const auto &shaderprogram = this->m_material->getShaderProgram();
        this->m_array_object->bind();
        this->m_material->bind();
        shaderprogram->setUniform("model", model);
        shaderprogram->setUniform("view", view);
        shaderprogram->setUniform("projection", projection);
        glDrawArrays(GL_TRIANGLES, 0, static_cast<int>(this->m_faces.size() * 3));
        this->m_material->unbind();
        this->m_array_object->unbind();
    }

    void
    Mesh::update(void)
    {
        std::vector<float>  vertices;

        vertices.reserve(this->m_faces.size() * 3 * 9);
        for (Face &face : this->m_faces)
        {
            auto face_vertices = face.vertices();
            if (face_vertices.size() != 3)
            {
                throw std::runtime_error("Inconsistency in the datastructure");
            }
            glm::vec3 normal = face.normal();
            for (Vertex *vertex : face_vertices)
            {
                vertices.push_back(vertex->position().x);
                vertices.push_back(vertex->position().y);
                vertices.push_back(vertex->position().z);
                vertices.push_back(normal.x);
                vertices.push_back(normal.y);
                vertices.push_back(normal.z);
                vertices.push_back(face.color().x);
                vertices.push_back(face.color().y);
                vertices.push_back(face.color().z);
            }
        }
        std::cerr << "Number of elements in the vertices_buffer : " << vertices.size() << std::endl;
        this->m_vertices_buffer->update(vertices.data(), vertices.size() * sizeof(float));
        this->m_dirty = false;
    }

    void
    Mesh::update_vao(void)
    {
        this->m_array_object->bind();
        this->m_vertices_buffer->bind();
        glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);
        glEnableVertexAttribArray(2);
        std::uintptr_t pointer_offset = 0;
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), reinterpret_cast<void *>(pointer_offset));
        pointer_offset += 3 * sizeof(float);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), reinterpret_cast<void *>(pointer_offset));
        pointer_offset += 3 * sizeof(float);
        glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), reinterpret_cast<void *>(pointer_offset));
        this->m_array_object->unbind();
        this->m_vertices_buffer->unbind();
    }

    bool
    Mesh::is_dirty(void) const
    {
        return this->m_dirty;
    }

    void
    Mesh::build_connectivity(const aiMesh *ai_mesh)
    {
        const auto &vertices = this->build_vertices(ai_mesh->mVertices, ai_mesh->mNumVertices);
        const auto &faces = this->build_faces(ai_mesh->mNumFaces);
        const auto &edges = this->build_edges(ai_mesh->mFaces, ai_mesh->mNumFaces, vertices);
        const auto &edge_to_face = this->build_ordered_edge_to_face_map(ai_mesh->mFaces,
                ai_mesh->mNumFaces, faces, vertices);
        const auto &edge_to_half_edge = this->build_half_edges(edges, edge_to_face);
        const auto &faces_to_vertices = this->build_face_to_vertices(ai_mesh->mFaces,
                ai_mesh->mNumFaces, faces, vertices);
        this->build_half_edge_connectivity(faces_to_vertices, edge_to_half_edge);
        this->m_dirty = true;
    }

    std::vector<Vertex *>
    Mesh::build_vertices(const aiVector3D *ai_vertices, unsigned int ai_vertices_number)
    {
        std::vector<Vertex *> vertices;

        vertices.reserve(ai_vertices_number);
        for (unsigned int i_vertex = 0 ; i_vertex < ai_vertices_number ; ++i_vertex)
        {
            const aiVector3D &ai_vertex = ai_vertices[i_vertex];
            Vertex *vertex = &this->build_vertex();
            vertices.push_back(vertex);
            vertex->position() = glm::vec3(ai_vertex.x, ai_vertex.y, ai_vertex.z);
        }
        std::cerr << vertices.size() << std::endl;
        return vertices;
    }

    std::vector<Face *>
    Mesh::build_faces(unsigned int ai_faces_number)
    {
        std::vector<Face *>     faces;

        faces.reserve(ai_faces_number);
        for (unsigned int i_faces = 0 ; i_faces < ai_faces_number ; ++i_faces)
        {
            faces.push_back(&this->build_face());
        }
        return faces;
    }

    std::set<Edge>
    Mesh::build_edges(const aiFace *ai_faces, unsigned int ai_faces_number,
            const std::vector<Vertex *> &vertices)
    {
        std::set<Edge> edges;
        auto edges_insert = [&](std::size_t index1, std::size_t index2) {
            const auto &start = std::min(index1, index2);
            const auto &end = std::max(index1, index2);
            edges.insert(std::make_pair(vertices[start], vertices[end]));
        };

        for (unsigned int i_faces = 0 ; i_faces < ai_faces_number ; ++i_faces)
        {
            const aiFace &face = ai_faces[i_faces];
            edges_insert(face.mIndices[0], face.mIndices[1]);
            edges_insert(face.mIndices[1], face.mIndices[2]);
            edges_insert(face.mIndices[2], face.mIndices[0]);
        }
        return edges;
    }

    std::map<Edge, Face *>
    Mesh::build_ordered_edge_to_face_map(
            const aiFace *ai_faces, unsigned int ai_faces_number,
            const std::vector<Face *> &faces,
            const std::vector<Vertex *> &vertices)
    {
        std::map<Edge, Face *>  ordered_edge_to_face_map;
        auto check_and_insert = [&](std::size_t index1, std::size_t index2, Face *value) {
            const auto &key = std::make_pair(vertices[index1], vertices[index2]);
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
        return ordered_edge_to_face_map;
    }

    std::map<Edge, HalfEdge *>
    Mesh::build_half_edges(const std::set<Edge> &edges,
            const std::map<Edge, Face *> &ordered_edge_to_face_map)
    {
        std::map<Edge, HalfEdge *>  ordered_edge_to_half_edge_map;
        auto find_face_or_nullptr = [&](const auto &key) -> Face * {
            auto it = ordered_edge_to_face_map.find(key);
            if (it != ordered_edge_to_face_map.end())
                return (*it).second;
           return nullptr;
        };

        std::cerr << ordered_edge_to_face_map.size() << std::endl;
        for (const Edge &edge : edges)
        {
            HalfEdge    *he1 = &this->build_half_edge();
            HalfEdge    *he2 = &this->build_half_edge();

            const auto &key_he1 = std::make_pair(edge.first, edge.second);
            const auto &key_he2 = std::make_pair(edge.second, edge.first);

            he1->face() = find_face_or_nullptr(key_he1);
            he2->face() = find_face_or_nullptr(key_he2);

            ordered_edge_to_half_edge_map[key_he1] = he1;
            ordered_edge_to_half_edge_map[key_he2] = he2;

            he1->vertex() = edge.second;
            he2->vertex() = edge.first;

            he1->pair() = he2;
            he2->pair() = he1;

            if (he1->vertex()->half_edge() == nullptr || he2->face() == nullptr)
                he1->vertex()->half_edge() = he1->pair();
            if (he2->vertex()->half_edge() == nullptr || he1->face() == nullptr)
                he2->vertex()->half_edge() = he2->pair();

            if (he1->face() != nullptr && he1->face()->half_edge() == nullptr)
                he1->face()->half_edge() = he1;
            if (he2->face() != nullptr && he2->face()->half_edge() == nullptr)
                he2->face()->half_edge() = he2;
        }
        return ordered_edge_to_half_edge_map;
    }

    std::map<Face *, FaceVertices>
    Mesh::build_face_to_vertices(const aiFace *ai_faces,
            unsigned int ai_faces_number,
            const std::vector<Face *> &faces,
            const std::vector<Vertex *> &vertices)
    {
        std::map<Face *, FaceVertices>  face_to_vertices;

        for (unsigned int i_faces = 0 ; i_faces < ai_faces_number ; ++i_faces)
        {
            const aiFace &ai_face = ai_faces[i_faces];
            face_to_vertices[faces[i_faces]] = std::tie(vertices[ai_face.mIndices[0]],
                    vertices[ai_face.mIndices[1]], vertices[ai_face.mIndices[2]]);
        }
        return face_to_vertices;
    }

    void
    Mesh::build_half_edge_connectivity(
            const std::map<Face *, FaceVertices> &faces_to_vertices,
            const std::map<Edge, HalfEdge *> &ordered_edge_to_half_edge)
    {
        std::list<HalfEdge *>   boundary_half_edge_list;

        for (HalfEdge &half_edge : this->m_half_edges)
        {
            // we have a boundary half_edge
            if (half_edge.face() == nullptr)
            {
                // we will set the next component after.
                boundary_half_edge_list.push_back(&half_edge);
                continue;
            }

            Vertex *start = half_edge.vertex();
            Vertex *end = nullptr;

            const auto &face_vertices = faces_to_vertices.at(half_edge.face());

            if (std::get<0>(face_vertices) == start)
                end = std::get<1>(face_vertices);
            else if (std::get<1>(face_vertices) == start)
                end = std::get<2>(face_vertices);
            else if (std::get<2>(face_vertices) == start)
                end = std::get<0>(face_vertices);
            else
                throw std::runtime_error("Datastructure inconsistency.");

            const auto &key = std::make_pair(start, end);
            half_edge.next() = ordered_edge_to_half_edge.at(key);
        }
        this->build_half_edge_boundary_connectivity(boundary_half_edge_list);
    }

    void
    Mesh::build_half_edge_boundary_connectivity(
            const std::list<HalfEdge *> &boundary_half_edges)
    {
        for (HalfEdge *half_edge : boundary_half_edges)
        {
            if (half_edge->vertex()->half_edge()->is_boundary() == false)
            {
                throw std::runtime_error("boundary half_edge pointing to a vertex without a boundary vertex outgoing");
            }
            half_edge->next() = half_edge->vertex()->half_edge();
        }
    }

    HalfEdge &
    Mesh::build_half_edge(void)
    {
        auto it = this->m_half_edges.emplace(this->m_half_edges.end());
        (*it).iterator() = it;
        return *it;
    }

    Vertex &
    Mesh::build_vertex(void)
    {
        auto it = this->m_vertices.emplace(this->m_vertices.end());
        (*it).iterator() = it;
        return *it;
    }

    Face &
    Mesh::build_face(void)
    {
        auto it = this->m_faces.emplace(this->m_faces.end());
        (*it).iterator() = it;
        return *it;
    }

}
