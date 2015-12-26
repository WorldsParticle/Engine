#include    <log4cpp/Category.hh>

#include    "Light.hpp"

using namespace     log4cpp;

namespace   WorldParticles
{
    namespace   Engine
    {
        Light::Light(SceneGraphNode *node) :
            Entity(node),
            name("")
        {
            // nothing to do atm.
        }

        /// TODO GSL NOT NULL
        Light::Light(const aiLight *assimpLight, SceneGraphNode *node) :
            Entity(node),
            name(assimpLight->mName.C_Str())
        {
            // nothing to do atm.
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
            Category    &root = Category::getRoot();

            root << Priority::DEBUG << "Light - update()";
            // nothing to do atm.
        }

    }
}
