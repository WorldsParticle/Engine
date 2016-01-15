///
/// \file AnimationLibrary.cpp
///
/// \author Martin-Pierrat Louis (mart_p)
///
/// \date Fri, 15 Jan 2016 13:28:08
///
/// \version 1.0.1
///

#include    "AnimationLibrary.hpp"
#include    "Animation.hpp"

namespace   WorldParticles
{
    namespace   Engine
    {
        AnimationLibrary::AnimationLibrary(void) :
            Library<Animation *>()
        {
            // nothing to do.
        }

        AnimationLibrary::AnimationLibrary(aiAnimation **assimpAnimations,
                unsigned int size) :
            Library<Animation *>()
        {
            this->resources.reserve(size);
            for (unsigned int i = 0 ; i < size ; ++i)
            {
                this->resources.push_back(new Animation(assimpAnimations[i]));
            }
        }

        AnimationLibrary::AnimationLibrary(const AnimationLibrary &other) :
            Library<Animation *>()
        {
            this->resources.reserve(other.resources.size());
            for (Animation *resource : other.resources)
            {
                this->resources.push_back(new Animation(*resource));
            }
        }

        AnimationLibrary::~AnimationLibrary(void)
        {
            for (Animation *resource : this->resources)
            {
                delete resource;
            }
        }



        AnimationLibrary &
        AnimationLibrary::operator=(const AnimationLibrary &other)
        {
            this->resources.reserve(other.resources.size());
            for (Animation *resource : other.resources)
            {
                this->resources.push_back(new Animation(*resource));
            }
            return *this;
        }
    }
}
