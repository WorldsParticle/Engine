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

#ifndef     __ENGINE_BUFFER_OBJECT_HPP__
# define    __ENGINE_BUFFER_OBJECT_HPP__

#include    <vector>
#include    <glm/glm.hpp>

namespace   Engine
{
    ///
    /// \brief This class is used to abstract a OpenGL Vertex Buffer Object.
    ///
    class       BufferObject
    {
        public:
            ///
            /// \brief This enum is used to define all type of buffer object.
            ///
            enum    Type
            {
                ARRAY_BUFFER,
                ELEMENT_ARRAY_BUFFER
            };

            enum    Usage
            {
                STATIC_DRAW,
                DYNAMIC_DRAW,
                STREAM_DRAW
            };

        public:
            ///
            /// \brief Create an empty buffer object.
            ///
            BufferObject(const Type &type, const Usage &usage);

            ///
            /// \brief Copy constructor.
            ///
            BufferObject(const BufferObject &other) = delete;

            ///
            /// \brief Move constructor.
            ///
            BufferObject(BufferObject &&other) noexcept;

            ///
            /// \brief Destructor.
            ///
            virtual ~BufferObject(void) noexcept;

        public:
            ///
            /// \brief Copy assignment operator.
            ///
            BufferObject    &operator=(const BufferObject &other) = delete;

            ///
            /// \brief Move assignment operator.
            ///
            BufferObject    &operator=(BufferObject &&other) noexcept;

        public:
            ///
            /// \brief This method is used to bind the buffer object to the graphic API.
            ///
            void    bind(void);

            ///
            /// \brief This method is used to unbind the buffer object from the graphic API.
            ///
            void    unbind(void);

            ///
            /// \brief replace the previous data with the new data in the graphic api.
            ///
            /// If the new data is greater than the size of the buffer, the buffer will be reallocated.
            ///
            void    update(void *data, unsigned int length);

        public:
            ///
            /// \brief Setter for the type attribute.
            ///
            void            setType(const Type &type);

            ///
            /// \brief Setter for the usage attribute.
            ///
            void            setUsage(const Usage &usage);

        public:
            ///
            /// \brief Getter for the type attribute.
            ///
            const Type      &getType(void) const;

            ///
            /// \brief Getter for the usage attribute.
            ///
            const Usage     &getUsage(void) const;

        private:

            unsigned int    convert(const Type &type) const;
            unsigned int    convert(const Usage &usage) const;

        private:
            ///
            /// \brief This attribute is used to contains the graphic id of the buffer object.
            ///
            unsigned int    m_id;

            ///
            /// \brief This attribute is used to contains the type of the buffer object.
            ///
            Type            m_type;

            ///
            /// \brief This attribute is used to know if the buffer object will be updated frequently or not.
            ///
            Usage           m_usage;

            ///
            /// \brief the buffer size.
            ///
            unsigned int    m_size;
    };
}

#endif /* !__ENGINE_BUFFER_OBJECT_HPP__ */
