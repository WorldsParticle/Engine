///
/// \file MeshLibrary.hpp
///
/// \author Martin-Pierrat Louis (mart_p)
///
/// \date Sun, 17 Jan 2016 06:56:03
///
/// \version 1.0.5
///

#ifndef     __ENGINE_MESH_LIBRARY_HPP__
# define    __ENGINE_MESH_LIBRARY_HPP__

#include    <Engine/Library.hpp>
#include    <Engine/Mesh.hpp>

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
