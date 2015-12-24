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
                /// \brief Construct a scene from an assimp scene.
                ///
                Scene(const aiScene *assimpScene);

                ///
                /// \brief Copy constructor.
                ///
                Scene(const Scene &other);

                ///
                /// \brief Move constructor.
                ///
                Scene(Scene &&other);

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
                Scene       &operator=(Scene &&other);

            public:
                ///
                /// \brief This function is used to update the scene.
                ///
                void        update(void);

                ///
                /// \brief This function is used to draw the scene on the screen.
                ///
                void        draw(void);

            private:
                ///
                /// \brief This vector contains all materials that can be used in the scene.
                ///
                /// All the materials present are not necessarily used in the scene.
                /// It's more like a library for loaded materials.
                ///
                std::vector<Material *>     materials; // TODO GSL OWNER && NOT NULL

                ///
                /// \brief This vector contains all animations that can be used in the scene.
                ///
                /// All the animation present are not necessarily used in the scene.
                /// It's more like a library for loaded animations.
                ///
                std::vector<Animations *>   animations; // TODO GSL OWNER && NOT NULL

                ///
                /// \brief This vector contains all meshes that can be used in the scene.
                ///
                /// All the mesh present are not necessarily used in the scene.
                /// It's more like a library for loaded meshes.
                ///
                std::vector<Mesh *>         meshes; // TODO GSL OWNER && NOT NULL

                ///
                /// \brief This vector contains all textures that can be used in the scene.
                ///
                /// All the textures present are not necessarily used in the scene.
                /// It's more like a library for loaded textures.
                ///
                std::vector<Textures *>     textures; // TODO GSL OWNER && NOT NULL

            private:
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
