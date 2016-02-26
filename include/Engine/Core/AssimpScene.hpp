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

#pragma once

#include    <assimp/scene.h>
#include    <map>

#include    "Engine/Configuration.hpp"

namespace   Engine
{
    class ENGINE_EXPORTS AssimpScene
    {
        public:
            ///
            /// \brief Construct an assimp scene from an const aiScene pointer.
            ///
            AssimpScene(const aiScene *assimpScene);

            ///
            /// \brief Copy constructor.
            ///
            AssimpScene(const AssimpScene &other) = default;

            ///
            /// \brief Move constructor.
            ///
            AssimpScene(AssimpScene &&other) noexcept = default;

            ///
            /// \brief Destructor.
            ///
            ~AssimpScene(void);

        public:
            ///
            /// \brief Copy assignment operator.
            ///
            AssimpScene     &operator=(const AssimpScene &other) = default;

            ///
            /// \brief Move assignment operator.
            ///
            AssimpScene     &operator=(AssimpScene &&other) noexcept = default;

        public:
            ///
            /// \brief Get a light from its name.
            ///
            const aiLight   *getLight(const std::string &name) const;

            ///
            /// \brief Get a camera from its name.
            ///
            const aiCamera  *getCamera(const std::string &name) const;

            ///
            /// \brief Get the assimps materials of the scene.
            ///
            /// TODO GSL ARRAY VIEW
            aiMaterial    **getMaterials(void) const;

            unsigned int        getMaterialsNumber(void) const;

            ///
            /// \brief Get the assimp animation of the scene.
            ///
            /// TODO GSL ARRAY VIEW
            aiAnimation   **getAnimations(void) const;

            unsigned int        getAnimationsNumber(void) const;

            ///
            /// \brief Get the assimp mesh of the scene.
            ///
            /// TODO GSL ARRAY VIEW
            aiMesh        **getMeshes(void) const;

            unsigned int        getMeshesNumber(void) const;

            ///
            /// \brief Get the assimp textures of the scene.
            /// TODO GSL ARRAY VIEW
            aiTexture     **getTextures(void) const;

            unsigned int        getTexturesNumber(void) const;

            ///
            /// \brief Get the root node of the scene.
            ///
            const aiNode        *getRootNode(void) const;

			inline std::size_t	getCameraNumber(void) const
			{
				return this->m_cameras.size();
			}

        private:
            ///
            /// \brief map of imported assimp cameras.
            ///
            std::map<std::string, const aiCamera *> m_cameras;

            ///
            /// \brief Map of imported assimp lights.
            ///
            std::map<std::string, const aiLight *>  m_lights;

            ///
            /// \brief all materials contains in the aiScene.
            ///
            aiMaterial  **m_materials;

            ///
            /// \brief all animations contains in the aiScene.
            ///
            aiAnimation     **m_animations;

            ///
            /// \brief all meshes contains in the aiScene.
            ///
            aiMesh  **m_meshes;

            ///
            /// \brief all textures contains in the aiScene.
            ///
            aiTexture   **m_textures;

            ///
            /// \brief The root node of the scene.
            ///
            const aiNode    *m_rootNode;

            ///
            /// \brief Number of materials in the materials array.
            ///
            unsigned int    m_materialsNumber;

            ///
            /// \brief Number of animations in the animations array.
            ///
            unsigned int    m_animationsNumber;

            ///
            /// \brief Number of meshes in the meshes array.
            ///
            unsigned int    m_meshesNumber;

            ///
            /// \brief Number of textures in the textures array.
            ///
            unsigned int    m_texturesNumber;

    };
}
