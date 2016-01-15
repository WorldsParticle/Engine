///
/// \file ArrayObject.hpp
///
/// \author Martin-Pierrat Louis (mart_p)
///
/// \date Fri, 15 Jan 2016 13:28:15
///
/// \version 1.0.1
///

#ifndef     __ARRAY_OBJECT_HPP__
# define    __ARRAY_OBJECT_HPP__

namespace   WorldParticles
{
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
                unsigned int    id;
        };
    }
}

#endif /* !__ARRAY_OBJECT_HPP__ */
