#ifndef     __LIBRARY_HPP__
# define    __LIBRARY_HPP__

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
                T           &get(unsigned int id) const; // TODO GSL NOT NULL

            protected:
                ///
                /// \brief Resources container.
                ///
                std::vector<T>      resources; // TODO GSL NOT NULL && OWNER
        };
    }
}

#include    "Library.tpp"

#endif /* !__LIBRARY_HPP__ */
