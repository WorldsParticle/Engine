#ifndef     __MATERIAL_HPP__
# define    __MATERIAL_HPP__

#include    <glm/glm.hpp>

namespace   WorldParticles
{
    namespace   Engine
    {
        ///
        /// \brief This class is used to represent a material which a gameobject should be drawed with.
        ///
        class   Material
        {
            public:
                ///
                /// \brief Default constructor
                ///
                Material(void);

                ///
                /// \brief Destructor
                ///
                ~Material(void);

            public:

                ///
                /// \brief Getter for the color attribute.
                /// \return the color.
                ///
                const glm::vec3 &GetColor(void) const
                {
                    return this->color;
                }

            private:
                ///
                /// \brief the color attribute is used to store the color of the material.
                ///
                glm::vec3   color;

                /// TODO Abstraction shader.
                // program shader

                /// TODO add texture
                // Texture
        };
    }
}

#endif /* !__MATERIAL_HPP__ */
