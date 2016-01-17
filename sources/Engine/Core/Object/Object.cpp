///
/// \file Object.cpp
///
/// \author Martin-Pierrat Louis (mart_p)
///
/// \date Sat, 16 Jan 2016 20:49:23
///
/// \version 1.0.2
///

#include    <log4cpp/Category.hh>

#include    <Engine/Object.hpp>
#include    <Engine/Scene.hpp>

using namespace     log4cpp;

namespace   WorldParticles
{
    namespace   Engine
    {
        Object::Object(SceneGraphNode *node) :
            Entity(node)
        {
            this->scene->add(this);
        }

        // TODO GSL NOT NULL
        Object::Object(const aiNode *assimpNode, SceneGraphNode *node) :
            Entity(node)
        {
            Category &root = Category::getRoot();
            root << Priority::DEBUG << "Création object";
            for (unsigned int i = 0 ; i < assimpNode->mNumMeshes ; ++i)
            {
                root << Priority::DEBUG << "Add mesh";
                auto *mesh = this->scene->getMesh(assimpNode->mMeshes[i]);
                this->meshes.push_back(mesh);
            }

            this->scene->add(this);

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


        const std::list<Mesh *> &
        Object::getMeshes(void) const
        {
            return this->meshes;
        }



    }
}
