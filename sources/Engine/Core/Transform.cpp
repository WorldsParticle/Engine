///
/// \file Transform.cpp
///
/// \author Martin-Pierrat Louis (mart_p)
///
/// \date Sun, 17 Jan 2016 07:04:52
///
/// \version 1.0.4
///

#include    <log4cpp/Category.hh>
#include    <glm/gtc/matrix_transform.hpp>

#include    <Engine/Transform.hpp>

using namespace     log4cpp;

namespace Engine
{

    Transform::Transform(void) :
        matrix(1)
    {
        // nothing to do
    }

    Transform::Transform(const aiMatrix4x4 &m) :
        matrix(1)
    {
        matrix[0][0] = m.a1;
        matrix[1][0] = m.a2;
        matrix[2][0] = m.a3;
        matrix[3][0] = m.a4;

        matrix[0][1] = m.b1;
        matrix[1][1] = m.b2;
        matrix[2][1] = m.b3;
        matrix[3][1] = m.b4;

        matrix[0][2] = m.c1;
        matrix[1][2] = m.c2;
        matrix[2][2] = m.c3;
        matrix[3][2] = m.c4;

        matrix[0][3] = m.d1;
        matrix[1][3] = m.d2;
        matrix[2][3] = m.d3;
        matrix[3][3] = m.d4;
        Category &root = Category::getRoot();

        root << Priority::DEBUG << "[" << matrix[0][0] << "][" << matrix[1][0] << "][" << matrix[2][0] << "][" << matrix[3][0] << "]";
        root << Priority::DEBUG << "[" << matrix[0][1] << "][" << matrix[1][1] << "][" << matrix[2][1] << "][" << matrix[3][1] << "]";
        root << Priority::DEBUG << "[" << matrix[0][2] << "][" << matrix[1][2] << "][" << matrix[2][2] << "][" << matrix[3][2] << "]";
        root << Priority::DEBUG << "[" << matrix[0][3] << "][" << matrix[1][3] << "][" << matrix[2][3] << "][" << matrix[3][3] << "";
    }

    Transform::~Transform(void)
    {
        // nothing to do
    }



    const glm::mat4 &
    Transform::getMatrix(void) const
    {
         return this->matrix;
    }

    void
    Transform::rotate(const glm::vec3 &rotation)
    {
         this->matrix = glm::rotate(this->matrix, rotation.x, glm::vec3(1.0, 0.0, 0.0));
         this->matrix = glm::rotate(this->matrix, rotation.y, glm::vec3(0.0, 1.0, 0.0));
         this->matrix = glm::rotate(this->matrix, rotation.z, glm::vec3(0.0, 0.0, 1.0));
    }

}
