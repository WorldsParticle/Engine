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

#include    "Engine/Core/AnimationLibrary.hpp"
#include    "Engine/Core/Animation.hpp"

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
