
#ifndef     __ASSIMP_IMPORTER_HPP__
# define    __ASSIMP_IMPORTER_HPP__

#include    <string>
#include    <list>
#include    <assimp/Importer.hpp>
#include    <assimp/mesh.h>

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
                Scene       *importScene(const std::string &filename);

            private:
                ///
                /// \brief This method is internally used to load animation in the scene graph.
                ///
                void        importAnimations(const aiScene *assimpScene, Scene *scene);

                ///
                ///
                ///
                void        importCameras(const aiScene *assimpScene, Scene *scene);

                void        importLights(const aiScene *assimpScene, Scene *scene);

                void        importMaterials(const aiScene *assimpScene, Scene *scene);

                void        importMeshes(const aiScene *assimpScene, Scene *scene);

                void        importTextures(const aiScene *assimpScene, Scene *scene);

                Mesh        *importMesh(const aiMesh *assimpMesh);

            private:
                ///
                /// \brief the assimp importer that wil be used to load the file in a new scene.
                ///
                Assimp::Importer    _importer;
        };
    }
}

#endif /* !__ASSIMP_IMPORTER_HPP__ */
