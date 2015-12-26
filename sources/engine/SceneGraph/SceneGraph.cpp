#include    "SceneGraph.hpp"

namespace   WorldParticles
{
    namespace   Engine
    {
        SceneGraph(Scene *parent) :
            parent(parent),
            rootNode(nullptr)
        {
            // nothing to do.
        }

        /// TODO GSL NOT NULL
        SceneGraph::SceneGraph(const AssimpScene &aiScene, Scene *scene) :
            scene(scene),
            rootNode(new SceneGraphNode(aiScene, aiScene->getRootNode(), this))
        {
            // nothing to do.
        }

        SceneGraph::SceneGraph(const SceneGraph &other) :
            scene(other.scene),
            rootNode(new SceneGraphNode(*other.rootNode))
        {
            // nothing to do.
        }

        SceneGraph::SceneGraph(SceneGraph &&other) :
            scene(other.scene),
            rootNode(other.rootNode)
        {
            other.rootNode = nullptr;
        }

        SceneGraph::~SceneGraph(void)
        {
            delete this->rootNode;
        }



        SceneGraph &
        SceneGraph::operator=(const SceneGraph &other)
        {
            this->scene = other.scene;
            this->rootNode = new SceneGraphNode(*other.rootNode);
            return *this;
        }

        SceneGraph &
        SceneGraph::operator=(SceneGraph &&other)
        {
            this->scene = other.scene;
            this->rootNode = other.rootNode;
            other.rootNode = nullptr;
            return *this;
        }



        void
        SceneGraph::update(void)
        {
            if (this->rootNode != nullptr)
            {
                 this->rootNode->update();
            }
        }
    }
}
