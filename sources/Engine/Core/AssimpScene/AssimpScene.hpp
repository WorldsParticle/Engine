///
/// \file AssimpScene.hpp
///
/// \author Martin-Pierrat Louis (mart_p)
///
/// \date Sat, 16 Jan 2016 21:06:09
///
/// \version 1.0.3
///

#ifndef     __ENGINE_ASSIMP_SCENE_HPP__
# define    __ENGINE_ASSIMP_SCENE_HPP_

#include    <assimp/scene.h>
#include    <map>

namespace   WorldParticles
{
    namespace   Engine
    {
        class       AssimpScene
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

            private:
                ///
                /// \brief map of imported assimp cameras.
                ///
                std::map<std::string, const aiCamera *>     cameras;

                ///
                /// \brief Map of imported assimp lights.
                ///
                std::map<std::string, const aiLight *>      lights;

                ///
                /// \brief all materials contains in the aiScene.
                ///
                aiMaterial      **materials;

                ///
                /// \brief all animations contains in the aiScene.
                ///
                aiAnimation     **animations;

                ///
                /// \brief all meshes contains in the aiScene.
                ///
                aiMesh          **meshes;

                ///
                /// \brief all textures contains in the aiScene.
                ///
                aiTexture       **textures;

                ///
                /// \brief The root node of the scene.
                ///
                const aiNode        *rootNode;

                ///
                /// \brief Number of materials in the materials array.
                ///
                unsigned int        materialsNumber;

                ///
                /// \brief Number of animations in the animations array.
                ///
                unsigned int        animationsNumber;

                ///
                /// \brief Number of meshes in the meshes array.
                ///
                unsigned int        meshesNumber;

                ///
                /// \brief Number of textures in the textures array.
                ///
                unsigned int        texturesNumber;

        };
    }
}

#endif /* !__ENGINE_ASSIMP_SCENE_HPP__ */
