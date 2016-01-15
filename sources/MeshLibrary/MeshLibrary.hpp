///
/// \file MeshLibrary.hpp
///
/// \author Martin-Pierrat Louis (mart_p)
///
/// \date Fri, 15 Jan 2016 13:31:40
///
/// \version 1.0.1
///

#ifndef     __MESH_LIBRARY_HPP__
# define    __MESH_LIBRARY_HPP__

#include    "Library.hpp"
#include    "Mesh.hpp"

namespace   WorldParticles
{
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
}

#endif /* !__MESH_LIBRARY_HPP__ */
