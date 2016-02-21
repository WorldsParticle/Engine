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

#include    <glm/gtc/random.hpp>

#include    "Engine/MeshDataStructure/Vertex.hpp"
#include    "Engine/MeshDataStructure/Face.hpp"

namespace   Engine
{
    Face::Face(void) :
        m_half_edge(nullptr),
        m_iterator(),
        m_color(glm::linearRand(glm::vec3(0.0f), glm::vec3(1.0f)))
    {
    }

    Face::Face(HalfEdge *half_edge) :
        m_half_edge(half_edge),
        m_iterator(),
        m_color(glm::linearRand(glm::vec3(0.0f), glm::vec3(1.0f)))
    {
    }

    Face::~Face(void)
    {
    }



    HalfEdge *&
    Face::half_edge(void)
    {
        return this->m_half_edge;
    }

    std::list<Face>::iterator &
    Face::iterator(void)
    {
         return this->m_iterator;
    }

    glm::vec3 &
    Face::color(void)
    {
         return this->m_color;
    }



    glm::vec3
    Face::normal(void)
    {
        auto v = this->vertices();
        return glm::cross(v[1]->position() - v[0]->position(), v[2]->position() - v[1]->position());
    }

    std::vector<Vertex *>
    Face::vertices(void) const
    {
        std::vector<Vertex *> vertices;

        HalfEdge *end = this->m_half_edge;
        HalfEdge *he = end;
        do
        {
            vertices.push_back(he->vertex());
            he = he->next();
        } while (he != end);
        return vertices;
    }

    glm::vec4
    Face::plane_equation(void) const
    {
        std::vector<Vertex *>   vertices = this->vertices();

        glm::vec3   a = vertices[0]->position();
        glm::vec3   b = vertices[1]->position();
        glm::vec3   c = vertices[2]->position();

        glm::vec3   ab = b - a;
        glm::vec3   ac = c - a;
        glm::vec3   n = glm::cross(ab, ac);

        return glm::vec4(n, a.x * n.x + a.y * n.y + a.z * n.z);
    }

}
