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

#include    <log4cpp/Category.hh>
#include    <glm/gtc/matrix_transform.hpp>

#include    "Engine/Core/Transform.hpp"

using namespace     log4cpp;

namespace Engine
{

    Transform::Transform(void) :
        m_matrix(1)
    {
        // nothing to do
    }

    Transform::Transform(const aiMatrix4x4 &m) :
        m_matrix(1)
    {
        m_matrix[0][0] = m.a1;
        m_matrix[1][0] = m.a2;
        m_matrix[2][0] = m.a3;
        m_matrix[3][0] = m.a4;

        m_matrix[0][1] = m.b1;
        m_matrix[1][1] = m.b2;
        m_matrix[2][1] = m.b3;
        m_matrix[3][1] = m.b4;

        m_matrix[0][2] = m.c1;
        m_matrix[1][2] = m.c2;
        m_matrix[2][2] = m.c3;
        m_matrix[3][2] = m.c4;

        m_matrix[0][3] = m.d1;
        m_matrix[1][3] = m.d2;
        m_matrix[2][3] = m.d3;
        m_matrix[3][3] = m.d4;
    }

    Transform::~Transform(void)
    {
        // nothing to do
    }


    void
    Transform::multiplyBy(Transform const& other)
    {
        m_matrix * other.getMatrix();
    }

    const glm::mat4 &
    Transform::getMatrix(void) const
    {
         return this->m_matrix;
    }
    
    void
    Transform::translate(const glm::vec3 &tranlation)
    {
        m_matrix = glm::translate(m_matrix, tranlation);
    }
    
    void
    Transform::scale(const glm::vec3 &s)
    {
        m_matrix = glm::scale(m_matrix, s);
    }

    void
    Transform::rotate(const glm::vec3 &rotation)
    {
//         this->m_matrix = glm::rotate(this->m_matrix, rotation.x, glm::vec3(1.0, 0.0, 0.0));
//         this->m_matrix = glm::rotate(this->m_matrix, rotation.y, glm::vec3(0.0, 1.0, 0.0));
//         this->m_matrix = glm::rotate(this->m_matrix, rotation.z, glm::vec3(0.0, 0.0, 1.0));
    }

    void
    Transform::print() const
    {
        Category &root = Category::getRoot();
        root << Priority::DEBUG << "[" << m_matrix[0][0] << "][" << m_matrix[1][0] << "][" << m_matrix[2][0] << "][" << m_matrix[3][0] << "]";
        root << Priority::DEBUG << "[" << m_matrix[0][1] << "][" << m_matrix[1][1] << "][" << m_matrix[2][1] << "][" << m_matrix[3][1] << "]";
        root << Priority::DEBUG << "[" << m_matrix[0][2] << "][" << m_matrix[1][2] << "][" << m_matrix[2][2] << "][" << m_matrix[3][2] << "]";
        root << Priority::DEBUG << "[" << m_matrix[0][3] << "][" << m_matrix[1][3] << "][" << m_matrix[2][3] << "][" << m_matrix[3][3] << "]";        
//2016-07-08 17:44:37,425 [DEBUG] [1][0][0][500]
//2016-07-08 17:44:37,425 [DEBUG] [0][1][0][100]
//2016-07-08 17:44:37,425 [DEBUG] [0][0][1][2]
//2016-07-08 17:44:37,425 [DEBUG] [0][0][0][1]
    }

}
