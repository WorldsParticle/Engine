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

/*#include    <GL/glew.h>*/
//#include    <iostream>
//#include    <map>

//#include    "Engine/Core/Mesh.hpp"
//#include    "Engine/Core/Material.hpp"
//#include    "Engine/Core/ShaderProgram.hpp"

//namespace   Engine
//{

    //Mesh::Mesh(Material *material) :
        //m_name("default"),
        //m_dirty(true),
        //m_edges(),
        //m_faces(),
        //m_vertices(),
        //m_vertices_buffer(std::make_shared<BufferObject>(BufferObject::Type::ARRAY_BUFFER, BufferObject::Usage::DYNAMIC_DRAW)),
        //m_elements_buffer(std::make_shared<BufferObject>(BufferObject::Type::ELEMENT_ARRAY_BUFFER, BufferObject::Usage::DYNAMIC_DRAW)),
        //m_array_object(std::make_shared<ArrayObject>()),
        //m_material(material)
    //{
    //}

    //Mesh::Mesh(const aiMesh *assimp_mesh, Material *material) :
        //m_name(assimp_mesh->mName.C_Str()),
        //m_dirty(true),
        //m_edges(),
        //m_faces(),
        //m_vertices(),
        //m_vertices_buffer(std::make_shared<BufferObject>(BufferObject::Type::ARRAY_BUFFER, BufferObject::Usage::DYNAMIC_DRAW)),
        //m_elements_buffer(std::make_shared<BufferObject>(BufferObject::Type::ELEMENT_ARRAY_BUFFER, BufferObject::Usage::DYNAMIC_DRAW)),
        //m_array_object(std::make_shared<ArrayObject>()),
        //m_material(material)
    //{
        //std::vector<Vertex *>   temporary_vertices;
        //temporary_vertices.reserve(assimp_mesh->mNumVertices);

        //std::cerr << "Number of Vertices : " << assimp_mesh->mNumVertices << std::endl;
        //for (unsigned int i_vertex = 0 ; i_vertex < assimp_mesh->mNumVertices ; ++i_vertex)
        //{
            //const aiVector3D *vertex = &assimp_mesh->mVertices[i_vertex];
            //std::list<Vertex>::iterator it = this->m_vertices.emplace(this->m_vertices.end(),
                    //glm::vec3(vertex->x, vertex->y, vertex->z),
                    //glm::vec3(0.0f, 0.0f, 1.0f));
            //temporary_vertices[i_vertex] = &(*it);
            //temporary_vertices[i_vertex]->iterator = it;
            //temporary_vertices[i_vertex]->index = i_vertex;
        //}

        //std::cerr << "Number of faces : " << assimp_mesh->mNumFaces << std::endl;
        //for (unsigned int i_faces = 0 ; i_faces < assimp_mesh->mNumFaces ; ++i_faces)
        //{
            //const aiFace    *assimp_face = &assimp_mesh->mFaces[i_faces];

            //if (assimp_face->mNumIndices != 3)
            //{
                //throw std::runtime_error("Unsupported face");
            //}

            //auto it_face = this->m_faces.emplace(this->m_faces.end());
            //Face *face = &(*it_face);
            //face->iterator = it_face;

            //Vertex *v0 = temporary_vertices[assimp_face->mIndices[0]];
            //Vertex *v1 = temporary_vertices[assimp_face->mIndices[1]];
            //Vertex *v2 = temporary_vertices[assimp_face->mIndices[2]];

            ////std::cerr << "e0 => " << assimp_face->mIndices[0] << " -> " << assimp_face->mIndices[1] << std::endl;
            ////std::cerr << "e1 => " << assimp_face->mIndices[1] << " -> " << assimp_face->mIndices[2] << std::endl;
            ////std::cerr << "e2 => " << assimp_face->mIndices[2] << " -> " << assimp_face->mIndices[0] << std::endl;

            //Edge *e0 = v0->search_edge_to(v1);
            //Edge *e1 = v1->search_edge_to(v2);
            //Edge *e2 = v2->search_edge_to(v0);


            //auto check_consistency = [this](const std::string &t, Vertex *lv0, Vertex *lv1){
                //for (Edge &edge : this->m_edges)
                //{
                    //if (edge.begin_vertex == lv0 && edge.end_vertex == lv1)
                    //{
                        //if (edge.begin_vertex->search_edge_to(edge.end_vertex) == nullptr)
                        //{
                            //std::cerr << t << " first "<< std::endl;
                        //}
                        //std::cerr << t << std::endl;
                    //}
                    //else if (edge.begin_vertex == lv1 && edge.end_vertex == lv0)
                    //{
                        //if (edge.end_vertex->search_edge_to(edge.begin_vertex) == nullptr)
                        //{
                            //std::cerr << t << " SECOND "<< std::endl;
                        //}
                        //std::cerr << t << std::endl;
                    //}
                //}
            //};

            //if (e0 == nullptr)
            //{
                //check_consistency("error consistency => e0", v0, v1);
            //}
            //if (e1 == nullptr)
            //{
                //check_consistency("error consistency => e1", v1, v2);
            //}
            //if (e2 == nullptr)
            //{
                //check_consistency("error consistency => e2", v2, v0);
            //}

            //auto create_edge = [this](Vertex *ve0, Vertex *ve1) {
                //auto it = this->m_edges.emplace(this->m_edges.end(), ve0, ve1);
                //(*it).iterator = it;
                //if (ve0->edge == nullptr) ve0->edge = &(*it);
                //return &(*it);
            //};

            //if (e0 == nullptr)
                //e0 = create_edge(v0, v1);
            ////else
                ////std::cerr << "e0 found" << std::endl;
            //if (e1 == nullptr)
                //e1 = create_edge(v1, v2);
            ////else
                ////std::cerr << "e1 found" << std::endl;
            //if (e2 == nullptr)
                //e2 = create_edge(v2, v0);
            ////else
                ////std::cerr << "e2 found" << std::endl;

            //e0->build_connectivity(e2, e1, face, e0->is_oriented(v0, v1));
            //e1->build_connectivity(e0, e2, face, e1->is_oriented(v1, v2));
            //e2->build_connectivity(e1, e0, face, e2->is_oriented(v2, v0));

            //face->first_edge = e0;

        //}

        //std::cerr << "Result =>" << std::endl;
        //std::cerr << "Number of edge : " << this->m_edges.size() << std::endl;
        //std::cerr << "Number of face : " << this->m_faces.size() << std::endl;
        //std::cerr << "Number of vertex : " << this->m_vertices.size() << std::endl;

        ////this->compute_smooth_normal();
        //this->update();
    //}

    //Mesh::~Mesh(void)
    //{
        //// nothing to do atm.
    //}



    //void
    //Mesh::compute_smooth_normal(void)
    //{
         //for (Vertex &vertex : this->m_vertices)
         //{
             //vertex.compute_smooth_normal();
         //}
    //}

    //void
    //Mesh::merge(Edge *e1, Edge *e2, Face *face)
    //{
        //// create a new edge with the two in parameter.
        //std::list<Edge>::iterator it = this->m_edges.emplace(this->m_edges.end(),
                //e1->begin_vertex, e2->end_vertex);
        //(*it).iterator = it;
        //Edge *new_edge = &(*it);

        //// if the left_face is equal to the one that will be deleted
        //if (e1->left_face == face)
        //{
            //// we save the right face
            //new_edge->forward_right_edge = e1->forward_right_edge;
            //new_edge->backward_right_edge = e1->backward_right_edge;
            //new_edge->right_face = e1->right_face;

            //// and select the left face from the orientation of e2
            //if (e2->right_face == face)
            //{
                //new_edge->forward_left_edge = e2->forward_left_edge;
                //new_edge->backward_left_edge = e2->backward_left_edge;
                //new_edge->left_face = e2->left_face;
            //}
            //else
            //{
                //new_edge->forward_left_edge = e2->forward_right_edge;
                //new_edge->backward_left_edge = e2->backward_right_edge;
                //new_edge->left_face = e2->right_face;
            //}
        //}
        //else
        //{
            //// we save the left face
            //new_edge->forward_left_edge = e1->forward_left_edge;
            //new_edge->backward_left_edge = e1->backward_left_edge;
            //new_edge->left_face = e1->left_face;
            //// and select the right face from the orientation of e1.
            //if (e2->left_face == face)
            //{
                //new_edge->forward_right_edge = e2->forward_right_edge;
                //new_edge->backward_right_edge = e2->backward_right_edge;
                //new_edge->right_face = e2->right_face;
            //}
            //else
            //{
                //new_edge->forward_right_edge = e2->forward_left_edge;
                //new_edge->backward_right_edge = e2->backward_left_edge;
                //new_edge->right_face = e2->left_face;
            //}
        //}

        //if (new_edge->left_face != nullptr)
        //{
            //new_edge->forward_left_edge->backward_left_edge = new_edge;
            //new_edge->backward_left_edge->forward_left_edge = new_edge;
            //new_edge->left_face->first_edge = new_edge;
        //}
        //if (new_edge->right_face != nullptr)
        //{
            //new_edge->forward_right_edge->backward_right_edge = new_edge;
            //new_edge->backward_right_edge->forward_right_edge = new_edge;
            //new_edge->right_face->first_edge = new_edge;
        //}

        //if (new_edge->left_face == nullptr && new_edge->right_face == nullptr)
        //{
            //std::cerr << "MUST BE DELETED" << std::endl;
            //this->m_edges.erase(e1->iterator);
            //this->m_edges.erase(e2->iterator);
            //this->m_edges.erase(new_edge->iterator);
        //}
    //}


    //void
    //Mesh::reduce(void)
    //{
        //static float val = 0.0f;
        //static auto it = this->m_edges.begin();
        //static auto prev_it = this->m_edges.end();

        //val += 0.1f;
        //if (it == this->m_edges.end())
            //it = this->m_edges.begin();

        //if (prev_it != this->m_edges.end())
        //{
            //if ((*prev_it).left_face != nullptr)
                //(*prev_it).left_face->color = (*prev_it).left_face->origin_color;
            //if ((*prev_it).right_face != nullptr)
                //(*prev_it).right_face->color = (*prev_it).right_face->origin_color;
        //}


        //if ((*it).left_face != nullptr)
            //(*it).left_face->color = glm::vec3(1.0f, 0.0f, 0.0f);
        //if ((*it).right_face != nullptr)
            //(*it).right_face->color = glm::vec3(1.0f, 0.2f, 0.2f);
        //if ((*it).left_face != nullptr && (*it).right_face == nullptr)
            //(*it).left_face->color = glm::vec3(0.0f, 0.0f, 1.0f);

        //if ((*it).left_face != nullptr)
        //{
            //this->smooth_collapse((*it).backward_left_edge, val);
            //this->smooth_collapse((*it).forward_left_edge, val);
        //}
        //if ((*it).right_face != nullptr)
        //{
            //this->smooth_collapse((*it).backward_right_edge, val);
            //this->smooth_collapse((*it).forward_right_edge, val);
        //}
        //std::cerr << "e => " << (*it).begin_vertex->index << " " << (*it).end_vertex->index << std::endl;

        //if (val >= 0.4f)
        //{
            //prev_it = it;
            //if (it != this->m_edges.end())
                //++it;
            //val = 0.0f;
        //}
        //this->m_dirty = true;

        //std::map<std::pair<int, int>, bool> result;
        //for (Edge &edge : this->m_edges)
        //{
            //std::pair<int, int> e = std::make_pair(edge.begin_vertex->index, edge.end_vertex->index);
            //std::pair<int, int> e2 = std::make_pair(edge.end_vertex->index, edge.begin_vertex->index);
            //if (result.find(e) != result.end())
            //{
                //std::cerr << e.first << ":" << e.second << " already exist" << std::endl;
                //std::cerr << "error in the edge" << std::endl;
            //}
            //else if (result.find(e2) != result.end())
            //{
                //std::cerr << e2.first << ":" << e2.second << " already exist" << std::endl;
                //std::cerr << "error in the edge" << std::endl;
            //}
            //else
            //{
                 //result[e] = true;
            //}
        //}
    //}

    //void
    //Mesh::increase(void)
    //{
        //static float    val = 0.0f;

        //val += 0.1f;
        //if (this->m_edges.size() > 0)
            //this->smooth_collapse(&(*this->m_edges.begin()), val);
        //this->m_dirty = true;
        //if (val >= 0.6f)
            //val = 0.0f;
    //}

    //void
    //Mesh::smooth_collapse(Edge *edge, float ratio)
    //{
        //if (ratio >= 0.6f)
            //this->collapse(edge);
        //else
        //{
            //glm::vec3 end_position = edge->begin_vertex->origin + (edge->end_vertex->origin - edge->begin_vertex->origin) / 2.0f;
            //edge->begin_vertex->position = edge->begin_vertex->origin + (end_position - edge->begin_vertex->origin) * ratio;
            //edge->end_vertex->position = edge->end_vertex->origin + (end_position - edge->end_vertex->origin) * ratio;
        //}
    //}

    //void
    //Mesh::collapse(Edge *edge)
    //{
        //// collaspe the edge in parameter.

        //// create the new vertex
        //std::list<Vertex>::iterator it = this->m_vertices.emplace(this->m_vertices.end(),
                //edge->begin_vertex->position + (edge->end_vertex->position - edge->begin_vertex->position) / 2.0f,
                //glm::vec3(0.0f, 0.0f, 1.0f));
        //(*it).iterator = it;

        //Vertex *beg_vertex = edge->begin_vertex;
        //Vertex *end_vertex = edge->end_vertex;

        //// rebound every edge of the begin_vertex to the new one.
        //edge->begin_vertex->rebound_edge(&(*it));
        //// rebound every edge of the end_vertex to the new one.
        //edge->end_vertex->rebound_edge(&(*it));

        //// remove the begin_vertex.
        //this->m_vertices.erase(beg_vertex->iterator);
        //// remove the end vertex.
        //this->m_vertices.erase(end_vertex->iterator);


        ////if the edge had a left_face
        //if (edge->left_face != nullptr)
        //{
            //Face *tmp = edge->left_face;
            //// merge the last two edge of the face, (the face is used to speed the process).
            //this->merge(edge->forward_left_edge, edge->backward_left_edge, edge->left_face);
            //// remove the left face.
            ////tmp->color = glm::vec3(0.3f, 1.0f, 0.3f);
            //this->m_faces.erase(tmp->iterator);
        //}

        //// if the edge had a right_face
        //if (edge->right_face != nullptr)
        //{
            //Face *tmp = edge->right_face;
            //// merge the last  two edge of the right face, the face is used to speed the process).
            //this->merge(edge->forward_right_edge, edge->backward_right_edge, edge->right_face);
            //// remove the right_face.
            //this->m_faces.erase(tmp->iterator);
        //}

        //this->m_edges.erase(edge->iterator);

        //std::cerr << "Number of faces : " << this->m_faces.size() << std::endl;
        //std::cerr << "Number of edges : " << this->m_edges.size() << std::endl;
        //std::cerr << "Number of vertices : " << this->m_vertices.size() << std::endl;

        ////(*it).compute_smooth_normal();
    //}

    //void
    //Mesh::draw(const glm::mat4 &model, const glm::mat4 &view, const glm::mat4 &projection)
    //{
        //if (this->m_dirty)
            //this->update_elements_buffer();
        //const auto &shaderprogram = this->m_material->getShaderProgram();
        //this->m_array_object->bind();
        //this->m_material->bind();
        //shaderprogram->setUniform("model", model);
        //shaderprogram->setUniform("view", view);
        //shaderprogram->setUniform("projection", projection);
        ////std::uintptr_t pointer_offset = 0;
        ////glDrawElements(GL_TRIANGLES, static_cast<int>(this->m_faces.size() * 3), GL_UNSIGNED_INT, reinterpret_cast<void *>(pointer_offset));
        //glDrawArrays(GL_TRIANGLES, 0, static_cast<int>(this->m_faces.size() * 3));
        //this->m_material->unbind();
        //this->m_array_object->unbind();
    //}

    //void
    //Mesh::update(void)
    //{
        //std::cerr << "Update the mesh in the graphic card" << std::endl;
        ////this->update_vertices_buffer();
        //this->update_elements_buffer();
        //this->update_array_object();
        //this->m_dirty = false;
    //}

    //void
    //Mesh::update_vertices_buffer(void)
    //{
        //std::vector<float>  vertices = std::vector<float>();
        //vertices.reserve(this->m_vertices.size() * 3);
        //unsigned int i_vertex = 0;
        //for (Vertex &vertex : this->m_vertices)
        //{
            //vertex.index = i_vertex++;
            //vertices.push_back(vertex.position.x);
            //vertices.push_back(vertex.position.y);
            //vertices.push_back(vertex.position.z);
            //vertices.push_back(vertex.normal.x);
            //vertices.push_back(vertex.normal.y);
            //vertices.push_back(vertex.normal.z);
            //vertices.push_back(0.0f);
            //vertices.push_back(0.0f);
            //vertices.push_back(1.0f);
        //}
        //std::cerr << "Number of vertices in the vertices_buffer : " << i_vertex << std::endl;
        //std::cerr << "Number of data in the vertices_buffer : (must be i_vertex * 9) " << vertices.size() << std::endl;
        //this->m_vertices_buffer->update(vertices.data(), vertices.size() * sizeof(float));
    //}

    //void
    //Mesh::update_elements_buffer(void)
    //{
        //std::vector<float>          vertices;
        //std::vector<unsigned int>    indices;

        //vertices.reserve(this->m_faces.size() * 3 * 9);
        //indices.reserve(this->m_faces.size() * 3);
        //for (Face &face : this->m_faces)
        //{
            //Edge *edge = face.first_edge;

            //Vertex *vertex = edge->begin(&face);

            //vertices.push_back(vertex->position.x);
            //vertices.push_back(vertex->position.y);
            //vertices.push_back(vertex->position.z);
            //vertices.push_back(vertex->normal.x);
            //vertices.push_back(vertex->normal.y);
            //vertices.push_back(vertex->normal.z);
            //vertices.push_back(face.color.x);
            //vertices.push_back(face.color.y);
            //vertices.push_back(face.color.z);

            ////indices.push_back(edge->begin(&face)->index);
            //edge = edge->next(&face);
            //vertex = edge->begin(&face);

            //vertices.push_back(vertex->position.x);
            //vertices.push_back(vertex->position.y);
            //vertices.push_back(vertex->position.z);
            //vertices.push_back(vertex->normal.x);
            //vertices.push_back(vertex->normal.y);
            //vertices.push_back(vertex->normal.z);
            //vertices.push_back(face.color.x);
            //vertices.push_back(face.color.y);
            //vertices.push_back(face.color.z);

            ////indices.push_back(edge->begin(&face)->index);
            //edge = edge->next(&face);
            //vertex = edge->begin(&face);

            //vertices.push_back(vertex->position.x);
            //vertices.push_back(vertex->position.y);
            //vertices.push_back(vertex->position.z);
            //vertices.push_back(vertex->normal.x);
            //vertices.push_back(vertex->normal.y);
            //vertices.push_back(vertex->normal.z);
            //vertices.push_back(face.color.x);
            //vertices.push_back(face.color.y);
            //vertices.push_back(face.color.z);

            ////indices.push_back(edge->begin(&face)->index);
        //}
        //std::cerr << "Number of elements in the vertices_buffer : " << vertices.size() << std::endl;
        ////this->m_elements_buffer->update(indices.data(), indices.size() * sizeof(unsigned int));
        //this->m_vertices_buffer->update(vertices.data(), vertices.size() * sizeof(float));
        //this->m_dirty = false;
    //}

    //void
    //Mesh::update_array_object(void)
    //{
        //this->m_array_object->bind();
        //this->m_vertices_buffer->bind();
        ////this->m_elements_buffer->bind();
        //glEnableVertexAttribArray(0);
        //glEnableVertexAttribArray(1);
        //glEnableVertexAttribArray(2);
        //std::uintptr_t pointer_offset = 0;
        //glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), reinterpret_cast<void *>(pointer_offset));
        //pointer_offset += 3 * sizeof(float);
        //glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), reinterpret_cast<void *>(pointer_offset));
        //pointer_offset += 3 * sizeof(float);
        //glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), reinterpret_cast<void *>(pointer_offset));
        //this->m_array_object->unbind();
        //this->m_vertices_buffer->unbind();
        ////this->m_elements_buffer->unbind();
    //}

    //bool
    //Mesh::is_dirty(void) const
    //{
         //return this->m_dirty;
    //}
/*}*/
