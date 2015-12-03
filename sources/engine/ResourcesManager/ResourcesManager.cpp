#include "ResourcesManager.hpp"

namespace   WorldParticles
{
    namespace   Engine
    {
        ///
        /// \brief static attribute declaration.
        ///
        template<typename T>
        std::map<const std::string, T*> ResourcesManager<T>::_resources = std::map<const std::string, T*>();
    }
}
