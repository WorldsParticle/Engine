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
#include    <mutex>

std::mutex  g_mutex;

#include    "Engine/Core/Material.hpp"
#include    "Engine/Core/ShaderProgram.hpp"
#include    "Engine/MeshDataStructure/Mesh.hpp"

namespace   Engine
{
    using Edge = std::pair<Vertex *, Vertex *>;
    using FaceVertices = std::tuple<Vertex *, Vertex *, Vertex *>;

    Mesh::Mesh(Material *material) :
        m_name("DefaultMesh"),
        m_edges(),
        m_collapse(),
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
        m_edges(),
        m_collapse(),
        m_half_edges(),
        m_faces(),
        m_vertices(),
        m_vertices_buffer(std::make_shared<BufferObject>(BufferObject::Type::ARRAY_BUFFER, BufferObject::Usage::DYNAMIC_DRAW)),
        m_elements_buffer(std::make_shared<BufferObject>(BufferObject::Type::ELEMENT_ARRAY_BUFFER, BufferObject::Usage::DYNAMIC_DRAW)),
        m_array_object(std::make_shared<ArrayObject>()),
        m_material(material),
        m_dirty(true)
    {


        /// TODO remove => only here to test plane equation.

        glm::vec4   eq = glm::vec4(0.0f);
        glm::vec3   a = glm::vec3(0.0f, -2.0f, 0.0f);
        glm::vec3   b = glm::vec3(2.0f, 1.0f, -1.0f);
        glm::vec3   c = glm::vec3(1.0f, -1.0f, 2.0f);


        glm::vec3   ab = b - a;
        glm::vec3   ac = c - a;
        glm::vec3   n = glm::cross(ab, ac);

        eq = glm::vec4(n, a.x * eq.x + a.y * eq.y + a.z * eq.z);

        std::cerr << eq.x << " " << eq.y << " " << eq.z << " " << eq.w << std::endl;

        this->build_connectivity(assimp_mesh);
        this->update_vao();
    }

    Mesh::~Mesh(void) noexcept
    {
    }

    void
    Mesh::increase(void)
    {
        std::lock_guard<std::mutex> lock(g_mutex);
        this->tmp(1);
    }

    void
    Mesh::tmp(int a)
    {
        if (this->m_dirty == true) return;


/*        auto it = this->m_collapse.begin();*/

        //if (it == this->m_collapse.end())
            //return;

        int i = 0;
        for (auto it = this->m_collapse.begin() ; it != this->m_collapse.end() ; )
        {
            ++i;
            HalfEdge *he = (*it).half_edge_const();
            if (this->collapse(he->vertex(), he->pair()->vertex()) == nullptr)
                ++it;
            else
                it = this->m_collapse.begin();
            if (i >= 10000)
                break;
        }

        auto ermax = 1000.0f;

        float pas = 1.0f / this->m_collapse.size();
        float ac = 1.0f;

        for (const EdgeCollapse &ec : this->m_collapse)
        {
            if (ec.half_edge_const()->face() != nullptr)
                ec.half_edge_const()->face()->color() = glm::vec3(1.0f, 0.0f, 0.0f) * ac;
            if (ec.half_edge_const()->pair()->face() != nullptr)
            ec.half_edge_const()->pair()->face()->color() = glm::vec3(1.0f, 0.0f, 0.0f) * ac;

            ac -= pas;
        }

        this->m_dirty = true;
    }


    void
    Mesh::reduce(void)
    {
        std::lock_guard<std::mutex> lock(g_mutex);
        this->tmp(0);
    }


    bool
    Mesh::check_consistency(void)
    {
        bool result = true;
        for (Vertex &vertex : this->m_vertices)
        {
            if (vertex.half_edge() == nullptr)
            {
                std::cerr << "INCONSISTENCY vertex half edge nullptr" << std::endl;
                result = false;
            }
        }
        for (Face &face : this->m_faces)
        {
            if (face.half_edge() == nullptr)
            {
                std::cerr << "INCONSISTENCY face he nullptr" << std::endl;
                result = false;
            }
        }
        for (HalfEdge &he : this->m_half_edges)
        {
            if (he.vertex() == nullptr)
            {
                std::cerr << "INCONSISTENCY he vertex nullptr" << std::endl;
                result = false;
            }
            if (he.pair() == nullptr)
            {
                std::cerr << "INCONSISTENCY he pair nullptr" << std::endl;
                 result = false;
            }
            if (he.pair()->pair() != &he)
            {
                std::cerr << "INCONSISTENCY he pair pair != he" << std::endl;
                result = false;
            }
            if (he.next() == nullptr)
            {
                std::cerr << "INCONSISTENCY he next nullptr" << std::endl;
                result = false;
            }
            if (he.pair()->vertex() == he.vertex())
            {
                std::cerr << "INCONSISTENCY he pair vertex== he.verterx" << std::endl;
                 result = false;
            }
            if (he.is_boundary() == false && &he != he.next()->next()->next())
            {
                std::cerr << "INCONSISTENCY cannot turn around a face" << std::endl;
                result = false;
            }
            if (he.pair()->face() != nullptr)
            {
                he.pair()->face()->color() = he.pair()->face()->color();
                // dumb
            }
        }
        return result;
    }

    HalfEdge *
    Mesh::merge(HalfEdge *he1, HalfEdge *he2)
    {
        HalfEdge    *merged_he = nullptr;

        merged_he = he2->pair();
        he1->pair()->edge() = he2->edge();
        he2->edge()->half_edge() = he2->pair();
        he1->pair()->pair() = he2->pair();
        he2->pair()->pair() = he1->pair();
        he1->vertex()->half_edge() = he1->pair();
        this->m_collapse.erase(he1->edge()->iterator());
        this->m_half_edges.erase(he1->iterator());
        this->m_half_edges.erase(he2->iterator());
        return merged_he;
    }

    Vertex *
    Mesh::collapse(Vertex *v1, Vertex *v2)
    {

        if (v1->shared_neighbour_vertices_with(v2).size() > 2)
        {
            return nullptr;
        }

        auto replace = [this](Vertex *old_vertex, Vertex *new_vertex) {
            auto ingoing_he = old_vertex->ingoing_half_edges();
            for (auto *he : ingoing_he)
                he->vertex() = new_vertex;
        };
        auto merge_adjacent_he = [this](HalfEdge *he) -> HalfEdge * {
            if (he->face() != nullptr)
            {
                HalfEdge *merged_he = this->merge(he->next(), he->next()->next());
                this->m_faces.erase(he->face()->iterator());
                return merged_he;
            }
            else
            {
                std::cerr << "BOUNDARY" << std::endl;
            }
            return nullptr;
        };
        auto remove_if_useless = [this](HalfEdge *he, Vertex *tmp) -> HalfEdge * {
            if (he != nullptr && he->is_boundary() && he->pair()->is_boundary())
            {
                std::cerr << "deletion vertex" << std::endl;

                he->prev()->next() = he->pair()->next();
                he->pair()->next()->prev() = he->prev();

                if (he->vertex() != tmp)
                    this->m_vertices.erase(he->vertex()->iterator());
                this->m_half_edges.erase(he->pair()->iterator());
                this->m_half_edges.erase(he->iterator());
                return nullptr;
            }
            return he;
        };
        HalfEdge *he = v1->outgoing_half_edge_to(v2);
        Vertex *new_vertex = &this->build_vertex();


        glm::mat4 Q = v1->quadric() + v2->quadric();
        new_vertex->quadric() = Q;
        Q[3] = glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);
        glm::mat4 Qi = glm::inverse(Q);
        glm::vec4 pos = -glm::vec4(Qi[0][3], Qi[1][3], Qi[2][3], Qi[3][3]);


        new_vertex->position() = glm::vec3(pos);

        if (he == nullptr)
        {
            return nullptr;
        }

        replace(v1, new_vertex);
        replace(v2, new_vertex);

        this->m_vertices.erase(v1->iterator());
        this->m_vertices.erase(v2->iterator());

        HalfEdge *he_f1 = merge_adjacent_he(he);
        HalfEdge *he_f2 = merge_adjacent_he(he->pair());

        // Boundary specific
        he->next()->prev() = he->prev();
        he->prev()->next() = he->next();
        he->pair()->next()->prev() = he->pair()->prev();
        he->pair()->prev()->next() = he->pair()->next();
        // !Boundary specific

        he_f1 = remove_if_useless(he_f1, he_f2 != nullptr ? he_f2->vertex() : nullptr);
        he_f2 = remove_if_useless(he_f2, nullptr);

        if (he_f1 != nullptr && (new_vertex->half_edge() == nullptr || he_f1->is_boundary()))
            new_vertex->half_edge() = he_f1;
        if (he_f2 != nullptr && (new_vertex->half_edge() == nullptr || he_f2->is_boundary()))
            new_vertex->half_edge() = he_f2;

        this->m_collapse.erase(he->edge()->iterator());
        this->m_half_edges.erase(he->pair()->iterator());
        this->m_half_edges.erase(he->iterator());

        if (new_vertex->half_edge() == nullptr || this->m_half_edges.size() == 0)
        {
            this->m_vertices.clear();
            return nullptr;
        }

        if (new_vertex != nullptr)
        {
            auto out = new_vertex->outgoing_half_edges();
            std::vector<EdgeCollapse> tmp;
            std::vector<float> errors1;
            std::vector<float> errors2;

            for (HalfEdge *out_he : out)
            {
                errors1.push_back(out_he->edge()->m_error);
                tmp.push_back(*out_he->edge());
                this->m_collapse.erase(out_he->edge()->iterator());
            }
            for (int i = 0 ; i < out.size() ; ++i)
            {
                auto it = this->m_collapse.insert(tmp[i]);
                EdgeCollapse &c = const_cast<EdgeCollapse&>(*it);
                c.iterator() = it;
                out[i]->edge() = &c;
                out[i]->pair()->edge() = &c;
                errors2.push_back(c.error());
            }

        }

        this->m_dirty = true;
        return new_vertex;
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
        //glPolygonMode( GL_FRONT_AND_BACK, GL_LINE  );
        glDrawArrays(GL_TRIANGLES, 0, static_cast<int>(this->m_faces.size() * 3));
        this->m_material->unbind();
        this->m_array_object->unbind();
    }

    void
    Mesh::update(void)
    {
        std::lock_guard<std::mutex> lock(g_mutex);
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
        this->set_half_edge_prev_component();

        this->compute_quadric();
        this->compute_priority_queue();

        std::cerr << "start check..." << std::endl;
        this->check_consistency();
        std::cerr << "end check..." << std::endl;
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

            this->m_edges.push_back(he1);

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

    void
    Mesh::set_half_edge_prev_component(void)
    {
        for (HalfEdge &half_edge : this->m_half_edges)
        {
            half_edge.next()->prev() = &half_edge;
        }
    }

    void
    Mesh::compute_quadric(void)
    {
        for (Face &face : this->m_faces)
        {
            std::vector<Vertex *> vertices = face.vertices();
            glm::vec4 eq = face.plane_equation();
            for (Vertex *vertex : vertices)
            {
/*                glm::mat4 test = glm::mat4(*/
                        //glm::vec4(eq.x * eq.x, eq.x * eq.y, eq.x * eq.z, eq.x * eq.w),
                        //glm::vec4(eq.y * eq.x, eq.y * eq.y, eq.y * eq.z, eq.y * eq.w),
                        //glm::vec4(eq.z * eq.x, eq.z * eq.y, eq.z * eq.z, eq.z * eq.w),
                        /*glm::vec4(eq.w * eq.x, eq.w * eq.y, eq.w * eq.z, eq.w * eq.w));*/
                vertex->quadric() += glm::outerProduct(eq, eq);
/*                if (test != glm::outerProduct(eq, eq))*/
                //{
                    //std::cerr << "ERRROROOROROROOR" << std::endl;
                //}
                //else
                //{
                    //std::cerr << "GOOD" << std::endl;
                /*}*/
            }
        }
    }

    void
    Mesh::compute_priority_queue(void)
    {
        float   pas = 1.0f / this->m_edges.size();
        float ac = 1.0f;

        for (HalfEdge *he : this->m_edges)
        {
            auto it = this->m_collapse.insert(EdgeCollapse(he));
            EdgeCollapse &ec = const_cast<EdgeCollapse&>(*it);
            ec.iterator() = it;
            he->edge() = &ec;
            he->pair()->edge() = &ec;
        }
        //auto max = (*this->m_collapse.rbegin()).error();
        //auto min = (*this->m_collapse.begin()).error();

        for (const EdgeCollapse &ec : this->m_collapse)
        {
            //auto actual = ec.error();
            //ac = 1.0 - (actual - min) / max;
            if (ec.half_edge_const()->face() != nullptr)
                ec.half_edge_const()->face()->color() = glm::vec3(1.0f, 0.0f, 0.0f) * ac;
            if (ec.half_edge_const()->pair()->face() != nullptr)
            ec.half_edge_const()->pair()->face()->color() = glm::vec3(1.0f, 0.0f, 0.0f) * ac;
            ac -= pas;
        }
        this->m_edges.clear();
    }

    HalfEdge &
    Mesh::build_half_edge(void)
    {
        auto it = this->m_half_edges.emplace(this->m_half_edges.end(), HalfEdge());
        (*it).iterator() = it;
        return *it;
    }

    Vertex &
    Mesh::build_vertex(void)
    {
        auto it = this->m_vertices.emplace(this->m_vertices.end(), Vertex());
        (*it).iterator() = it;
        return *it;
    }

    Face &
    Mesh::build_face(void)
    {
        auto it = this->m_faces.emplace(this->m_faces.end(), Face());
        (*it).iterator() = it;
        return *it;
    }

}
