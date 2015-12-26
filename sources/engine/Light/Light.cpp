#include    "Light.hpp"


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
            // nothing to do atm.
        }

    }
}
