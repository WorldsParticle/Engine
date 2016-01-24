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

#include    "Engine/Core/Animation.hpp"

namespace   Engine
{
    Animation::Animation(void) :
        name("")
    {
        // nothing more to do actually.
    }

    // TODO GSL NOT NULL
    Animation::Animation(const aiAnimation *assimpAnimation) :
        name(assimpAnimation->mName.C_Str())
    {
        // TODO
    }

    Animation::Animation(const Animation &other) :
        name(other.name)
    {
        // nothing more to do actually.
    }

    Animation::Animation(Animation &&other) noexcept :
        name(std::move(other.name))
    {
        // nothing more to do actually.
    }

    Animation::~Animation(void)
    {

    }



    Animation &
    Animation::operator=(const Animation &other)
    {
        this->name = other.name;
        return *this;
    }

    Animation &
    Animation::operator=(Animation &&other) noexcept
    {
        this->name = std::move(other.name);
        return *this;
    }

}
