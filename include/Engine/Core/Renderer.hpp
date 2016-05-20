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

#include    <list>

#include    "Engine/Configuration.hpp"
#include    "Engine/Core/ShaderProgramLibrary.hpp"

namespace   Engine
{
    class   Scene;
    class   Camera;
    class   Object;
	class   Light;
    class   Terrain;

    ///
    /// \brief The render graph is used to render efficiently 3D data.
    ///
    /// This class must be an interface.
    ///
    /// TODO rework.
    ///
    class ENGINE_EXPORTS Renderer
    {
        public:
            ///
            /// \brief Default Constructor.
            ///
            Renderer(Scene *scene);

            ///
            /// \brief Copy constructor.
            ///
            Renderer(const Renderer &other);

            ///
            /// \brief Move constructor.
            ///
            Renderer(Renderer &&other) noexcept;

            ///
            /// \brief Destructor.
            ///
            ~Renderer(void) noexcept;

        public:
            ///
            /// \brief Copy assignment operator.
            ///
            Renderer     &operator=(const Renderer &other);

            ///
            /// \brief Move assignment operator.
            ///
            Renderer     &operator=(Renderer &&other) noexcept;

        public:
            ///
            /// \brief This method launch the rendering process.
            ///
            void            render(void);

        public:
            ///
            /// \brief This method is used to add an object for the next rendering.
            ///
            void            add(Object *object);

            ///
            /// \brief This method is used to add a Light for the next rendering.
            ///
            void            add(Light *light);

			///
			/// \brief This method is used to add a camera for the next rendering.
			///
			void            add(Camera *camera);

			///
			/// \brief This method is used to add a terrain for the next rendering.
			///
			void            add(Terrain *terrain);

        private:
            ///
            /// \brief The scene in which the Renderer act.
            ///
            Scene				    *m_scene;

            ///
            /// \brief The list of object needed to be rendered with the render method.
            ///
            /// TODO container type
            ///
            std::list<Object *>			    m_objects;

            ///
            /// \brief The list of cameras needed to be rendered with the render method.
            ///
            /// TODO container type
            ///
            std::list<Camera *>			    m_cameras;

			///
			/// \brief The list of lights needed to be rendered with the light method.
			///
			/// TODO container type
			///
			std::list<Light *>      m_lights;

			///
			/// \brief The list of terrains needed to be rendered with the light method.
			///
			/// TODO container type
			///
			std::list<Terrain *>      m_terrains;

    };
}
