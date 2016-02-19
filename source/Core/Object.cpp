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

#include    <functional>
#include    <log4cpp/Category.hh>

#include    "Engine/Core/SceneGraphNode.hpp"
#include    "Engine/Event/Event.hpp"
#include    "Engine/Event/KeyPressed.hpp"
#include    "Engine/Input/Keyboard/Key.hpp"
#include    "Engine/Core/Object.hpp"
#include    "Engine/Core/Scene.hpp"
#include    "Engine/MeshDataStructure/Mesh.hpp"

using namespace     log4cpp;

namespace   Engine
{
    Object::Object(SceneGraphNode *node) :
        Entity(node),
        m_meshes()
    {
        this->m_scene->add(this);
    }

    // TODO GSL NOT NULL
    Object::Object(const aiNode *assimpNode, SceneGraphNode *node) :
        Entity(node),
        m_meshes()
    {
        using namespace     std::placeholders;
        Category &root = Category::getRoot();
        root << Priority::DEBUG << "Création object";
        for (unsigned int i = 0 ; i < assimpNode->mNumMeshes ; ++i)
        {
            root << Priority::DEBUG << "Add mesh";
            auto *mesh = this->m_scene->getMesh(assimpNode->mMeshes[i]);
            this->m_meshes.push_back(mesh);
        }
        this->m_scene->add(this);

        node->getScene()->register_callback(Event::Type::KEY_PRESSED,
                std::bind(&Object::on_key_pressed, this, _1));
    }

    Object::~Object(void)
    {

    }

    void
    Object::on_key_pressed(const Event::Event &event)
    {
        const Event::KeyPressed *key_pressed_event =
            dynamic_cast<const Event::KeyPressed *>(&event);

        if (key_pressed_event != nullptr)
        {
            switch (key_pressed_event->get_key())
            {
                case Keyboard::Key::Add:
                    {
                        for (Mesh *mesh : this->m_meshes)
                        {
                            mesh->increase();
                        }
                        break;
                    }
                case Keyboard::Key::Substract:
                    {
                        for (Mesh *mesh : this->m_meshes)
                        {
                            mesh->reduce();
                        }
                        break;
                    }
                default:
                    break;
            }
        }
    }

    Object *
    Object::clone(void) const
    {
        return new Object(*this);
    }

    void
    Object::update(void)
    {
        //Category    &root = Category::getRoot();

        //root << Priority::DEBUG << "Object - update()";
        // nothing to do actually.
    }


    const std::list<Mesh *> &
    Object::getMeshes(void) const
    {
        return this->m_meshes;
    }

}