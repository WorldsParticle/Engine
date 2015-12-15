#include    <assimp/postprocess.h>
#include    <assimp/scene.h>
#include    <log4cpp/Category.hh>

#include    "AssimpImporter.hpp"
#include    "Model.hpp"

using namespace   log4cpp;

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
                Category    &root = Category::getRoot();
                root << Priority::ERROR
                    << "Erreur dans le loading du fichier : " << filename;
                root << Priority::ERROR << this->_importer.GetErrorString();
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
            Category    &root = Category::getRoot();
            root << Priority::INFO << "Importation des animations...";
            if (scene == nullptr || assimpScene == nullptr)
            {
                root << Priority::ERROR << "invalid function argument, a required argument is null.";
                return;
            }
            if (assimpScene->HasAnimations() == false)
            {
                root << Priority::INFO << "la scene ne contient pas d'animations.";
                return;
            }
            root << Priority::INFO << "Nombre d'animations : " << assimpScene->mNumAnimations;
            for (unsigned int i = 0 ; i < assimpScene->mNumAnimations ; ++i)
            {
                aiAnimation   *assimpAnimation = assimpScene->mAnimations[i];

                assimpAnimation = assimpAnimation;
            }
            root << Priority::INFO << "Importation des animations terminée !";
        }

        void
        AssimpImporter::importCameras(const aiScene *assimpScene, Scene *scene)
        {
            Category   &root = Category::getRoot();
            root << Priority::INFO << "Importation des cameras...";
            if (scene == nullptr || assimpScene == nullptr)
            {
                root << Priority::ERROR << "invalid function argument, a required argument is null.";
                return;
            }
            if (assimpScene->HasCameras() == false)
            {
                 root << Priority::INFO << "la scene ne contient pas de cameras.";
                 return;
            }
            root << Priority::INFO << "Nombre de cameras : " << assimpScene->mNumCameras;
            for (unsigned int i = 0 ; i < assimpScene->mNumCameras ; ++i)
            {
                aiCamera *assimpCamera = assimpScene->mCameras[i];

                assimpCamera = assimpCamera;
            }
            root << Priority::INFO << "Importation des caméras terminée !";
        }

        void
        AssimpImporter::importLights(const aiScene *assimpScene, Scene *scene)
        {
            Category    &root = Category::getRoot();
            root << Priority::INFO << "Importation des lumières...";
            if (scene == nullptr || assimpScene == nullptr)
            {
                root << Priority::ERROR << "invalid function argument, a required argument is null.";
                return;
            }
            if (assimpScene->HasLights() == false)
            {
                root << Priority::INFO << "la scene ne contient pas de lumières.";
                return;
            }
            root << Priority::INFO << "Nombre de lumières : " << assimpScene->mNumLights;
            for (unsigned int i = 0 ; i < assimpScene->mNumLights ; ++i)
            {
                aiLight   *assimpLight = assimpScene->mLights[i];

                assimpLight = assimpLight;
            }
            root << Priority::INFO << "Importation des lumières terminée !";
        }

        void
        AssimpImporter::importMaterials(const aiScene *assimpScene, Scene *scene)
        {
            Category   &root = Category::getRoot();
            root << Priority::INFO << "Importation des materiaux...";
            if (scene == nullptr || assimpScene == nullptr)
            {
                root << Priority::ERROR << "invalid function argument, a required argument is null.";
                return;
            }
            if (assimpScene->HasMaterials() == false)
            {
                root << Priority::INFO << "la scene ne contient pas de materiaux.";
                return;
            }
            root << Priority::INFO << "Nombre de materiaux : " << assimpScene->mNumMaterials;
            for (unsigned int i = 0 ; i < assimpScene->mNumMaterials ; ++i)
            {
                aiMaterial    *assimpMaterial = assimpScene->mMaterials[i];
                assimpMaterial = assimpMaterial;
            }
            root << Priority::INFO << "Importation des materiaux terminée !";
        }

        void
        AssimpImporter::importMeshes(const aiScene *assimpScene, Scene *scene)
        {
            Category    &root = Category::getRoot();
            root << Priority::INFO << "Importation des meshes...";
            if (scene == nullptr || assimpScene == nullptr)
            {
                root << Priority::ERROR << "invalid function argument, a required argument is null.";
                return;
            }
            if (assimpScene->HasMeshes() == false)
            {
                root << Priority::INFO << "la scene ne contient pas de meshes.";
                return;
            }
            root << Priority::INFO << "Nombre de meshes : " << assimpScene->mNumMeshes;
            for (unsigned int i = 0 ; i < assimpScene->mNumMeshes ; ++i)
            {
                Mesh    *mesh = this->importMesh(assimpScene->mMeshes[i]);
                if (mesh != nullptr)
                {
                    Model *test = new Model();
                    test->setMesh(mesh);
                    *scene << test;
                    //MeshLibrary::add(mesh);
                }
                break;
            }
            root << Priority::INFO << "Importation des meshes terminée !";
        }

        void
        AssimpImporter::importTextures(const aiScene *assimpScene, Scene *scene)
        {
            Category    &root = Category::getRoot();
            root << Priority::INFO << "Importation des textures...";
            if (scene == nullptr || assimpScene == nullptr)
            {
                root << Priority::ERROR << "invalid function argument, a required argument is null.";
                return;
            }
            if (assimpScene->HasTextures() == false)
            {
                root << Priority::INFO << "La scene ne contient pas de textures.";
                return;
            }
            root << Priority::INFO << "Nombre de textures : " << assimpScene->mNumTextures;
            for (unsigned int i = 0 ; i < assimpScene->mNumTextures ; ++i)
            {
                aiTexture  *assimpTexture = assimpScene->mTextures[i];

                assimpTexture = assimpTexture;
            }
            root << Priority::INFO << "Importation des textures terminée !";
        }

        /// TODO : surement possible de pouvoir cast les vertices... directement en glm
        Mesh *
        AssimpImporter::importMesh(const aiMesh *assimpMesh)
        {
            Category  &root = Category::getRoot();
            Mesh     *mesh = nullptr;

            if (assimpMesh == nullptr)
            {
                root << Priority::ERROR << "invalid function argument, a required argument is null.";
                return nullptr;
            }
            root << Priority::INFO << "importation d'un nouveau Mesh...";
            mesh = new Mesh();
            if (assimpMesh->HasPositions() == true)
            {
                root << Priority::INFO << "le mesh possede " << assimpMesh->mNumVertices << " vertices";
                std::vector<glm::vec3>  vertices;
                for (unsigned int i = 0 ; i < assimpMesh->mNumVertices ; ++i)
                {
                    aiVector3D  &v = assimpMesh->mVertices[i];
                    vertices.push_back(glm::vec3(v.x, v.y, v.z));
                }
                mesh->SetVertices(vertices);
                mesh->initialise();
            }
            root << Priority::INFO << "Importation d'un nouveau mesh terminée !";
            return mesh;
        }

    }
}
