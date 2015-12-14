
#ifndef     __ASSIMP_IMPORTER_HPP__
# define    __ASSIMP_IMPORTER_HPP__

#include    <string>
#include    <list>
#include    <assimp/Importer.hpp>

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
                Scene       *load(const std::string &filename);

            private:
                ///
                /// \brief the assimp importer that wil be used to load the file in a new scene.
                ///
                Assimp::Importer    _importer;
        };
    }
}

#endif /* !__ASSIMP_IMPORTER_HPP__ */
