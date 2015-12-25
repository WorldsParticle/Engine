#include    "SceneGraphNode.hpp"

namespace   WorldParticles
{
    namespace   Engine
    {
        /// TODO add GSL NOT NULL
        SceneGraphNode::SceneGraphNode(SceneGraphNode *parent, Entity *entity) :
            name(""),
            parent(parent),
            sceneGraph(parent->sceneGraph),
            scene(parent->scene),
            entity(entity)
        {

        }

        SceneGraphNode::SceneGraphNode(const aiNode *assimpNode, SceneGraphNode *parent) :
            parent(parent)
        {

        }

        SceneGraphNode::~SceneGraphNode(void)
        {
            for (SceneGraphNode *node : this->childrens)
            {
                delete node;
            }
        }



        void
        SceneGraphNode::update(void)
        {
            this->entity->update();
            for (SceneGraphNode *node : this->childrens)
            {
                 node->update();
            }
        }

    }
}

