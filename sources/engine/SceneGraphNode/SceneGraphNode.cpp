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

        SceneGraphNode::SceneGraphNode(const aiNode *assimpNode,
                const std::map<std::string, Entity *> entities,
                SceneGraph *scenegraph, SceneGraphNode *parent) :
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
                // If the name is not empty, the node is a Camera or a Light.
                auto    &it = entities.find(this->name);
                // we look into the preloaded Camera & Light by the AssimpImporter
                if (it != entities.end())
                {
                    // if we find something that match, we clone it.
                    this->entity = it->clone();
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
                SceneGraphNode  *child = new SceneGraphNode(assimpNode->mChildren[i],
                        entities, scenegraph, this);
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

