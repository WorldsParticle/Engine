
#ifndef     __ASSIMP_IMPORTER_HPP__
# define    __ASSIMP_IMPORTER_HPP__

#include    <string>
#include    <list>

#include    "Scene.hpp"

namespace   WorldParticles
{
    namespace   Engine
    {
        class       AssimpImporter
        {
            public:
                ///
                /// \brief Default constructor
                ///
                AssimpImporter(void);

                ///
                /// \brief Destructor
                ///
                ~AssimpImporter(void);

            public:
                ///
                /// \brief This method is used to load a scene from a filename.
                ///
                std::list<Scene *>  load(const std::string &filename);

            private:

        };
    }
}

#endif /* !__ASSIMP_IMPORTER_HPP__ */
