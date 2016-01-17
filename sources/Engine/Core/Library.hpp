///
/// \file Library.hpp
///
/// \author Martin-Pierrat Louis (mart_p)
///
/// \date Sat, 16 Jan 2016 21:05:00
///
/// \version 1.0.3
///

#ifndef     __ENGINE_LIBRARY_HPP__
# define    __ENGINE_LIBRARY_HPP__

#include    <vector>

namespace   WorldParticles
{
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
                std::vector<T>      resources;
        };
    }
}

#include    "Library.tpp"

#endif /* !__ENGINE_LIBRARY_HPP__ */
