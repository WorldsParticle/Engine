///
/// \file SceneGraphNode.cpp
///
/// \author Martin-Pierrat Louis (mart_p)
///
/// \date Sat, 16 Jan 2016 20:52:16
///
/// \version 1.0.2
///

#include    <log4cpp/Category.hh>

#include    <Engine/SceneGraphNode.hpp>
#include    <Engine/SceneGraph.hpp>
#include    <Engine/AssimpScene.hpp>
#include    <Engine/PerspectiveCamera.hpp>
#include    <Engine/Light.hpp>
#include    <Engine/Object.hpp>

using namespace     log4cpp;

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
            scenegraph(scenegraph),
            scene(scenegraph->getScene()),
            entity(nullptr),
            transform()
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
            Category &root = Category::getRoot();
            root << Priority::DEBUG << "SceneGraphNode : " << this->name;
            if (!this->name.empty())
            {
                const aiCamera  *camera = nullptr;
                const aiLight   *light = nullptr;
                if ((camera = assimpScene.getCamera(this->name)) != nullptr)
                {
                    this->entity = new PerspectiveCamera(camera, this);
                }
                else if ((light = assimpScene.getLight(this->name)) != nullptr)
                {
                     this->entity = new Light(light, this);
                }
            }
            if (assimpNode->mNumMeshes > 0)
            {
                // if the name is empty and the meshes related to the node > 0
                // the node is an object.
                this->entity = new Object(assimpNode, this);
            }
            // we just need to create the others child.
            for (unsigned int i = 0 ; i < assimpNode->mNumChildren ; ++i)
            {
                SceneGraphNode  *child = new SceneGraphNode(assimpScene,
                        assimpNode->mChildren[i], scenegraph, this);
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
            //Category &root = Category::getRoot();

            //root << Priority::DEBUG << "SceneGraphNode update";
            //

            if (this->entity != nullptr)
            {
                this->entity->update();
            }
            for (SceneGraphNode *node : this->childrens)
            {
                 node->update();
            }
        }



        const std::string &
        SceneGraphNode::getName(void) const
        {
             return this->name;
        }

        SceneGraphNode *
        SceneGraphNode::getParent(void) const
        {
            return this->parent;
        }

        Scene *
        SceneGraphNode::getScene(void) const
        {
             return this->scene;
        }

        const Transform &
        SceneGraphNode::getTransform(void) const
        {
             return this->transform;
        }

    }
}

