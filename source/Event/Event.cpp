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

#include <utility>

#include "Engine/Event/Event.hpp"

namespace   Engine
{
    Event::Event(const Event::Type &event_type) :
        m_consumed(false),
        m_type(event_type)
    {

    }

    Event::Event(const Event &other) :
        m_consumed(other.m_consumed),
        m_type(other.m_type)
    {

    }

    Event::Event(Event &&other) noexcept :
        m_consumed(std::move(other.m_consumed)),
        m_type(std::move(other.m_type))
    {

    }

    Event::~Event(void) noexcept
    {
        // nothing to do.
    }



    Event &
    Event::operator=(const Event &other)
    {
        this->m_consumed = other.m_consumed;
        this->m_type = other.m_type;
        return *this;
    }

    Event &
    Event::operator=(Event &&other) noexcept
    {
         this->m_consumed = std::move(other.m_consumed);
         this->m_type = std::move(other.m_type);
         return *this;
    }



    bool
    Event::is_consumed() const
    {
        return this->m_consumed;
    }

    void
    Event::consume(void)
    {
        this->m_consumed = true;
    }
}
