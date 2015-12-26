#ifndef     __MESH_LIBRARY_HPP__
# define    __MESH_LIBRARY_HPP__

#include    "Library.hpp"
#include    "Mesh.hpp"

namespace   WorldParticles
{
    namespace   Engine
    {
        class       MeshLibrary : public Library<Mesh>
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
                MeshLibrary(aiMesh **assimpMeshes, unsigned int size);

                ///
                /// \brief Copy constructor.
                ///
                MeshLibrary(const MeshLibrary &other) = default;

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
                MeshLibrary     &operator=(const MeshLibrary &other) = default;

                ///
                /// \brief Move assignment operator.
                ///
                MeshLibrary     &operator=(MeshLibrary &&other) noexcept = default;
        };
    }
}

#endif /* !__MESH_LIBRARY_HPP__ */
