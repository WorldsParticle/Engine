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
#include    "Engine/Core/FreeflyCamera.hpp"
#include    "Engine/Core/ShaderProgramLibrary.hpp"

using namespace     log4cpp;

namespace   Engine
{
    SceneGraph::SceneGraph(Scene *scene, ShaderProgramLibrary &shaderprograms) :
        m_scene(scene),
        m_rootNode(nullptr),
	m_shaderprograms(shaderprograms)
    {
        // nothing to do.
    }

    /// TODO GSL NOT NULL
    SceneGraph::SceneGraph(const AssimpScene &s, Scene *scene, ShaderProgramLibrary &shaderprograms) :
        m_scene(scene),
        m_rootNode(new SceneGraphNode(s, s.getRootNode(), this, shaderprograms)),
	m_shaderprograms(shaderprograms)
    {
        //#warning TODO temporary
//        if (s.getCameraNumber() == 0)
//        {
            SceneGraphNode  *node = new SceneGraphNode(this);
            node->setName("DefaultCamera");
            Entity *camera = new FreeflyCamera(node, shaderprograms);
            node->setEntity(camera);
            this->m_rootNode->addChildren(node);
//        }

        // nothing to do.
    }

    SceneGraph::SceneGraph(const SceneGraph &other) :
        m_scene(other.m_scene),
        m_rootNode(new SceneGraphNode(*other.m_rootNode)),
	m_shaderprograms(other.m_shaderprograms)
    {
        // nothing to do.
    }

    SceneGraph::SceneGraph(SceneGraph &&other) noexcept :
        m_scene(other.m_scene),
        m_rootNode(other.m_rootNode),
	m_shaderprograms(other.m_shaderprograms)
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
	this->m_shaderprograms = other.m_shaderprograms;
        return *this;
    }

    SceneGraph &
    SceneGraph::operator=(SceneGraph &&other) noexcept
    {
        this->m_scene = other.m_scene;
        this->m_rootNode = other.m_rootNode;
        other.m_rootNode = nullptr;
	this->m_shaderprograms = other.m_shaderprograms;
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

    SceneGraphNode *
    SceneGraph::getRootNode(void) const
    {
        return this->m_rootNode;
    }
}
