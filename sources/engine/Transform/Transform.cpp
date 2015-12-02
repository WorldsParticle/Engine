#include    "Transform.hpp"
#include    <glm/gtc/matrix_transform.hpp>


Transform::Transform(const glm::vec3 &position,
                     const glm::vec3 &rotation,
                     const glm::vec3 &scale) :
    _position(position),
    _rotation(rotation),
    _scale(scale)
{

}

Transform::~Transform(void)
{

}

const glm::mat4 Transform::GetMatrix(void) const
{
    glm::mat4   result = glm::mat4(1);
    result = glm::translate(result, this->_position);
    result = glm::rotate(result, this->_rotation.x, glm::vec3(1.0, 0.0, 0.0));
    result = glm::rotate(result, this->_rotation.y, glm::vec3(0.0, 1.0, 0.0));
    result = glm::rotate(result, this->_rotation.z, glm::vec3(0.0, 0.0, 1.0));
    result = glm::scale(result, this->_scale);
    return result;
}
