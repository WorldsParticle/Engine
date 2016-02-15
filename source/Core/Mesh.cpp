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

    ///
    /// VERTEX CLASS
    ///

    Mesh::Vertex::Vertex(const glm::vec3 &value_position, const glm::vec3 &value_normal) :
        index(0),
        position(value_position),
        normal(value_normal),
        edge(nullptr),
        iterator(nullptr)
    {
        // nothing more to do.
    }


    Mesh::Vertex::Vertex(const Vertex &other) :
        index(other.index),
        position(other.position),
        normal(other.normal),
        edge(other.edge),
        iterator(other.iterator)
    {
    }

    Mesh::Vertex::Vertex(Vertex &&other) noexcept :
        index(std::move(other.index)),
        position(std::move(other.position)),
        normal(std::move(other.normal)),
        edge(std::move(other.edge)),
        iterator(std::move(other.iterator))
    {
    }

    Mesh::Vertex::~Vertex(void) noexcept
    {
        // nothign to do atm.
    }

    Mesh::Vertex &
    Mesh::Vertex::operator=(const Mesh::Vertex &other)
    {
        this->index = other.index;
        this->position = other.position;
        this->normal = other.normal;
        this->edge = other.edge;
        this->iterator = other.iterator;
        return *this;
    }

    Mesh::Vertex &
    Mesh::Vertex::operator=(Mesh::Vertex &&other) noexcept
    {
        this->index = std::move(other.index);
        this->position = std::move(other.position);
        this->normal = std::move(other.normal);
        this->edge = std::move(other.edge);
        this->iterator = std::move(other.iterator);
        return *this;
    }

    std::list<Mesh::Edge>::iterator *
    Mesh::Vertex::search_edge_to(const std::list<Vertex>::iterator &vertex)
    {
        std::list<Edge>::iterator *tmp = this->edge;
        do
        {
            if (tmp != nullptr)
            {
                if ((*(*tmp)).match(*this->iterator, vertex))
                {
                    return tmp;
                }
                if ((*tmp).is_oriented(*this->iterator))
                    tmp = (*tmp.backward_right_edge);
                else
                    tmp = (*tmp).backward_left_edge;
            }
        } while (tmp != this->edge && tmp != nullptr);
        return nullptr;
    }

    std::list<Mesh::Edge>::iterator *
    Mesh::Vertex::create_edge_to(const std::list<Vertex>::iterator &vertex)
    {
        // first check if the edge don't already exist.
        std::list<Edge>::iterator *edge = this->search_edge_to(to);
        // create an edge from this vertex to the "to" vertex with face as left face.
        if (edge == nullptr)
        {
            std::list<Edge>::iterator &edge = this->m_edges.emplace(this->m_edges.end(),
                    this->iterator, to, face);
        }
        return edge;
    }


    ///
    /// EDGE CLASS
    ///

    Mesh::Edge::Edge(const std::list<Vertex>::iterator &v1,
            const std::list<Vertex>::iterator &v2,
            const std::list<Face>::iterator &face) :
        begin_vertex(v1),
        end_vertex(v2),
        left_face(face),
        right_face(nullptr),
        forward_left_edge(nullptr),
        forward_right_edge(nullptr),
        backward_left_edge(nullptr),
        backward_right_edge(nullptr)
    {

    }

    Mesh::Edge::Edge(const Mesh::Edge &other) :
        begin_vertex(other.begin_vertex),
        end_vertex(other.end_vertex),
        left_face(other.left_face),
        right_face(other.right_face),
        forward_left_edge(other.forward_left_edge),
        forward_right_edge(other.forward_right_edge),
        backward_left_edge(other.backward_left_edge),
        backward_right_edge(other.backward_right_edge)
    {

    }

    Mesh::Edge::Edge(Mesh::Edge &&other) noexcept :
        begin_vertex(std::move(other.begin_vertex)),
        end_vertex(std::move(other.end_vertex)),
        left_face(std::move(other.left_face)),
        right_face(std::move(other.right_face)),
        forward_left_edge(std::move(other.forward_left_edge)),
        forward_right_edge(std::move(other.forward_right_edge)),
        backward_left_edge(std::move(other.backward_left_edge)),
        backward_right_edge(std::move(other.backward_right_edge))
    {

    }

    Mesh::Edge::~Edge(void) noexcept
    {
        // nothing to do.
    }

    Mesh::Edge &
    Mesh::Edge::operator=(const Mesh::Edge &other)
    {
        this->begin_vertex = other.begin_vertex;
        this->end_vertex = other.end_vertex;
        this->left_face = other.left_face;
        this->right_face = other.right_face;
        this->forward_left_edge = other.forward_left_edge;
        this->forward_right_edge = other.forward_right_edge;
        this->backward_left_edge = other.backward_left_edge;
        this->backward_right_edge = other.backward_right_edge;
        return *this;
    }

    Mesh::Edge &
    Mesh::Edge::operator=(Mesh::Edge &&other) noexcept
    {
        this->begin_vertex = std::move(other.begin_vertex);
        this->end_vertex = std::move(other.end_vertex);
        this->left_face = std::move(other.left_face);
        this->right_face = std::move(other.right_face);
        this->forward_left_edge = std::move(other.forward_left_edge);
        this->forward_right_edge = std::move(other.forward_right_edge);
        this->backward_left_edge = std::move(other.backward_left_edge);
        this->backward_right_edge = std::move(other.backward_right_edge);
        return *this;
    }

    bool
    Mesh::Edge::match(const std::list<Vertex>::iterator &v0, const std::list<Vertex>::iterator &v1) const
    {
         if ((v0 == this->begin_vertex && v1 == this->end_vertex) || (v0 == this->end_vertex && v1 == this->begin_vertex))
             return true;
         return false;
    }

    bool
    Mesh::Edge::is_oriented(std::list<Vertex>::iterator &v0, std::list<Vertex>::iterator &v1)
    {
        if ((v0 != this->begin_vertex && v0 != this->end_vertex) || (v1 != this->begin_vertex && v0 != this->end_vertex))
            throw std::runtime_exception("v0 or v1 don't match begin or end");
        if (v0 == this->begin_vertex && v1 == this->end_vertex)
            return true;
        else if (v0 == this->end_vertex && v1 == this->begin_vertex)
            return false;
        throw std::runtime_exception("v0 && v1 are equal.");
    }

    bool
    Mesh::Edge::is_oriented(std::list<Vertex>::iterator &v0)
    {
         if (v0 == this->end_vertex)
             return true;
         return false;
    }

    void
    Mesh::Edge::build_connectivity(std::list<Edge>::iterator *backward_edge,
            std::list<Edge>::iterator *forward_edge,
            std::list<Face>::iterator *face,
            bool oriented)
    {
        if (backward_edge == nullptr || forward_edge == nullptr || face == nullptr)
            throw std::runtime_exception("be || fe || face == nullptr.");
        if (oriented)
        {
            this->backward_left_edge = backward_edge;
            this->forward_left_edge = forward_edge;
            this->left_face = face;
        }
        else
        {
            this->backward_right_edge = backward_edge;
            this->forward_right_edge = forward_edge;
            this->right_face = face;
        }
    }

    ///
    /// MESH CLASS
    ///

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

        std::vector<std::list<Vertex>::iterator>   temporary_vertices;
        temporary_vertices.reserve(assimp_mesh->mNumVertices);

        for (unsigned int i_vertex ; i_vertex < assimp_mesh->mNumVertices ; ++i_vertex)
        {
            const aiVector3D *vertex = &assimp_mesh->mVertices[i_vertex];
            temporary_vertices[i_vertex] = this->m_vertices.emplace(this->m_vertices.end(),
                    glm::vec3(vertex->x, vertex->y, vertex->z),
                    glm::vec3(0.0f, 0.0f, 0.0f));
            temporary_vertices[i_vertex]->iterator = temporary_vertices[i_vertex];
        }

        for (unsigned int i_faces = 0 ; i_faces < assimp_mesh->mNumFaces ; ++i_faces)
        {
            const aiFace    *assimp_face = &assimp_mesh->mFaces[i_faces];

            const std::list<Face>::iterator &face = this->m_faces.emplace(this->m_faces.end());

            if (assimp_face->mNumIndices != 3)
            {
                throw std::runtime_error("Unsupported face");
            }

            std::list<Vertex>::iterator &v0 = temporary_vertices[assimp_face->mIndices[0]];
            std::list<Vertex>::iterator &v1 = temporary_vertices[assimp_face->mIndices[1]];
            std::list<Vertex>::iterator &v2 = temporary_vertices[assimp_face->mIndices[2]];

            std::list<Edge>::iterator *e0 = (*v0).create_edge_to(v1);
            std::list<Edge>::iterator *e1 = (*v1).create_edge_to(v2);
            std::list<Edge>::iterator *e2 = (*v2).create_edge_to(v0);

            bool orientation_e0 = e0.is_oriented(v0, v1);
            bool orientation_e1 = e1.is_oriented(v1, v2);
            bool orientation_e2 = e2.is_oriented(v2, v0);

            e0->build_connectivity(e2, e1, face, orientation_e0);
            e1->build_connectivity(e0, e2, face, orientation_e1);
            e2->build_connectivity(e1, e0, face, orientation_e2);

            (*face).first_edge = e0;

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
