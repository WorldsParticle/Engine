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

#pragma once

#include    <chrono>

#include    "Engine/Configuration.hpp"

namespace Engine
{
    ///
    /// \brief This class is used to represent the clock between frame and the world clock.
    ///
    /// This class should be entirely reworked.
    ///
    class ENGINE_EXPORTS Clock
    {
        public:
            ///
            /// \brief Default constructor.
            ///
            Clock(void);

            ///
            /// \brief Copy constructor.
            ///
            Clock(const Clock &other);

            ///
            /// \brief Move constructor.
            ///
            Clock(Clock &&other) noexcept;

            ///
            /// \brief Destructor.
            ///
            ~Clock(void);

        public:
            ///
            /// \brief Copy assignment operator.
            ///
            Clock   &operator=(const Clock &other);

            ///
            /// \brief Move assignment operator.
            ///
            Clock   &operator=(Clock &&other) noexcept;

        public:
            ///
            /// \brief Return the elapsed time between the previous two call of
            /// the restart method.
            ///
            float   elapsed_time(void) const;

            ///
            /// \brief Return true if the clock is stopped, false otherwise.
            ///
            bool    stopped(void) const;

        public:

            ///
            /// \brief Restart the clock timer. If the clock was stopped,
            /// relaunch it.
            ///
            void    restart(void);

            ///
            /// \brief Stop the clock
            ///
            void    stop(void);

        private:
            ///
            /// \brief The time point of the last restart call.
            ///
            std::chrono::steady_clock::time_point   m_time_point;

            ///
            /// \brief The elapsed time between the previous two call of the
            /// restart method.
            ///
            float   m_elapsed_time;

            ///
            /// \brief The stopped state of the clock. true if the clock is
            /// stopped, false otherwise.
            ///
            bool    m_stopped;
    };
}
