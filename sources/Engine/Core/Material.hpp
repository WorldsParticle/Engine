///
/// \file Material.hpp
///
/// \author Martin-Pierrat Louis (mart_p)
///
/// \date Sun, 17 Jan 2016 06:54:27
///
/// \version 1.0.5
///

#ifndef     __ENGINE_MATERIAL_HPP__
# define    __ENGINE_MATERIAL_HPP__

#include    <memory>
#include    <glm/glm.hpp>
#include    <assimp/material.h>

namespace   Engine
{
    class   ShaderProgram;
    class   ShaderProgramLibrary;
    ///
    /// \brief This class is used to represent a material which, applied to a mesh, determine how the mesh should be rendered.
    ///
    class   Material
    {
        public:
            ///
            /// \brief Default constructor
            ///
            Material(const std::shared_ptr<ShaderProgram> &shaderprogram);

            ///
            /// \brief Construct a material from an assimp material.
            ///
            Material(const aiMaterial *assimpMaterial,
                    const std::shared_ptr<ShaderProgram> &shaderprogram);

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
            /// \brief Bind the material in the graphic pipeline.
            ///
            void        bind(void) const;

            ///
            /// \brief Unbind the material off the graphic pipeline.
            ///
            void        unbind(void) const;

        public:
            ///
            /// \brief Getter for the name attribute.
            /// \return the name of the material.
            ///
            const std::string       &getName(void) const;

            ///
            /// \brief Getter for the shader program used by the material.
            /// \return the shader program.
            ///
            const std::shared_ptr<ShaderProgram>    &getShaderProgram(void) const;

        public:
            ///
            /// \brief Setter for the name attribute.
            ///
            void    setName(const std::string &name);

        private:
            ///
            /// \brief The name of the material.
            ///
            std::string                     name;

            ///
            /// \brief The shaderprogram used with this material.
            ///
            std::shared_ptr<ShaderProgram>  shaderprogram;
    };
}

#endif /* !__ENGINE_MATERIAL_HPP__ */
