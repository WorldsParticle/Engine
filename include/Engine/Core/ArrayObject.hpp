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

#ifndef     __ENGINE_ARRAY_OBJECT_HPP__
# define    __ENGINE_ARRAY_OBJECT_HPP__

namespace   Engine
{
    ///
    /// \brief This class is an abstraction of the Vertex Array Object of the OpenGL API.
    ///
    class       ArrayObject
    {
        public:
            ///
            /// \brief Default constructor.
            ///
            ArrayObject(void);

            ///
            /// \brief Copy constructor.
            ///
            /// The copy constructor is deleted because of the impossibilty
            /// to copy the OpenGL state of the VAO.
            ///
            ArrayObject(const ArrayObject &other) = delete;

            ///
            /// \brief Move constructor.
            ///
            ArrayObject(ArrayObject &&other) noexcept;

            ///
            /// \brief Destructor.
            ///
            virtual ~ArrayObject(void) noexcept;

        public:
            ///
            /// \brief Copy assignment operator.
            ///
            /// The copy assignment operator is deleted because of the
            /// impossibilty to copy the OpenGL state of the VAO.
            ///
            ArrayObject     &operator=(const ArrayObject &other) = delete;

            ///
            /// \brief Move assignment operator.
            ///
            ArrayObject     &operator=(ArrayObject &&other) noexcept;

        public:
            ///
            /// \brief Bind the array object in the graphic pipeline.
            ///
            void    bind(void) const;

            ///
            /// \brief Unbind the array object from the graphic pipeline.
            ///
            void    unbind(void) const;

        private:
            ///
            /// \brief The id of the vertex array object.
            ///
            unsigned int    m_id;
    };
}

#endif /* !__ENGINE_ARRAY_OBJECT_HPP__ */
