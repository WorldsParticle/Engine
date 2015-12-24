#ifndef     __MATERIAL_HPP__
# define    __MATERIAL_HPP__

#include    <glm/glm.hpp>
#include    <memory>

#include    "ShaderProgram.hpp"

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
                Material(const Material &other);

                ///
                /// \brief Move constructor.
                ///
                Material(Material &&other);

                ///
                /// \brief Destructor
                ///
                virtual ~Material(void) noexcept;

            public:
                ///
                /// \brief Copy assignment operator.
                ///
                Material    &operator=(const Material &other);

                ///
                /// \brief Move assignment operator.
                ///
                Material    &operator=(Material &&other);

            public:
                ///
                /// \brief Getter for the color attribute.
                /// \return the color.
                ///
                const glm::vec4     &getColor(void) const;

            public:
                ///
                /// \brief Setter for the color attribute.
                ///
                void                setColor(const glm::vec4 &color);

            private:
                ///
                /// \brief the color attribute is used to store the color of the material.
                ///
                glm::vec4                       color;
        };
    }
}

#endif /* !__MATERIAL_HPP__ */
