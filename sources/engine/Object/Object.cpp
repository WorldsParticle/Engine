#include    "Object.hpp"

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

        Object::Object(const Object &other) :
            Entity(other)
        {

        }

        Object::Object(Object &&other) :
            Entity(std::move(other))
        {

        }

        Object::~Object(void)
        {

        }



        Object &
        Object::operator=(const Object &other)
        {
            return *this;
        }

        Object &
        Object::operator=(const Object &&other)
        {

        }



        void
        Object::update(void)
        {
            // nothing to do actually.
        }

    }
}
