
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

#include    <list>

#include    "Engine/Configuration.hpp"

namespace   Engine
{

    class   Renderer;
    class   Scene;
    class   Camera;
    class   Object;
	class   Light;
	class   Terrain;

    ///
    /// \brief This class will be used to implement an occlusion culling algorithm.
    ///
    /// Actually, this class doesn't implement any occlusion culling, everything is rendered.
    ///
    class ENGINE_EXPORTS SpatialGraph
    {
        public:
            ///
            /// \brief Default constructor.
            ///
            SpatialGraph(Renderer &renderer, Scene *scene);

            ///
            /// \brief Copy constructor.
            ///
            SpatialGraph(const SpatialGraph &other) = default;

            ///
            /// \brief Move constructor.
            ///
            SpatialGraph(SpatialGraph &&other) noexcept = default;

            ///
            /// \brief Destructor.
            ///
            ~SpatialGraph(void) noexcept;

        public:
            ///
            /// \brief Copy assignment operator.
            ///
            SpatialGraph    &operator=(const SpatialGraph &other) = default;

            ///
            /// \brief Move assignment operator.
            ///
            SpatialGraph    &operator=(SpatialGraph &&other) noexcept = default;

        public:
            ///
            /// \brief This method is used to do the culling process and
            /// prepare the renderer for rendering process.
            ///
            void    cull(void);

        public:
            ///
            /// \brief This method add the object in the spatial graph,
            /// it's used to reduce the rendering time.
            ///
            void    add(Object *object);

            ///
            /// \brief This method add the light in the spatial graph,
            /// it's used to reduce the rendering time.
            ///
            void    add(Light *light);

			///
			/// \brief This method add the camera in the spatial graph,
			/// it's used to reduce the rendering time.
			///
			void    add(Camera *camera);

			///
			/// \brief This method add the terrain in the spatial graph,
			/// it's used to reduce the rendering time.
			///
			void    add(Terrain *terrain);

        protected:
            ///
            /// \brief The scene which the spatial graph act.
            ///
            Scene                   *m_scene;

            ///
            /// \brief The renderer used to display non hidden objects.
            ///
            Renderer                &m_renderer;

        protected:
            ///
            /// \brief The cameras present in the scene.
            ///
            std::list<Camera *>     m_cameras;

            ///
            /// \brief The objects present in the scene.
            ///
        std::list<Object *>     m_objects;

			///
			/// \brief The lights existing in the scene.
			///
			std::list<Light *>      m_lights;

			///
			/// \brief The terrains existing in the scene.
			///
			std::list<Terrain *>      m_terrains;
	};
}
