#include    "SceneGraphNode.hpp"

namespace   WorldParticles
{
    namespace   Engine
    {
        SceneGraphNode::SceneGraphNode(SceneGraphNode *parent) :
            parent(parent)
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
    }
}

