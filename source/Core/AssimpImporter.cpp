//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 3 of the License, or
// any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this program; If not, see <http://www.gnu.org/licenses/>.
//
// Copyright (C) 2016 Martin-Pierrat Louis (louismartinpierrat@gmail.com)
//

#include    <assimp/postprocess.h>
#include    <assimp/scene.h>
#include    <log4cpp/Category.hh>

#include    "Engine/Core/AssimpImporter.hpp"
#include    "Engine/Core/AssimpScene.hpp"
#include    "Engine/Core/Scene.hpp"

using namespace   log4cpp;

namespace   Engine
{

    AssimpImporter::AssimpImporter(void) :
        m_importer()
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
        Category::getRoot() << Priority::DEBUG << "Loaded : " << filename;

        if (loadedScene == nullptr)
        {
            std::stringstream errMsg;
            errMsg << "Error in file loading : "
                    << filename << ": "
                    << this->m_importer.GetErrorString();
            throw std::runtime_error(errMsg.str());
        }
        AssimpScene     aiscene(loadedScene);
        scene = new Scene(aiscene);
        return scene;
    }
    
    bool
    AssimpImporter::importModel(const std::string &filename, Scene *scene)
    {
        const aiScene   *loadedScene = this->load(filename);

        if (loadedScene != nullptr)
        {
            AssimpScene     aiscene(loadedScene);
            Category::getRoot() << Priority::INFO << "Importing... " << filename;

            scene->addModel(aiscene);
            return true;
        }
        return false;        
    }


    const aiScene *
    AssimpImporter::load(const std::string &filename)
    {
        Category        &root = Category::getRoot();
        int             flags = 0;
        const aiScene * result = nullptr;

        root << Priority::DEBUG << "Loading : " << filename;
//        flags |= aiProcess_ValidateDataStructure;
//        flags |= aiProcess_Triangulate;
//        flags |= aiProcess_FindInvalidData;
//        flags |= aiProcess_SortByPType;
//        flags |= aiProcessPreset_TargetRealtime_Quality;
//        flags |= aiProcess_FixInfacingNormals;
        result = this->m_importer.ReadFile(filename, flags);
        if (result == nullptr)
        {
            std::stringstream errMsg;
            errMsg << "Error in file loading : "
                    << filename << ": "
                    << this->m_importer.GetErrorString();
            throw std::runtime_error(errMsg.str());
        }

        root << Priority::DEBUG << "Loaded : " << result;        
        return result;
    }
}
