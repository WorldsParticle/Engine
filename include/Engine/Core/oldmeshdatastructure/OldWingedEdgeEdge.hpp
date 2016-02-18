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

/*#pragma once*/

//#include    <list>

//#include    "Engine/Configuration.hpp"

//namespace Engine
//{

    //class   Vertex;
    //class   Face;

    //class ENGINE_EXPORTS Edge
    //{

        //public:

            /////
            ///// \brief Default constructor.
            /////
            //Edge(Vertex *begin_vertex, Vertex *end_vertex);

            /////
            ///// \brief Copy constructor.
            /////
            //Edge(const Edge &other) = default;

            /////
            ///// \brief Move constructor.
            /////
            //Edge(Edge &&other) noexcept = default;

            /////
            ///// \brief Destructor.
            /////
            //virtual ~Edge(void) noexcept;

        //public:
            /////
            ///// \brief Copy assignment operator.
            /////
            //Edge    &operator=(const Edge &other) = default;

            /////
            ///// \brief Move assignment operator.
            /////
            //Edge    &operator=(Edge &&other) noexcept = default;

        //public:

            /////
            ///// \brief Return true if v0 && v1 match begin and end (the order doesn't matter).
            /////
            //bool match(Vertex *v0, Vertex *v1) const;

            /////
            ///// \brief Return true if v0 is the begin vertex and v1 is the end vertex. False otherwise.
            /////
            ///// Throw runtime_exception if v0 or v1 is nor begin nor end.
            /////
            //bool is_oriented(Vertex *v0, Vertex *v1);

            /////
            ///// \brief Return true if end vertex is v0. False otherwise.
            /////
            //bool is_oriented(Vertex *vo);

            /////
            ///// \brief Build the wing of the edge. if oriented is true, it's the left wing, right wing otherwise.
            /////
            //void build_connectivity(Edge *be, Edge *fe, Face *face, bool oriented);

            //Edge *next(Face *face);
            //Edge *prev(Face *face);
            //Vertex *begin(Face *face);

        //public:
            /////
            ///// \brief The iterator of the edge in the list.
            /////
            //std::list<Edge>::iterator   iterator;

            /////
            ///// \brief The begin vertex of the winged edge.
            /////
            //Vertex  *begin_vertex;

            /////
            ///// \brief The end vertex of the winged edge.
            /////
            //Vertex  *end_vertex;

            /////
            ///// \brief The left face of the edge.
            /////
            //Face    *left_face;

            /////
            ///// \brief The right face of the edge.
            /////
            //Face    *right_face;

            /////
            ///// \brief The forward left edge
            /////
            //Edge    *forward_left_edge;

            /////
            ///// \brief The forward right edge.
            /////
            //Edge    *forward_right_edge;

            /////
            ///// \brief The backward left edge.
            /////
            //Edge    *backward_left_edge;

            /////
            ///// \brief The backward right edge.
            /////
            //Edge    *backward_right_edge;

    //};

/*}*/
