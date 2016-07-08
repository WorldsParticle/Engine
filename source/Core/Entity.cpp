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

#include    "Engine/Core/Entity.hpp"
#include    "Engine/Core/SceneGraphNode.hpp"

namespace   Engine
{
    Entity::Entity(SceneGraphNode *node) :
        m_node(node),
        m_scene(this->m_node->getScene()),
        m_transform_zero_test()
    {

    }

    Entity::Entity(Scene *scene) :
        m_node(nullptr),
        m_scene(scene),
        m_transform_zero_test()
    {

    }

    Entity::Entity(const Entity &other) :
        m_node(other.m_node),
        m_scene(this->m_node->getScene()),
        m_transform_zero_test()
    {

    }

    Entity::Entity(Entity &&other) :
        m_node(std::move(other.m_node)),
        m_scene(this->m_node->getScene()),
        m_transform_zero_test()
    {

    }

    Entity::~Entity(void)
    {

    }



    Entity &
    Entity::operator=(const Entity &other)
    {
        this->m_node = other.m_node;
        this->m_scene = this->m_node->getScene();
        return *this;
    }

    Entity &
    Entity::operator=(Entity &&other)
    {
        this->m_node = std::move(other.m_node);
        this->m_scene = this->m_node->getScene();
        return *this;
    }



    const std::string &
    Entity::getName(void) const
    {
        static  std::string s = ""; // because of return reference to temporary variable
        if (!this->m_node)
            return s;
         return this->m_node->getName();
    }

    const Transform &
    Entity::getTransform(void) const
    {
        if (!this->m_node)
            return m_transform_zero_test;
        return this->m_node->getTransform();
    }
    
    SceneGraphNode *    Entity::getNode() {
        return m_node;
    }

    void     Entity::setNode(SceneGraphNode * node) {
        m_node = node;
    }

    void    Entity::setTransform(Transform const& t)
    {
        if (m_node)
            m_node->setTransform(t);
        else
            m_transform_zero_test = t;
    }

}
