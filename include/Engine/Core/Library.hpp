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

#include    <map>

namespace   Engine
{
    template<typename Key, typename Resource>
    class       Library
    {
        public:
            ///
            /// \brief Default constructor.
            ///
            Library(void);

            ///
            /// \brief Copy constructor.
            ///
            Library(const Library &other);

            ///
            /// \brief Move constructor.
            ///
            Library(Library &&other) noexcept;

            ///
            /// \brief Destructor.
            ///
            virtual ~Library(void) noexcept;

        public:
            ///
            /// \brief Copy assignment operator.
            ///
            Library     &operator=(const Library &other);

            ///
            /// \brief Move assignment operator.
            ///
            Library     &operator=(Library &&other) noexcept;

        public:
            ///
            /// \brief Getter for a resource.
            ///
            const Resource  &get(const Key &key) const;

        protected:
            ///
            /// \brief Resources container.
            ///
            std::map<Key, Resource>     m_resources;
    };

    template<typename Key, typename Resource>
    Library<Key, Resource>::Library(void) :
        m_resources()
    {
        // nothing to do.
    }

    template<typename Key, typename Resource>
    Library<Key, Resource>::Library(const Library<Key, Resource> &other) :
        m_resources(other.m_resources)
    {
        // nothing to do.
    }

    template<typename Key, typename Resource>
    Library<Key, Resource>::Library(Library<Key, Resource> &&other) noexcept :
        m_resources(std::move(other.m_resources))
    {
        // nothing to do.
    }

    template<typename Key, typename Resource>
    Library<Key, Resource>::~Library(void) noexcept
    {
        // nothing to do.
    }



    template<typename Key, typename Resource>
    Library<Key, Resource> &
    Library<Key, Resource>::operator=(const Library<Key, Resource> &other)
    {
        this->m_resources = other.m_resources;
        return *this;
    }

    template<typename Key, typename Resource>
    Library<Key, Resource> &
    Library<Key, Resource>::operator=(Library<Key, Resource> &&other) noexcept
    {
        this->m_resources = std::move(other.m_resources);
        return *this;
    }



    template<typename Key, typename Resource>
    const Resource &
    Library<Key, Resource>::get(const Key &key) const
    {
        return this->m_resources.at(key);
    }

}
