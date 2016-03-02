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
        Library<std::string, Animation *>()
    {
        // nothing to do.
    }

    AnimationLibrary::AnimationLibrary(aiAnimation **assimpAnimations,
            unsigned int size) :
        Library<std::string, Animation *>()
    {
        for (unsigned int i = 0 ; i < size ; ++i)
        {
            std::string name = assimpAnimations[i]->mName.C_Str();
            this->m_resources.insert(
                    std::make_pair(name, new Animation(assimpAnimations[i])));
        }
    }

    AnimationLibrary::AnimationLibrary(const AnimationLibrary &other) :
        Library<std::string, Animation *>()
    {
        for (const auto &key_value : other.m_resources)
        {
            this->m_resources.insert(
                    std::make_pair(key_value.first, new Animation(*key_value.second)));
        }
    }

    AnimationLibrary::~AnimationLibrary(void)
    {
        for (const auto &key_value : this->m_resources)
        {
            delete key_value.second;
        }
    }



    AnimationLibrary &
    AnimationLibrary::operator=(const AnimationLibrary &other)
    {
        for (const auto &key_value : other.m_resources)
        {
            this->m_resources.insert(
                    std::make_pair(key_value.first, new Animation(*key_value.second)));
        }
        return *this;
    }
}
