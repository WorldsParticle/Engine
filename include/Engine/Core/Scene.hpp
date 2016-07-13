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
#include    "Engine/Core/Clock.hpp"
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
            Scene(void);
            Scene(const AssimpScene &assimpScene);
            Scene(const Scene &other) = default;
            Scene(Scene &&other) noexcept = default;
            virtual ~Scene(void) noexcept;

        public:
            Scene       &operator=(const Scene &other) = default;
            Scene       &operator=(Scene &&other) noexcept = default;

        public:
            ///
            /// \brief This function is used to import a model with assimp.
            ///
            SceneGraphNode  *loadModel(const AssimpScene &s);
	    void setFramebufferActivationInRenderer(bool state);
	    void setSkyColorInRenderer(glm::vec4 const &newColor);
	    void clear();

            void        update(void);
            void        render(void);
            void        push_event(const Event::Event &event);

        public:
            Material    *getMaterial(unsigned int id) const;
            Animation   *getAnimation(const std::string &name) const;
            Mesh        *getMesh(unsigned int id) const;
            Texture     *getTexture(const std::string &name) const;

            const Clock &clock(void) const;

            ShaderProgramLibrary const&     getShaderPrograms() const{
                return m_shaderprograms;
            }

        public:
            ///
            /// \brief Add an object in the spatial graph.
            ///
            void        add(Object *object);
            void        add(Light *light);
            void        add(Camera *camera);
            void        add(Terrain *terrain);

        public:
            ///
            /// \brief Temporary function to register a callback to an event.
            ///
            /// TODO : something a little bit better
            ///
            void        register_callback(const Event::Type &event_type,
                    const std::function<void(const Event::Event &)> &callback);

        protected:
            Event::EventRegister    m_event_register;

            Clock                   m_clock;

        protected:
            ShaderProgramLibrary        m_shaderprograms;
            TextureLibrary              m_textures;
            MaterialLibrary             m_materials;
            AnimationLibrary            m_animations;
            MeshLibrary                 m_meshes;

        protected:
            ///
            /// \brief The renderer is used to render the scene efficiently.
            ///
            Renderer                    m_renderer;

            ///
            /// \brief The spatial graph is used for the culling process.
            ///
            SpatialGraph                m_spatialgraph;

            ///
            /// \brief The scene graph represent the architecture of the scene.
            ///
            SceneGraph                  m_scenegraph;

    };
}
