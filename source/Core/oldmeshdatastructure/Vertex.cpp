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

/*#include    "Engine/Core/Edge.hpp"*/
//#include    "Engine/Core/Face.hpp"
//#include    "Engine/Core/Vertex.hpp"

//namespace   Engine
//{

    //Vertex::Vertex(const glm::vec3 &value_position, const glm::vec3 &value_normal) :
        //index(0),
        //position(value_position),
        //origin(value_position),
        //normal(value_normal),
        //edge(nullptr),
        //iterator(nullptr)
    //{
        //// nothing more to do.
    //}


    //Vertex::~Vertex(void) noexcept
    //{
        //// nothign to do atm.
    //}

    //Edge *
    //Vertex::search_edge_to(Vertex *vertex)
    //{
        //Edge *tmp = this->edge;
        //do
        //{
            //if (tmp != nullptr)
            //{
                //if (tmp->match(this, vertex))
                //{
                   //return tmp;
                //}
                //if (tmp->is_oriented(this))
                    //tmp = tmp->backward_right_edge;
                //else
                    //tmp = tmp->backward_left_edge;
            //}
        //} while (tmp != this->edge && tmp != nullptr);
        //return nullptr;
    //}

    //void
    //Vertex::compute_smooth_normal(void)
    //{
        //this->normal = glm::vec3(0.0f);
        //Edge *tmp = this->edge;
        //do
        //{
            //if (tmp != nullptr)
            //{

                //if (tmp->left_face != nullptr)
                //{
                    //normal += tmp->left_face->normal();
                //}

                //if (tmp->is_oriented(this))
                    //tmp = tmp->backward_right_edge;
                //else
                    //tmp = tmp->backward_left_edge;

            //}
        //} while (tmp != this->edge && tmp != nullptr);

        //this->normal = glm::normalize(this->normal);
    //}

    //void
    //Vertex::rebound_edge(Vertex *new_vertex)
    //{
        //Edge *tmp = this->edge;
        //do
        //{
            //if (tmp != nullptr)
            //{
                //if (tmp->is_oriented(this))
                //{
                    //tmp->end_vertex = new_vertex;
                    //tmp = tmp->backward_right_edge;
                //}
                //else
                //{
                    //tmp->begin_vertex = new_vertex;
                    //tmp = tmp->backward_left_edge;
                //}
            //}
        //} while (tmp != this->edge && tmp != nullptr);
    //}

/*}*/
