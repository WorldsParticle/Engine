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

#ifndef     __ENGINE_LIBRARY_HPP__
# define    __ENGINE_LIBRARY_HPP__

#include    <vector>

namespace   Engine
{
    template<typename T>
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
            const T     &get(unsigned int id) const;

        protected:
            ///
            /// \brief Resources container.
            ///
            std::vector<T>  m_resources;
    };

    template<typename T>
    Library<T>::Library(void) :
        m_resources()
    {
        // nothing to do.
    }

    template<typename T>
    Library<T>::Library(const Library<T> &other) :
        m_resources(other.m_resources)
    {
        // nothing to do.
    }

    template<typename T>
    Library<T>::Library(Library<T> &&other) noexcept :
        m_resources(std::move(other.m_resources))
    {
        // nothing to do.
    }

    template<typename T>
    Library<T>::~Library(void) noexcept
    {
        // nothing to do.
    }



    template<typename T>
    Library<T> &
    Library<T>::operator=(const Library<T> &other)
    {
        this->m_resources = other.m_resources;
        return *this;
    }

    template<typename T>
    Library<T> &
    Library<T>::operator=(Library<T> &&other) noexcept
    {
        this->m_resources = std::move(other.m_resources);
        return *this;
    }



    template<typename T>
    const T &
    Library<T>::get(unsigned int id) const
    {
        return this->m_resources.at(id);
    }


}

#endif /* !__ENGINE_LIBRARY_HPP__ */
