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

        AssimpImporter::AssimpImporter(void) :
            importer()
        {
            // nothing to do.
        }

        AssimpImporter::~AssimpImporter(void)
        {
            // nothing to do.
        }



        Scene *
        AssimpImporter::importScene(const std::string &filename)
        {
            const aiScene *assimpScene = this->load(filename);
            std::map<std::string, Entity *> entities;

            for (unsigned int i = 0 ; i < assimpScene->mNumCameras ; ++i)
            {
                Camera      *camera = new Camera(assimpScene->mCameras[i]);
                entities[camera->getName()] = camera;
            }

            for (unsigned int i = 0 ; i < assimpScene->mNumLights ; ++i)
            {
                Light   *light = new Light(assimpScene->mLights);
                entities[light->getName()] = light;
            }

            Scene   *scene = new Scene(assimpScene, entities);

            for (auto &entry : entities)
            {
                delete entry.second;
            }

            return scene;
        }

        const aiScene *
        AssimpImporter::load(const std::string &filename)
        {
            const aiScene   *result = nullptr;
            int             flags = 0;

            flags |= aiProcess_ValidateDataStructure;
            flags |= aiProcess_Triangulate;
            flags |= aiProcess_FindInvalidData;
            flags |= aiProcess_SortByPType;
            flags |= aiProcessPreset_TargetRealtime_Quality;
            flags |= aiProcess_FixInfacingNormals;
            if ((result = this->importer.ReadFile(filename, flags)) == nullptr)
            {
                Category    &root = Category::getRoot();
                root << Priority::ERROR
                    << "Erreur dans le loading du fichier : " << filename;
                root << Priority::ERROR << this->_importer.GetErrorString();
            }
            return result;
        }

    }
}
