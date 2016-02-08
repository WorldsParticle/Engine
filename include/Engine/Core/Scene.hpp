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

#ifndef     __ENGINE_SCENE_HPP__
# define    __ENGINE_SCENE_HPP__

#include    <memory>
#include    <list>

#include    "Engine/Configuration.hpp"
#include    "Engine/Core/Renderer.hpp"
#include    "Engine/Core/SpatialGraph.hpp"
#include    "Engine/Core/SceneGraph.hpp"
#include    "Engine/Core/ShaderProgramLibrary.hpp"
#include    "Engine/Core/MaterialLibrary.hpp"
#include    "Engine/Core/AnimationLibrary.hpp"
#include    "Engine/Core/MeshLibrary.hpp"
#include    "Engine/Core/TextureLibrary.hpp"

#include    "Engine/Event/EventRegister.hpp"

namespace Engine
{
    namespace   Event
    {
        class       Event;
    }
    class       AssimpScene;

    ///
    /// \brief This class is used to represent a scene, with camera / light & gameobject.
    ///
    /// The scene could be used to draw a GUI in the screen, with a good gameobject separation.
    ///
    class ENGINE_EXPORTS Scene final
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

            ///
            /// \brief This function is used to push a new event in the scene.
            ///
            void        push_event(const Event::Event &event);

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

        public:

            ///
            /// \brief Temporary function to register a callback to an event.
            ///
            /// TODO : something a little bit better
            ///
            void        register_callback(const Event::Type &event_type,
                    const std::function<void(const Event::Event &)> &callback);

        protected:

            ///
            /// \brief temporary, but something similar to what I want do.
            ///
            Event::EventRegister    m_event_register;

        protected:
            ///
            /// \brief Library of usable shader program.
            ///
            ShaderProgramLibrary        m_shaderprograms;

            ///
            /// \brief Library of usable materials.
            ///
            MaterialLibrary             m_materials;

            ///
            /// \brief Library of usable animation in the scene.
            ///
            AnimationLibrary            m_animations;

            ///
            /// \brief Library of usable mesh in the scene.
            ///
            MeshLibrary                 m_meshes;

            ///
            /// \brief Library of usable textures in the scene.
            ///
            TextureLibrary              m_textures;

        protected:
            ///
            /// \brief The renderer is used to render the scene efficiently.
            ///
            /// For more informations, see Renderer.hpp
            ///
            Renderer                    m_renderer;

            ///
            /// \brief The spatial graph is used for the culling process.
            ///
            SpatialGraph                m_spatialgraph;

            ///
            /// \brief The scene graph represent the architecture of the scene.
            ///
            /// For more informations see SceneGraph.hpp
            ///
            SceneGraph                  m_scenegraph;

    };
}

#endif /* !__ENGINE_SCENE_HPP__ */
