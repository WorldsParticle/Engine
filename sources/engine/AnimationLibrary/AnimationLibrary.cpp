#include    "AnimationLibrary.hpp"
#include    "Animation.hpp"

namespace   WorldParticles
{
    namespace   Engine
    {
        AnimationLibrary::AnimationLibrary(void) :
            Library<Animation>()
        {
            // nothing to do.
        }

        AnimationLibrary::AnimationLibrary(aiAnimation **assimpAnimations, unsigned int size) :
            Library<Animation>()
        {
            this->resources.reserve(size);
            for (unsigned int i = 0 ; i < size ; ++i)
            {
                this->resources.push_back(new Animation(assimpAnimations[i]));
            }
        }

        AnimationLibrary::~AnimationLibrary(void)
        {
            // nothing to do.
        }
    }
}
