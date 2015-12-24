#include    "SceneGraph.hpp"

namespace   WorldParticles
{
    namespace   Engine
    {
        SceneGraph(Scene *parent) :
            parent(parent),
            rootNode(nullptr)
        {

        }

        SceneGraph(const aiNode *assimpNode, Scene *parent) :
            parent(parent),
            rootNode(nullptr)
        {
        }

        SceneGraph::~SceneGraph(void)
        {
            delete this->rootNode;
        }

        void
        SceneGraph::update(void)
        {
            // TODO fill function
        }
    }
}
