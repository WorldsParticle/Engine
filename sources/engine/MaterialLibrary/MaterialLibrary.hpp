#ifndef     __MATERIAL_LIBRARY_HPP__
# define    __MATERIAL_LIBRARY_HPP__

#include    "Library.hpp"
#include    "Material.hpp"

namespace   WorldParticles
{
    namespace   Engine
    {
        class       MaterialLibrary : public Library<Material>
        {
            public:
                ///
                /// \brief Default constructor.
                ///
                MaterialLibrary(void);

                ///
                /// \brief Construct a library from an array of assimp materials.
                ///
                MaterialLibrary(const aiMaterial *assimpMaterials, unsigned int size);

                ///
                /// \brief Copy constructor.
                ///
                MaterialLibrary(const MaterialLibrary &other) = default;

                ///
                /// \brief Move constructor.
                ///
                MaterialLibrary(MaterialLibrary &&other) noexcept = default;

                ///
                /// \brief Destructor.
                ///
                virtual ~MaterialLibrary(void) noexcept;

            public:
                ///
                /// \brief Copy assignment operator.
                ///
                MaterialLibrary     &operator=(const MaterialLibrary &other) = default;

                ///
                /// \brief Move assignment operator.
                ///
                MaterialLibrary     &operator=(MaterialLibrary &&other) noexcept = default;


        };
    }
}

#endif /* !__MATERIAL_LIBRARY_HPP__ */
