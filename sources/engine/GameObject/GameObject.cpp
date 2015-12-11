#include    "GameObject.hpp"

namespace   WorldParticles
{
    namespace   Engine
    {

        GameObject::GameObject(const glm::vec3 &position,
                const glm::vec3 &rotation,
                const glm::vec3 &scale) :
            _transform(position, rotation, scale)
        {

        }

        GameObject::~GameObject(void)
        {

        }

    }
}
