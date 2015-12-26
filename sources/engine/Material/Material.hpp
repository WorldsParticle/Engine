#ifndef     __MATERIAL_HPP__
# define    __MATERIAL_HPP__

#include    <glm/glm.hpp>
#include    <assimp/material.h>

namespace   WorldParticles
{
    namespace   Engine
    {
        ///
        /// \brief This class is used to represent a material which, applied to a mesh, determine how the mesh should be rendered.
        ///
        class   Material
        {
            public:
                ///
                /// \brief Default constructor
                ///
                Material(void);

                ///
                /// \brief Construct a material from an assimp material.
                ///
                Material(const aiMaterial *assimpMaterial);

                ///
                /// \brief Copy constructor.
                ///
                Material(const Material &other) = default;

                ///
                /// \brief Move constructor.
                ///
                Material(Material &&other) noexcept = default;

                ///
                /// \brief Destructor
                ///
                virtual ~Material(void) noexcept;

            public:
                ///
                /// \brief Copy assignment operator.
                ///
                Material    &operator=(const Material &other) = default;

                ///
                /// \brief Move assignment operator.
                ///
                Material    &operator=(Material &&other) noexcept = default;

            public:
                ///
                /// \brief Getter for the name attribute.
                /// \return the name of the material.
                ///
                const std::string   &getName(void) const;

            public:
                ///
                /// \brief Setter for the name attribute.
                ///
                void    setName(const std::string &name);

            private:
                ///
                /// \brief The name of the material.
                ///
                std::string         name;
        };
    }
}

#endif /* !__MATERIAL_HPP__ */
