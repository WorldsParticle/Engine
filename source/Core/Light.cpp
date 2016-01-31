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

#include    "Engine/Core/Light.hpp"
#include    "Engine/Core/Scene.hpp"
#include    "Engine/Core/SceneGraphNode.hpp"

using namespace     log4cpp;

namespace   Engine
{
    Light::Light(SceneGraphNode *node) :
        Entity(node)
    {
        this->m_node->setName("");
        this->m_scene->add(this);
    }

    /// TODO GSL NOT NULL
    Light::Light(const aiLight *assimpLight, SceneGraphNode *node) :
        Entity(node)
    {
        this->m_node->setName(assimpLight->mName.C_Str());
        this->m_scene->add(this);
    }

    Light::~Light(void) noexcept
    {
        // nothing to do atm.
    }




    Light *
    Light::clone(void) const
    {
         return new Light(*this);
    }

    void
    Light::update(void)
    {
        // nothing to do atm.
    }

}
