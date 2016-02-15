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

#include    <stdexcept>

#include    "Engine/Core/Edge.hpp"

namespace Engine
{
    Edge::Edge(Vertex *v1, Vertex *v2) :
        iterator(),
        begin_vertex(v1),
        end_vertex(v2),
        left_face(nullptr),
        right_face(nullptr),
        forward_left_edge(nullptr),
        forward_right_edge(nullptr),
        backward_left_edge(nullptr),
        backward_right_edge(nullptr)
    {

    }

    Edge::~Edge(void) noexcept
    {
        // nothing to do.
    }

    bool
    Edge::match(Vertex *v0, Vertex *v1) const
    {
         if ((v0 == this->begin_vertex && v1 == this->end_vertex)
                 || (v0 == this->end_vertex && v1 == this->begin_vertex))
             return true;
         return false;
    }

    bool
    Edge::is_oriented(Vertex *v0, Vertex *v1)
    {
        if ((v0 != this->begin_vertex && v0 != this->end_vertex) ||
                (v1 != this->begin_vertex && v1 != this->end_vertex))
            throw std::runtime_error("v0 or v1 don't match begin or end");
        if (v0 == this->begin_vertex && v1 == this->end_vertex)
            return true;
        else if (v0 == this->end_vertex && v1 == this->begin_vertex)
            return false;
        throw std::runtime_error("v0 && v1 are equal.");
    }

    bool
    Edge::is_oriented(Vertex *v0)
    {
         if (v0 == this->end_vertex)
             return true;
         return false;
    }

    void
    Edge::build_connectivity(Edge *backward_edge, Edge *forward_edge, Face *face, bool oriented)
    {
        if (backward_edge == nullptr || forward_edge == nullptr || face == nullptr)
            throw std::runtime_error("be || fe || face == nullptr.");
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


}
