#include    "Transform.hpp"
#include    <glm/gtc/matrix_transform.hpp>


namespace WorldParticles
{
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

    }
}
