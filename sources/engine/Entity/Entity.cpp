#include    "Entity.hpp"
#include    "SceneGraphNode.hpp"

namespace   WorldParticles
{
    namespace   Engine
    {
        Entity::Entity(SceneGraphNode *node) :
            node(node),
            scene(this->node->getScene())
        {

        }

        Entity::Entity(const Entity &other) :
            node(other.node),
            scene(this->node->getScene())
        {

        }

        Entity::Entity(Entity &&other) :
            node(std::move(other.node)),
            scene(this->node->getScene())
        {

        }

        Entity::~Entity(void)
        {

        }



        Entity &
        Entity::operator=(const Entity &other)
        {
            this->node = other.node;
            this->scene = this->node->getScene();
            return *this;
        }

        Entity &
        Entity::operator=(Entity &&other)
        {
            this->node = std::move(other.node);
            this->scene = this->node->getScene();
            return *this;
        }



        const std::string &
        Entity::getName(void) const
        {
             return this->node->getName();
        }

    }
}
