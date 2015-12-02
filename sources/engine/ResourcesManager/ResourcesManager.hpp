#ifndef     __RESOURCE_MANAGER_HPP__
# define    __RESOURCE_MANAGER_HPP__

#include    <string>
#include    <map>

#include    "Mesh.hpp"

namespace   WorldParticles
{
    namespace   Engine
    {
        ///
        /// \brief This class is used to load any resources assets like sound, texture, mesh...
        ///
        template<typename T>
        class       ResourcesManager
        {
            public:
                ///
                /// \brief This method is used to retrieve every assets that have an implemented addResource method.
                ///
                static T    &getResource(const std::string &filename)
                {
                    typename std::map<const std::string, T*>::iterator it;

                    if ((it = ResourcesManager<T>::_resources.find(filename)) != ResourcesManager<T>::_resources.end())
                        return *it->second;
                    return ResourcesManager<T>::addResource(filename);
                }

            private:
                ///
                /// \brief This method is automaticaly called by getResource if the resource is not found.
                ///
                static T    &addResource(const std::string &filename);

            protected:
                ///
                /// \brief this attribute is used to contains the resources.
                ///
                static std::map<const std::string, T *>     _resources;
        };

        ///
        /// \brief static attribute declaration.
        ///
        template<typename T>
        std::map<const std::string, T*> ResourcesManager<T>::_resources = std::map<const std::string, T*>();

        ///
        /// \brief The overloading of the addResource method for a Mesh.
        ///
        template<> inline
        Mesh &ResourcesManager<Mesh>::addResource(const std::string &filename)
        {
            Mesh *result = new Mesh();
            return *result;
        }

   }
}

#endif /* !__RESOURCE_MANAGER_HPP__ */
