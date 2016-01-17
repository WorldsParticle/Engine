///
/// \file AssimpImporter.cpp
///
/// \author Martin-Pierrat Louis (mart_p)
///
/// \date Sun, 17 Jan 2016 06:49:53
///
/// \version 1.0.5
///

#include    <assimp/postprocess.h>
#include    <assimp/scene.h>
#include    <log4cpp/Category.hh>

#include    <Engine/AssimpImporter.hpp>
#include    <Engine/AssimpScene.hpp>
#include    <Engine/Scene.hpp>

using namespace   log4cpp;

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
    AssimpImporter::import(const std::string &filename)
    {
        Scene           *scene = nullptr;
        const aiScene   *loadedScene = this->load(filename);

        if (loadedScene != nullptr)
        {
            AssimpScene     aiscene(loadedScene);
            scene = new Scene(aiscene);
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
            root << Priority::ERROR << this->importer.GetErrorString();
        }
        return result;
    }
}
