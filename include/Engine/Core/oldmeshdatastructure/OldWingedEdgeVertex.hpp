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

//#include    <glm/glm.hpp>
//#include    <list>

//#include    "Engine/Configuration.hpp"

//namespace Engine
//{

    //class   Edge;
    //class   Face;

    //class ENGINE_EXPORTS Vertex
    //{

        //public:

            /////
            ///// \brief Default constructor.
            /////
            //Vertex(const glm::vec3 &position, const glm::vec3 &normal);

            /////
            ///// \brief Copy constructor.
            /////
            //Vertex(const Vertex &other) = default;

            /////
            ///// \brief Move constructor.
            /////
            //Vertex(Vertex &&other) noexcept = default;

            /////
            ///// \brief Destructor.
            /////
            //~Vertex(void) noexcept;

        //public:

            /////
            ///// \brief Copy assignment operator.
            /////
            //Vertex  &operator=(const Vertex &other) = default;

            /////
            ///// \brief Move assignment operator.
            /////
            //Vertex  &operator=(Vertex &&other) noexcept = default;

        //public:

            /////
            ///// \brief Return an edge between this vertex and the one in parameter. Or nullptr if that don't exist.
            /////
            //Edge *search_edge_to(Vertex *vertex);

            /////
            ///// \brief Compute the smooth normal of the vertex.
            /////
            //void compute_smooth_normal(void);

            //void rebound_edge(Vertex *new_vertex);

        //public:

            /////
            ///// \brief The index of the vertex. Used in order to compute the indice buffer.
            /////
            //unsigned int    index;

            /////
            ///// \brief The position of the vertex.
            /////
            //glm::vec3       position;
            //glm::vec3       origin;

            /////
            ///// \brief The normal of the vertex.
            /////
            //glm::vec3       normal;

            /////
            ///// \brief One of the edge connected to the vertex.
            /////
            //Edge            *edge;

            /////
            ///// \brief The vertex iterator.
            /////
            //std::list<Vertex>::iterator iterator;

    //};

/*}*/
