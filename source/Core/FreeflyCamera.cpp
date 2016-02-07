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
#include    <functional>

#include    "Engine/Core/Scene.hpp"
#include    "Engine/Core/SceneGraphNode.hpp"
#include    "Engine/Core/FreeflyCamera.hpp"
#include    "Engine/Event/Event.hpp"

using namespace     log4cpp;

namespace   Engine
{

    FreeflyCamera::FreeflyCamera(SceneGraphNode *node) :
        PerspectiveCamera(node)
    {
/*        this->m_projection = glm::perspective(this->m_fov, this->m_aspect,*/
                //this->m_clippingPlane.near, this->m_clippingPlane.far);
        //this->m_view = glm::lookAt(this->m_position, this->m_lookat, this->m_up);
        std::function<void(const Event &)> callback =
            std::bind(&FreeflyCamera::test_input, this, std::placeholders::_1);

        node->getScene()->register_callback(Event::Type::KEY_PRESSED,
                callback);
    }

    FreeflyCamera::~FreeflyCamera(void)
    {

    }



    void
    FreeflyCamera::test_input(const Event &event)
    {
        Category    &root = Category::getRoot();

        root << Priority::DEBUG << "EVENT IN THE FREEFLY CAMERA";
    }

}
