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
        node(node),
        scene(this->node->getScene())
    {

    }

    Entity::Entity(const Entity &other) :
        node(other.node),
        scene(this->node->getScene())
    {

    }

    Entity::Entity(Entity &&other) :
        node(std::move(other.node)),
        scene(this->node->getScene())
    {

    }

    Entity::~Entity(void)
    {

    }



    Entity &
    Entity::operator=(const Entity &other)
    {
        this->node = other.node;
        this->scene = this->node->getScene();
        return *this;
    }

    Entity &
    Entity::operator=(Entity &&other)
    {
        this->node = std::move(other.node);
        this->scene = this->node->getScene();
        return *this;
    }



    const std::string &
    Entity::getName(void) const
    {
         return this->node->getName();
    }

    const Transform &
    Entity::getTransform(void) const
    {
        return this->node->getTransform();
    }
}
