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
            resources()
        {
            this->resources.reserve(other.resources.size());
            for (T *resource : other.resources) // TODO GSL NOT NULL
            {
                this->resources.push_back(new T(*resource));
            }
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
            for (T *resource : this->resources)
            {
                delete resource;
            }
        }



        template<typename T>
        Library<T> &
        Library<T>::operator=(const Library<T> &other)
        {

        }

        template<typename T>
        Library<T> &
        Library<T>::operator=(Library<T> &&other) noexcept
        {
            this->resources = std::move(other.resources);
            return *this;
        }



        template<typename T>
        T * // TODO GSL ADD NOT NULL
        Library<T>::get(unsigned int id)
        {
            return this->resources.at(id);
        }

    }
}
