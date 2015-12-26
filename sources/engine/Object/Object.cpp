#include    <log4cpp/Category.hh>

#include    "Object.hpp"
#include    "Scene.hpp"

using namespace     log4cpp;

namespace   WorldParticles
{
    namespace   Engine
    {
        Object::Object(SceneGraphNode *node) :
            Entity(node)
        {

        }

        // TODO GSL NOT NULL
        Object::Object(const aiNode *assimpNode, SceneGraphNode *node) :
            Entity(node)
        {

            for (unsigned int i = 0 ; i < assimpNode->mNumMeshes ; ++i)
            {
                this->scene->getMesh(assimpNode->mMeshes[i]);
            }

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

            Category    &root = Category::getRoot();

            root << Priority::DEBUG << "Object - update()";
            // nothing to do actually.
        }

    }
}
