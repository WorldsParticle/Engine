
#pragma once

#include    <memory>
#include    <glm/glm.hpp>

#include    "Engine/Configuration.hpp"
#include <Engine/Core/Material.hpp>

namespace   Engine
{

    class   ShaderProgram;
    class   ShaderProgramLibrary;
    class   Texture;
    class   TextureLibrary;

    ///
    /// \brief This class is used to represent a LightningBoltMaterial which, applied to a mesh, determine how the mesh should be rendered.
    ///
    class ENGINE_EXPORTS LightningBoltMaterial : public Material
    {
        public:
            ///
            /// \brief Default constructor
            ///
            LightningBoltMaterial(const std::shared_ptr<ShaderProgram> &shaderprogram);

            ///
            /// \brief Copy constructor.
            ///
            LightningBoltMaterial(const LightningBoltMaterial &other) = default;

            ///
            /// \brief Move constructor.
            ///
            LightningBoltMaterial(LightningBoltMaterial &&other) noexcept = default;

            ///
            /// \brief Destructor
            ///
            virtual ~LightningBoltMaterial(void) noexcept;

        public:
            ///
            /// \brief Copy assignment operator.
            ///
            LightningBoltMaterial    &operator=(const LightningBoltMaterial &other) = default;

            ///
            /// \brief Move assignment operator.
            ///
            LightningBoltMaterial    &operator=(LightningBoltMaterial &&other) noexcept = default;

        public:
            ///
            /// \brief Bind the LightningBoltMaterial in the graphic pipeline.
            ///
            virtual void        bind(void) const override;

    private:
        ///
        /// \brief The name of the material
        ///
        std::string     m_name;

        ///
        /// \brief The shaderprogram used with this material.
        ///
        std::shared_ptr<ShaderProgram>  m_shaderprogram;

        ///
        /// \brief The ids of the textures of the material
        ///
        Texture     *m_texture;
    };
}
