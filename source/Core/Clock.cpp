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

#include    <utility>

#include    "Engine/Core/Clock.hpp"

namespace Engine
{

    Clock::Clock(void) :
        m_time_point(),
        m_elapsed_time(0.0f),
        m_stopped(true)
    {

    }

    Clock::Clock(const Clock &other) :
        m_time_point(other.m_time_point),
        m_elapsed_time(other.m_elapsed_time),
        m_stopped(other.m_stopped)
    {

    }

    Clock::Clock(Clock &&other) noexcept :
        m_time_point(std::move(other.m_time_point)),
        m_elapsed_time(std::move(other.m_elapsed_time)),
        m_stopped(std::move(other.m_stopped))
    {

    }

    Clock::~Clock(void)
    {

    }



    Clock &
    Clock::operator=(const Clock &other)
    {
        this->m_time_point = other.m_time_point;
        this->m_elapsed_time = other.m_elapsed_time;
        this->m_stopped = other.m_stopped;
        return *this;
    }

    Clock &
    Clock::operator=(Clock &&other) noexcept
    {
        this->m_time_point = std::move(other.m_time_point);
        this->m_elapsed_time = std::move(other.m_elapsed_time);
        this->m_stopped = std::move(other.m_stopped);
        return *this;
    }



    float
    Clock::elapsed_time(void) const
    {
         return this->m_elapsed_time;
    }

    bool
    Clock::stopped(void) const
    {
         return this->m_stopped;
    }



    void
    Clock::restart(void)
    {
        if (this->m_stopped == true)
        {
            this->m_time_point = std::chrono::steady_clock::now();
            this->m_stopped = false;
        }
        auto now = std::chrono::steady_clock::now();
        std::chrono::duration<float>    diff = now - this->m_time_point;
        this->m_elapsed_time = diff.count();
        this->m_time_point = now;
    }

    void
    Clock::stop(void)
    {
         this->m_stopped = true;
    }

}
