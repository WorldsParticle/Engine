#include    "GameObject.hpp"

GameObject::GameObject(const glm::vec3 &position, const glm::vec3 &rotation, const glm::vec3 &scale) :
    transform(position, rotation, scale)
{

}
