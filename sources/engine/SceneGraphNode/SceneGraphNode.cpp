#include    "SceneGraphNode.hpp"

namespace   WorldParticles
{
    namespace   Engine
    {
        /// TODO add GSL NOT NULL
        SceneGraphNode::SceneGraphNode(SceneGraph *scenegraph,
                SceneGraphNode *parent) :
            name(""),
            parent(parent),
            childrens(),
            sceneGraph(scenegraph),
            scene(scenegraph->getScene()),
            entity(nullptr)
        {

        }

        SceneGraphNode::SceneGraphNode(const AssimpScene &assimpScene,
                const aiNode *assimpNode, SceneGraph *scenegraph,
                SceneGraphNode *parent) :
            name(assimpNode->mName.C_Str()),
            parent(parent),
            childrens(),
            scenegraph(scenegraph),
            scene(scenegraph->getScene()),
            entity(nullptr),
            transform(assimpNode->mTransformation)
        {
            if (!this->name.empty())
            {
                const aiCamera  *camera = nullptr;
                const aiLight   *light = nullptr;
                if ((camera = assimpScene->getCamera(this->name)) != nullptr)
                {
                    this->entity = new PerspectiveCamera(result);
                }
                else if ((light = assimpScene->getLight(this->name)) != nullptr)
                {
                     this->entity = new Light(light);
                }
            }
            else if (assimpNode->mNumMeshes > 0)
            {
                // if the name is empty and the meshes related to the node > 0
                // the node is an object.
                this->entity = new Object(assimpNode->mMeshes, assimpNode->mNumMeshes);
            }
            // we just need to create the others child.
            for (unsigned int i = 0 ; i < assimpNode->mNumChildren ; ++i)
            {
                const aiNode    *assimpChild = assimpNode->mChildren[i];
                SceneGraphNode  *child = new SceneGraphNode(assimpScene,
                        assimpChild, scenegraph, this);
                this->childrens.push_back(child);
            }
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
            if (this->entity != nullptr)
            {
                this->entity->update();
            }
            for (SceneGraphNode *node : this->childrens)
            {
                 node->update();
            }
        }

    }
}

