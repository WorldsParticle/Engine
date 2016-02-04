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

#include    "Engine/Core/SceneGraph.hpp"
#include    "Engine/Core/SceneGraphNode.hpp"
#include    "Engine/Core/AssimpScene.hpp"
#include    "Engine/Core/PerspectiveCamera.hpp"

using namespace     log4cpp;

namespace   Engine
{
    SceneGraph::SceneGraph(Scene *scene) :
        m_scene(scene),
        m_rootNode(nullptr)
    {
        // nothing to do.
    }

    /// TODO GSL NOT NULL
    SceneGraph::SceneGraph(const AssimpScene &s, Scene *scene) :
        m_scene(scene),
        m_rootNode(new SceneGraphNode(s, s.getRootNode(), this))
    {
#warning temporary
        SceneGraphNode  *node = new SceneGraphNode(this);
        node->setName("DefaultCamera");
        Entity *camera = new PerspectiveCamera(node);
        node->setEntity(camera);
        this->m_rootNode->addChildren(node);

        // nothing to do.
    }

    SceneGraph::SceneGraph(const SceneGraph &other) :
        m_scene(other.m_scene),
        m_rootNode(new SceneGraphNode(*other.m_rootNode))
    {
        // nothing to do.
    }

    SceneGraph::SceneGraph(SceneGraph &&other) noexcept :
        m_scene(other.m_scene),
        m_rootNode(other.m_rootNode)
    {
        other.m_rootNode = nullptr;
    }

    SceneGraph::~SceneGraph(void)
    {
        delete this->m_rootNode;
    }



    SceneGraph &
    SceneGraph::operator=(const SceneGraph &other)
    {
        this->m_scene = other.m_scene;
        this->m_rootNode = new SceneGraphNode(*other.m_rootNode);
        return *this;
    }

    SceneGraph &
    SceneGraph::operator=(SceneGraph &&other) noexcept
    {
        this->m_scene = other.m_scene;
        this->m_rootNode = other.m_rootNode;
        other.m_rootNode = nullptr;
        return *this;
    }



    void
    SceneGraph::update(void)
    {
        if (this->m_rootNode != nullptr)
        {
             this->m_rootNode->update();
        }
    }



    Scene *
    SceneGraph::getScene(void) const
    {
        return this->m_scene;
    }
}
