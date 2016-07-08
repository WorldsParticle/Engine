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

#include    "Engine/Core/Object.hpp"
#include    "Engine/Core/Scene.hpp"
#include    "Engine/Core/SceneGraphNode.hpp"

using namespace     log4cpp;

namespace   Engine
{
    Object::Object(SceneGraphNode *node) :
        Entity(node),
        m_meshes()
    {
        this->m_scene->add(this);
                
//        Transform titi;
//        titi.translate(glm::vec3(rand() % 50, rand() % 50,0));
//
//        node->setTransform(titi);
//        node->getTransform().print();
    }


    Object::Object(Scene *scene) :
    Entity(scene),
    m_meshes()
    {
        this->m_scene->add(this);
    }

    // TODO GSL NOT NULL
    Object::Object(const aiNode *assimpNode, SceneGraphNode *node, unsigned int previousMeshNumber) :
        Entity(node),
        m_meshes()
    {
        Category &root = Category::getRoot();
        std::cout << "Création object" << std::endl;
        for (unsigned int i = 0 ; i < assimpNode->mNumMeshes ; ++i)
        {
            auto *mesh = this->m_scene->getMesh(assimpNode->mMeshes[i] + previousMeshNumber);
            this->m_meshes.push_back(mesh);

            mesh->m_name = std::string(assimpNode->mName.C_Str());
            std::cout << "mesh " << mesh->m_name << std::endl;
        }
        this->m_scene->add(this);
    }

    Object::~Object(void)
    {

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

    void
    Object::moveToScene(SceneGraphNode *node)
    {
	std::cout << "moved to another scene " << getName() << std::endl;
        this->m_node = node;
        this->m_scene = node->getScene();
        this->m_scene->add(this);
    }


    const std::list<Mesh *> &
    Object::getMeshes(void) const
    {
	//int i = 0;
	//for (auto tmp = m_meshes.begin(); tmp != m_meshes.end(); tmp++) {
	//    std::cout << (*tmp)->getName() << " is number " << i << std::endl;
	//    i++;
	//}
        return this->m_meshes;
    }

}
