#include    <log4cpp/Category.hh>

#include    "Light.hpp"
#include    "Scene.hpp"

using namespace     log4cpp;

namespace   WorldParticles
{
    namespace   Engine
    {
        Light::Light(SceneGraphNode *node) :
            Entity(node),
            name("")
        {
            this->scene->add(this);
        }

        /// TODO GSL NOT NULL
        Light::Light(const aiLight *assimpLight, SceneGraphNode *node) :
            Entity(node),
            name(assimpLight->mName.C_Str())
        {
            this->scene->add(this);
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



        const std::string &
        Light::getName(void) const
        {
             return this->name;
        }

    }
}
