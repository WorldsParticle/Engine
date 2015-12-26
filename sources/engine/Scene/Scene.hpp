#ifndef     __SCENE_HPP__
# define    __SCENE_HPP__

#include    <memory>
#include    <list>

#include    "SceneGraph.hpp"
#include    "MaterialLibrary.hpp"
#include    "AnimationLibrary.hpp"
#include    "MeshLibrary.hpp"
#include    "TextureLibrary.hpp"

namespace WorldParticles
{
    namespace Engine
    {
        class       AssimpScene;

        ///
        /// \brief This class is used to represent a scene, with camera / light & gameobject.
        ///
        /// The scene could be used to draw a GUI in the screen, with a good gameobject separation.
        ///
        class       Scene
        {
            public:
                ///
                /// \brief Default constructor. This constructor create an empty scene.
                ///
                Scene(void);

                ///
                ///
                ///
                Scene(const AssimpScene &assimpScene);

                ///
                /// \brief Copy constructor.
                ///
                Scene(const Scene &other) = default;

                ///
                /// \brief Move constructor.
                ///
                Scene(Scene &&other) noexcept = default;

                ///
                /// \brief Destructor
                ///
                virtual ~Scene(void) noexcept;

            public:
                ///
                /// \brief Copy assignement operator.
                ///
                Scene       &operator=(const Scene &other) = default;

                ///
                /// \brief Move assignement operator.
                ///
                Scene       &operator=(Scene &&other) noexcept = default;

            public:
                ///
                /// \brief This function is used to update the scene.
                ///
                void        update(void);

                ///
                /// \brief This function is used to draw the scene on the screen.
                ///
                void        draw(void);

            public:
                ///
                /// \brief This method allow to retrieve a material from the animation material.
                ///
                Material    *getMaterial(unsigned int id) const;

                ///
                /// \brief This method allow to retrieve an animation from the animation library.
                ///
                Animation   *getAnimation(unsigned int id) const;

                ///
                /// \brief This method allow to retrieve a mesh from the mesh library.
                ///
                Mesh        *getMesh(unsigned int id) const;

                ///
                /// \brief This method allow to retrieve a texture from the texture library.
                ///
                Texture     *getTexture(unsigned int id) const;

            protected:
                ///
                /// \brief Library of usable materials.
                ///
                MaterialLibrary             materials;

                ///
                /// \brief Library of usable animation in the scene.
                ///
                AnimationLibrary            animations;

                ///
                /// \brief Library of usable mesh in the scene.
                ///
                MeshLibrary                 meshes;

                ///
                /// \brief Library of usable textures in the scene.
                ///
                TextureLibrary              textures;

            protected:
                ///
                /// \brief The scene graph represent the architecture of the scene.
                ///
                /// For more informations see SceneGraph.hpp
                ///
                SceneGraph                  sceneGraph;

                ///
                ///
                ///
                //RenderGraph                 renderGraph;

        };
    }
}

#endif /* !__GAMEVIEW_HPP__ */
