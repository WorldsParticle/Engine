#include    <log4cpp/Category.hh>

#include    "SceneGraph.hpp"
#include    "SceneGraphNode.hpp"
#include    "AssimpScene.hpp"

using namespace     log4cpp;

namespace   WorldParticles
{
    namespace   Engine
    {
        SceneGraph::SceneGraph(Scene *scene) :
            scene(scene),
            rootNode(nullptr)
        {
            // nothing to do.
        }

        /// TODO GSL NOT NULL
        SceneGraph::SceneGraph(const AssimpScene &s, Scene *scene) :
            scene(scene),
            rootNode(new SceneGraphNode(s, s.getRootNode(), this))
        {
            // nothing to do.
        }

        SceneGraph::SceneGraph(const SceneGraph &other) :
            scene(other.scene),
            rootNode(new SceneGraphNode(*other.rootNode))
        {
            // nothing to do.
        }

        SceneGraph::SceneGraph(SceneGraph &&other) noexcept :
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
        SceneGraph::operator=(SceneGraph &&other) noexcept
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



        Scene *
        SceneGraph::getScene(void) const
        {
            return this->scene;
        }
    }
}
