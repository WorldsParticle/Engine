///
/// \file Scene.hpp
///
/// \author Martin-Pierrat Louis (mart_p)
///
/// \date Sun, 17 Jan 2016 07:00:00
///
/// \version 1.0.6
///

#ifndef     __ENGINE_SCENE_HPP__
# define    __ENGINE_SCENE_HPP__

#include    <memory>
#include    <list>

#include    <Engine/Renderer.hpp>
#include    <Engine/SpatialGraph.hpp>
#include    <Engine/SceneGraph.hpp>
#include    <Engine/ShaderProgramLibrary.hpp>
#include    <Engine/MaterialLibrary.hpp>
#include    <Engine/AnimationLibrary.hpp>
#include    <Engine/MeshLibrary.hpp>
#include    <Engine/TextureLibrary.hpp>

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
            void        render(void);

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

        public:

            ///
            /// \brief Add an object in the spatial graph.
            ///
            void        add(Object *object);

            ///
            /// \brief Add a light in the spatial graph.
            ///
            void        add(Light *light);

            ///
            /// \brief add a camera in the spatial graph.
            ///
            void        add(Camera *camera);

        protected:
            ///
            /// \brief Library of usable shader program.
            ///
            ShaderProgramLibrary        shaderprograms;

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
            /// \brief The renderer is used to render the scene efficiently.
            ///
            /// For more informations, see Renderer.hpp
            ///
            Renderer                    renderer;

            ///
            /// \brief The spatial graph is used for the culling process.
            ///
            SpatialGraph                spatialgraph;

            ///
            /// \brief The scene graph represent the architecture of the scene.
            ///
            /// For more informations see SceneGraph.hpp
            ///
            SceneGraph                  scenegraph;

    };
}

#endif /* !__ENGINE_SCENE_HPP__ */
