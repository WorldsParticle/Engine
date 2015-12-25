#include    "Entity.hpp"

namespace   WorldParticles
{
    namespace   Engine
    {
        Entity::Entity(SceneGraphNode *node) : // TODO GSL NOT NULL
            node(node),
            scene(this->node->scene)
        {

        }

        Entity::Entity(const Entity &other) :
            node(other.node),
            scene(this->node->scene)
        {

        }

        Entity::Entity(Entity &&other) :
            node(std::mode(other.node)),
            scene(this->node->scene)
        {

        }

        Entity::~Entity(void)
        {

        }



        Entity &
        Entity::operator=(const Entity &other)
        {
            this->node = other.node;
            this->scene = this->node->scene;
            return *this;
        }

        Entity &
        Entity::operator=(Entity &&other)
        {
            this->node = std::move(other.node);
            this->scene = this->node->scene;
            return *this;
        }

    }
}
