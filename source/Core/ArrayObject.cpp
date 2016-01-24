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

#include    <GL/glew.h>
#include    <utility>

#include    "Engine/Core/ArrayObject.hpp"

namespace   Engine
{

    ArrayObject::ArrayObject(void)
    {
        glGenVertexArrays(1, &this->id);
    }

    ArrayObject::ArrayObject(ArrayObject &&other) noexcept :
        id(std::move(other.id))
    {
        other.id = 0;
    }

    ArrayObject::~ArrayObject(void)
    {
        glDeleteVertexArrays(1, &this->id);
    }



    ArrayObject &
    ArrayObject::operator=(ArrayObject &&other) noexcept
    {
        this->id = std::move(id);
        other.id = 0;
        return *this;
    }



    void
    ArrayObject::bind(void) const
    {
        glBindVertexArray(this->id);
    }

    void
    ArrayObject::unbind(void) const
    {
        glBindVertexArray(0);
    }
}
