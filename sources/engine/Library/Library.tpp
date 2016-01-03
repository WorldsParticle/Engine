#include    "Library.hpp"

namespace   WorldParticles
{
    namespace   Engine
    {
        template<typename T>
        Library<T>::Library(void) :
            resources()
        {
            // nothing to do.
        }

        template<typename T>
        Library<T>::Library(const Library<T> &other) :
            resources(other.resources)
        {
            // nothing to do.
        }

        template<typename T>
        Library<T>::Library(Library<T> &&other) noexcept :
            resources(std::move(other.resources))
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
            this->resources = other.resources;
            return *this;
        }

        template<typename T>
        Library<T> &
        Library<T>::operator=(Library<T> &&other) noexcept
        {
            this->resources = std::move(other.resources);
            return *this;
        }



        template<typename T>
        const T &
        Library<T>::get(unsigned int id) const
        {
            return this->resources.at(id);
        }

    }
}