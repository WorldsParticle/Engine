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

#ifndef     __ENGINE_MESH_LIBRARY_HPP__
# define    __ENGINE_MESH_LIBRARY_HPP__

#include    "Engine/Core/Library.hpp"
#include    "Engine/Core/Mesh.hpp"

namespace   Engine
{
    class       MaterialLibrary;

    ///
    /// \brief This class is used as a container for the mesh used in the scene.
    ///
    class       MeshLibrary : public Library<Mesh *>
    {
        public:
            ///
            /// \brief Default constructor.
            ///
            MeshLibrary(void);

            ///
            /// \brief Construct the library from an assimp mesh array.
            ///
            /// TODO GSL array_view
            ///
            MeshLibrary(const MaterialLibrary &materials,
                    aiMesh **assimpMeshes, unsigned int size);

            ///
            /// \brief Copy constructor.
            ///
            MeshLibrary(const MeshLibrary &other);

            ///
            /// \brief Move constructor.
            ///
            MeshLibrary(MeshLibrary &&other) noexcept = default;

            ///
            /// \brief Destructor.
            ///
            virtual ~MeshLibrary(void) noexcept;

        public:
            ///
            /// \brief Copy assignment operator.
            ///
            MeshLibrary     &operator=(const MeshLibrary &other);

            ///
            /// \brief Move assignment operator.
            ///
            MeshLibrary     &operator=(MeshLibrary &&other) noexcept = default;
    };
}

#endif /* !__ENGINE_MESH_LIBRARY_HPP__ */
