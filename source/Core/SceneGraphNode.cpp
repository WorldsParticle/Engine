//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 3 of the License, or
// any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this program; If not, see <http://www.gnu.org/licenses/>.
//
// Copyright (C) 2016 Martin-Pierrat Louis (louismartinpierrat@gmail.com)
//

#include    <algorithm>
#include    <log4cpp/Category.hh>

#include    "Engine/Core/SceneGraphNode.hpp"
#include    "Engine/Core/SceneGraph.hpp"
#include    "Engine/Core/AssimpScene.hpp"
#include    "Engine/Core/PerspectiveCamera.hpp"
#include    "Engine/Core/Light.hpp"
#include    "Engine/Core/Object.hpp"
#include    "Engine/Core/FreeflyCamera.hpp"

using namespace     log4cpp;

namespace   Engine
{
    /// TODO add GSL NOT NULL
    SceneGraphNode::SceneGraphNode(SceneGraph *scenegraph,
            SceneGraphNode *parent) :
        m_name(""),
        m_parent(parent),
        m_childrens(),
        m_scenegraph(scenegraph),
        m_entity(nullptr),
        m_transform(),
        m_worldTransform()
    {

    }

    SceneGraphNode::SceneGraphNode(const AssimpScene &assimpScene,
            const aiNode *assimpNode, SceneGraph *scenegraph,
            ShaderProgramLibrary &shaderprograms, SceneGraphNode *parent,
            bool meshOnly, unsigned int previousMeshNumber) :
        m_name(assimpNode->mName.C_Str()),
        m_parent(parent),
        m_childrens(),
        m_scenegraph(scenegraph),
        m_entity(nullptr),
        m_transform(assimpNode->mTransformation),
        m_worldTransform(assimpNode->mTransformation)
    {
        Category &root = Category::getRoot();
//        root << Priority::DEBUG << "SceneGraphNode : " << this->m_name;
//        root << Priority::DEBUG << "SceneGraphNode scene : " << this->getScene();
        if (!this->m_name.empty() && !meshOnly)
        {
            const aiCamera  *camera = nullptr;
            const aiLight   *light = nullptr;
            if ((camera = assimpScene.getCamera(this->m_name)) != nullptr)
            {
                this->m_entity = new FreeflyCamera(this, shaderprograms);
            }
            else if ((light = assimpScene.getLight(this->m_name)) != nullptr)
            {
                 this->m_entity = new Light(light, this);
            }
        }
        root << Priority::DEBUG << "nummesh : " << assimpNode->mNumMeshes;
        root << Priority::DEBUG << "SceneGraphNode scene : " << this->getScene();
        if (assimpNode->mNumMeshes > 0)
        {
            // if the name is empty and the meshes related to the node > 0
            // the node is an object.
            this->m_entity = new Object(assimpNode, this, previousMeshNumber);
            root << Priority::DEBUG << "SceneGraphNode have an entity : " << this->getEntity()->getName();
        }

        // we just need to create the others child.
        for (unsigned int i = 0 ; i < assimpNode->mNumChildren ; ++i)
        {
            SceneGraphNode  *child = new SceneGraphNode(assimpScene,
                    assimpNode->mChildren[i], scenegraph, shaderprograms, this,
		    meshOnly, previousMeshNumber);
            this->m_childrens.push_back(child);
        }
    }
    
    SceneGraphNode::SceneGraphNode(const SceneGraphNode &other)
    :   m_name(other.m_name),
        m_parent(other.m_parent),
        m_childrens(),
        m_scenegraph(other.m_scenegraph),
        m_entity(other.m_entity),//TODO cpy instead
        m_transform(other.m_transform),
        m_worldTransform(other.m_worldTransform)
    {
        Object* obj = dynamic_cast<Object*>(other.m_entity);
        if (obj)
        {
            m_entity = new Object(*obj);
            m_entity->setNode(this);
        }
        //TODO copy children
    }
    
    SceneGraphNode::SceneGraphNode(SceneGraphNode &&other) noexcept
    :   m_name(other.m_name),
        m_parent(other.m_parent),
        m_childrens(),
        m_scenegraph(other.m_scenegraph),
        m_entity(other.m_entity),//TODO cpy instead
        m_transform(other.m_transform),
        m_worldTransform(other.m_worldTransform)
    {
        //TODO copy children
    }

    

    SceneGraphNode::~SceneGraphNode(void)
    {
        for (SceneGraphNode *node : this->m_childrens)
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

        if (this->m_entity != nullptr)
        {
            this->m_entity->update();
        }
        for (SceneGraphNode *node : this->m_childrens)
        {
             node->update();
        }
    }



    const std::string &
    SceneGraphNode::getName(void) const
    {
         return this->m_name;
    }

    SceneGraphNode *
    SceneGraphNode::getParent(void) const
    {
        return this->m_parent;
    }

    Scene *
    SceneGraphNode::getScene(void) const
    {
         return this->m_scenegraph->getScene();
    }

    Transform &
    SceneGraphNode::getTransform(void)
    {
        if (m_parent)
        {
            m_worldTransform = this->m_transform;
            m_worldTransform.multiplyBy(this->m_parent->getTransform());
            return m_worldTransform;
        }
        return this->m_transform;
    }

    Entity *
    SceneGraphNode::getEntity(void) const
    {
        return this->m_entity;
    }

    void
    SceneGraphNode::setName(const std::string &name)
    {
         this->m_name = name;
    }

    void
    SceneGraphNode::setParent(SceneGraphNode *parent)
    {
        this->m_parent = parent;
    }

    void
    SceneGraphNode::setEntity(Entity *entity)
    {
         this->m_entity = entity;
    }

    void
    SceneGraphNode::setTransform(Transform const& transform)
    {
        //TMP, fix getTransform instead !
        std::for_each(m_childrens.begin(), m_childrens.end(), [&](SceneGraphNode * child){
            child->setTransform(transform);
        });
         this->m_transform = transform;
    }

    void
    SceneGraphNode::addChildren(SceneGraphNode *child)
    {
//        Category &root = Category::getRoot();
//        root << Priority::DEBUG << "SceneGraphNode add children : " << this->m_name;

        child->m_parent = this;
        this->m_childrens.push_back(child);
    }

}

