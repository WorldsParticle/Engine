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

using namespace     log4cpp;

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
