#ifndef     __SCENE_HPP__
# define    __SCENE_HPP__

#include    <memory>
#include    <list>

#include    "GameObject.hpp"
#include    "Camera.hpp"
#include    "Light.hpp"

namespace WorldParticles
{
    namespace Engine
    {
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
                Scene(const aiScene *scene, const std::map<std::string, Entity *> &entities);

                ///
                /// \brief Copy constructor.
                ///
                Scene(const Scene &other);

                ///
                /// \brief Move constructor.
                ///
                Scene(Scene &&other) noexcept;

                ///
                /// \brief Destructor
                ///
                virtual ~Scene(void) noexcept;

            public:
                ///
                /// \brief Copy assignement operator.
                ///
                Scene       &operator=(const Scene &other);

                ///
                /// \brief Move assignement operator.
                ///
                Scene       &operator=(Scene &&other) noexcept;

            public:
                ///
                /// \brief This function is used to update the scene.
                ///
                void        update(void);

                ///
                /// \brief This function is used to draw the scene on the screen.
                ///
                void        draw(void);

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

        };
    }
}

#endif /* !__GAMEVIEW_HPP__ */
