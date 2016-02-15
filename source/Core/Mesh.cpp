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

#include    "Engine/Core/Mesh.hpp"
#include    "Engine/Core/Material.hpp"
#include    "Engine/Core/ShaderProgram.hpp"

namespace   Engine
{

    Mesh::Mesh(Material *material) :
        m_name("default"),
        m_dirty(true),
        m_edges(),
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
        m_dirty(true),
        m_edges(),
        m_faces(),
        m_vertices(),
        m_vertices_buffer(std::make_shared<BufferObject>(BufferObject::Type::ARRAY_BUFFER, BufferObject::Usage::DYNAMIC_DRAW)),
        m_elements_buffer(std::make_shared<BufferObject>(BufferObject::Type::ELEMENT_ARRAY_BUFFER, BufferObject::Usage::DYNAMIC_DRAW)),
        m_array_object(std::make_shared<ArrayObject>()),
        m_material(material)
    {

        std::vector<Vertex *>   temporary_vertices;
        temporary_vertices.reserve(assimp_mesh->mNumVertices);

        for (unsigned int i_vertex = 0 ; i_vertex < assimp_mesh->mNumVertices ; ++i_vertex)
        {
            const aiVector3D *vertex = &assimp_mesh->mVertices[i_vertex];
            std::list<Vertex>::iterator it = this->m_vertices.emplace(this->m_vertices.end(),
                    glm::vec3(vertex->x, vertex->y, vertex->z),
                    glm::vec3(0.0f, 0.0f, 0.0f));
            temporary_vertices[i_vertex] = &(*it);
            temporary_vertices[i_vertex]->iterator = it;
        }

        for (unsigned int i_faces = 0 ; i_faces < assimp_mesh->mNumFaces ; ++i_faces)
        {
            const aiFace    *assimp_face = &assimp_mesh->mFaces[i_faces];

            if (assimp_face->mNumIndices != 3)
            {
                throw std::runtime_error("Unsupported face");
            }

            auto it_face = this->m_faces.emplace(this->m_faces.end());
            Face *face = &(*it_face);
            face->iterator = it_face;

            Vertex *v0 = temporary_vertices[assimp_face->mIndices[0]];
            Vertex *v1 = temporary_vertices[assimp_face->mIndices[1]];
            Vertex *v2 = temporary_vertices[assimp_face->mIndices[2]];

            Edge *e0 = v0->search_edge_to(v1);
            Edge *e1 = v1->search_edge_to(v2);
            Edge *e2 = v2->search_edge_to(v0);

            auto create_edge = [this](Vertex *ve0, Vertex *ve1) {
                auto it = this->m_edges.emplace(this->m_edges.end(), ve0, ve1);
                (*it).iterator = it;
                if (ve0->edge == nullptr) ve0->edge = &(*it);
                return &(*it);
            };

            if (e0 == nullptr) e0 = create_edge(v0, v1);
            if (e1 == nullptr) e1 = create_edge(v1, v2);
            if (e2 == nullptr) e2 = create_edge(v2, v0);

            e0->build_connectivity(e2, e1, face, e0->is_oriented(v0, v1));
            e1->build_connectivity(e0, e2, face, e1->is_oriented(v1, v2));
            e2->build_connectivity(e1, e0, face, e2->is_oriented(v2, v0));

            face->first_edge = e0;

        }

        this->update();
    }

    Mesh::~Mesh(void)
    {
        // nothing to do atm.
    }



    void
    Mesh::draw(const glm::mat4 &model, const glm::mat4 &view, const glm::mat4 &projection)
    {
        const auto &shaderprogram = this->m_material->getShaderProgram();
        this->m_array_object->bind();
        this->m_material->bind();
        shaderprogram->setUniform("model", model);
        shaderprogram->setUniform("view", view);
        shaderprogram->setUniform("projection", projection);
        std::uintptr_t pointer_offset = 0;
        glDrawElements(GL_TRIANGLES, static_cast<int>(this->m_faces.size() * 3), GL_UNSIGNED_INT, reinterpret_cast<void *>(pointer_offset));
        this->m_material->unbind();
        this->m_array_object->unbind();
    }

    void
    Mesh::update(void)
    {
        this->update_vertices_buffer();
        this->update_elements_buffer();
        this->update_array_object();
        this->m_dirty = false;
    }

    void
    Mesh::update_vertices_buffer(void)
    {
        std::vector<float>  vertices = std::vector<float>();
        vertices.reserve(this->m_vertices.size() * 3);
        unsigned int i_vertex = 0;
        for (Vertex &vertex : this->m_vertices)
        {
            vertex.index = i_vertex++;
            vertices.push_back(vertex.position.x);
            vertices.push_back(vertex.position.y);
            vertices.push_back(vertex.position.z);
            vertices.push_back(vertex.normal.x);
            vertices.push_back(vertex.normal.y);
            vertices.push_back(vertex.normal.z);
        }
        this->m_vertices_buffer->update(vertices.data(), vertices.size() * sizeof(float));
    }

    void
    Mesh::update_elements_buffer(void)
    {
        std::vector<unsigned int>    indices = std::vector<unsigned int>();
        indices.reserve(this->m_faces.size() * 3);
        for (const Face &face : this->m_faces)
        {
            indices.push_back(face.first_edge->begin_vertex->index);
            indices.push_back(face.first_edge->end_vertex->index);
            indices.push_back(face.first_edge->forward_left_edge->end_vertex->index);
        }
        this->m_elements_buffer->update(indices.data(), indices.size() * sizeof(unsigned int));
    }

    void
    Mesh::update_array_object(void)
    {
        this->m_array_object->bind();
        this->m_vertices_buffer->bind();
        this->m_elements_buffer->bind();
        glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);
        std::uintptr_t pointer_offset = 0;
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3, reinterpret_cast<void *>(pointer_offset));
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3, reinterpret_cast<void *>(pointer_offset));
        this->m_array_object->unbind();
        this->m_vertices_buffer->unbind();
        this->m_elements_buffer->unbind();
    }

    bool
    Mesh::is_dirty(void) const
    {
         return this->m_dirty;
    }
}
