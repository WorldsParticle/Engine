///
/// \file MaterialLibrary.hpp
///
/// \author Martin-Pierrat Louis (mart_p)
///
/// \date Sun, 17 Jan 2016 06:54:52
///
/// \version 1.0.5
///

#ifndef     __ENGINE_MATERIAL_LIBRARY_HPP__
# define    __ENGINE_MATERIAL_LIBRARY_HPP__

#include    <assimp/material.h>

#include    <Engine/Library.hpp>
#include    <Engine/Material.hpp>

namespace   Engine
{
    ///
    /// \brief This material library wrap the Library<Material> and provide a constructor from assimp materials.
    ///
    class       MaterialLibrary : public Library<Material *>
    {
        public:
            ///
            /// \brief Default constructor.
            ///
            MaterialLibrary(void);

            ///
            /// \brief Construct a library from an array of assimp materials.
            ///
            MaterialLibrary(const ShaderProgramLibrary &shaderprograms,
                    aiMaterial **assimpMaterials, unsigned int size);

            ///
            /// \brief Copy constructor.
            ///
            MaterialLibrary(const MaterialLibrary &other);

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
            MaterialLibrary     &operator=(const MaterialLibrary &other);

            ///
            /// \brief Move assignment operator.
            ///
            MaterialLibrary     &operator=(MaterialLibrary &&other) noexcept = default;


    };
}

#endif /* !__ENGINE_MATERIAL_LIBRARY_HPP__ */
