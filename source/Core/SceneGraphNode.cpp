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
        m_transform()
    {

    }

    SceneGraphNode::SceneGraphNode(const AssimpScene &assimpScene,
            const aiNode *assimpNode, SceneGraph *scenegraph,
            ShaderProgramLibrary &shaderprograms, SceneGraphNode *parent,
            bool meshOnly) :
        m_name(assimpNode->mName.C_Str()),
        m_parent(parent),
        m_childrens(),
        m_scenegraph(scenegraph),
        m_entity(nullptr),
        m_transform(assimpNode->mTransformation)
    {
        Category &root = Category::getRoot();
        root << Priority::DEBUG << "SceneGraphNode : " << this->m_name;
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
        if (assimpNode->mNumMeshes > 0)
        {
            // if the name is empty and the meshes related to the node > 0
            // the node is an object.
            this->m_entity = new Object(assimpNode, this);
        }
        // we just need to create the others child.
        for (unsigned int i = 0 ; i < assimpNode->mNumChildren ; ++i)
        {
            SceneGraphNode  *child = new SceneGraphNode(assimpScene,
                    assimpNode->mChildren[i], scenegraph, shaderprograms, this);
            this->m_childrens.push_back(child);
        }
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

    const Transform &
    SceneGraphNode::getTransform(void) const
    {
         return this->m_transform;
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
    SceneGraphNode::addChildren(SceneGraphNode *child)
    {
        child->m_parent = this;
        this->m_childrens.push_back(child);
    }

}

