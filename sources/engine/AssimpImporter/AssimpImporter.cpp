#include    <assimp/postprocess.h>
#include    <assimp/scene.h>

#include    "AssimpImporter.hpp"
#include    <log4cpp/Category.hh>

namespace   WorldParticles
{
    namespace   Engine
    {
        AssimpImporter::AssimpImporter(void)
        {

        }

        AssimpImporter::~AssimpImporter(void)
        {

        }

        Scene *
        AssimpImporter::importScene(const std::string &filename)
        {
            const aiScene   *assimpScene = nullptr;
            Scene           *scene = nullptr;
            int             flags = 0;

            flags |= aiProcess_ValidateDataStructure;
            flags |= aiProcess_Triangulate;
            flags |= aiProcess_FindInvalidData;
            if ((assimpScene = this->_importer.ReadFile(filename, flags)) == nullptr)
            {
                log4cpp::Category   &root = log4cpp::Category::getRoot();
                root << log4cpp::Priority::ERROR << "Erreur dans le loading du fichier : " << filename;
                root << log4cpp::Priority::ERROR << this->_importer.GetErrorString();
                return nullptr;
            }
            scene = new Scene();
            this->importAnimations(assimpScene, scene);
            this->importCameras(assimpScene, scene);
            this->importLights(assimpScene, scene);
            this->importMaterials(assimpScene, scene);
            this->importMeshes(assimpScene, scene);
            this->importTextures(assimpScene, scene);
            return scene;
        }

        void
        AssimpImporter::importAnimations(const aiScene *assimpScene, Scene *scene)
        {
            log4cpp::Category   &root = log4cpp::Category::getRoot();
            root << log4cpp::Priority::INFO << "Importation des animations...";
            if (scene != nullptr && assimpScene != nullptr && assimpScene->HasAnimations())
            {
                root << log4cpp::Priority::INFO << "Nombre d'animations : " << assimpScene->mNumAnimations;
                for (unsigned int i = 0 ; i < assimpScene->mNumAnimations ; ++i)
                {
                    aiAnimation   *assimpAnimation = assimpScene->mAnimations[i];

                    assimpAnimation = assimpAnimation;
                }
            }
            root << log4cpp::Priority::INFO << "Importation des animations terminée !";
        }

        void
        AssimpImporter::importCameras(const aiScene *assimpScene, Scene *scene)
        {
            log4cpp::Category   &root = log4cpp::Category::getRoot();
            root << log4cpp::Priority::INFO << "Importation des cameras...";
            if (scene != nullptr && assimpScene != nullptr && assimpScene->HasCameras())
            {
                root << log4cpp::Priority::INFO << "Nombre de cameras : " << assimpScene->mNumCameras;
                for (unsigned int i = 0 ; i < assimpScene->mNumCameras ; ++i)
                {
                    aiCamera *assimpCamera = assimpScene->mCameras[i];

                    assimpCamera = assimpCamera;
                }
            }
            root << log4cpp::Priority::INFO << "Importation des caméras terminée !";
        }

        void
        AssimpImporter::importLights(const aiScene *assimpScene, Scene *scene)
        {
            log4cpp::Category   &root = log4cpp::Category::getRoot();
            root << log4cpp::Priority::INFO << "Importation des lumières...";
            if (scene != nullptr && assimpScene != nullptr && assimpScene->HasLights())
            {
                root << log4cpp::Priority::INFO << "Nombre de lumières : " << assimpScene->mNumLights;
                for (unsigned int i = 0 ; i < assimpScene->mNumLights ; ++i)
                {
                    aiLight   *assimpLight = assimpScene->mLights[i];

                    assimpLight = assimpLight;
                }
            }
            root << log4cpp::Priority::INFO << "Importation des lumières terminée !";
        }

        void
        AssimpImporter::importMaterials(const aiScene *assimpScene, Scene *scene)
        {
            log4cpp::Category   &root = log4cpp::Category::getRoot();
            root << log4cpp::Priority::INFO << "Importation des materiaux...";
            if (scene != nullptr && assimpScene != nullptr && assimpScene->HasAnimations())
            {
                root << log4cpp::Priority::INFO << "Nombre de materiaux : " << assimpScene->mNumMaterials;
                for (unsigned int i = 0 ; i < assimpScene->mNumMaterials ; ++i)
                {

                }
            }
            root << log4cpp::Priority::INFO << "Importation des materiaux terminée !";
        }

        void
        AssimpImporter::importMeshes(const aiScene *assimpScene, Scene *scene)
        {
            log4cpp::Category   &root = log4cpp::Category::getRoot();
            root << log4cpp::Priority::INFO << "Importation des meshes...";
            if (scene != nullptr && assimpScene != nullptr && assimpScene->HasAnimations())
            {
                root << log4cpp::Priority::INFO << "Nombre de meshes : " << assimpScene->mNumMeshes;
                for (unsigned int i = 0 ; i < assimpScene->mNumMeshes ; ++i)
                {
                     aiMesh   *assimpMesh = assimpScene->mMeshes[i];

                     assimpMesh = assimpMesh;
                }
            }
            root << log4cpp::Priority::INFO << "Importation des meshes terminée !";
        }

        void
        AssimpImporter::importTextures(const aiScene *assimpScene, Scene *scene)
        {
            log4cpp::Category   &root = log4cpp::Category::getRoot();
            root << log4cpp::Priority::INFO << "Importation des textures...";
            if (scene != nullptr && assimpScene != nullptr && assimpScene->HasAnimations())
            {
                root << log4cpp::Priority::INFO << "Nombre de textures : " << assimpScene->mNumTextures;
                for (unsigned int i = 0 ; i < assimpScene->mNumTextures ; ++i)
                {
                     aiTexture  *assimpTexture = assimpScene->mTextures[i];

                     assimpTexture = assimpTexture;
                }
            }
            root << log4cpp::Priority::INFO << "Importation des textures terminée !";
        }



    }
}
