///
/// \file Material.cpp
///
/// \author Martin-Pierrat Louis (mart_p)
///
/// \date Sun, 17 Jan 2016 06:54:13
///
/// \version 1.0.3
///

#include    <Engine/Material.hpp>
#include    <Engine/ShaderProgram.hpp>

namespace   Engine
{

    Material::Material(const std::shared_ptr<ShaderProgram> &shaderprogram) :
        name("Default"),
        shaderprogram(shaderprogram)
    {
        // nothing to do
    }

    Material::Material(const aiMaterial *assimpMaterial,
            const std::shared_ptr<ShaderProgram> &shaderprogram) :
        name("Default"),
        shaderprogram(shaderprogram)
    {
        aiString assimpName;

        assimpMaterial->Get(AI_MATKEY_NAME, assimpName);
        this->name = assimpName.C_Str();
        // nothing to do atm.
    }

    Material::~Material(void) noexcept
    {
        // nothind to do.
    }



    const std::string &
    Material::getName(void) const
    {
        return this->name;
    }



    void
    Material::setName(const std::string &name)
    {
        this->name = name;
    }



    const std::shared_ptr<ShaderProgram> &
    Material::getShaderProgram(void) const
    {
         return this->shaderprogram;
    }

    void
    Material::bind(void) const
    {
        this->shaderprogram->bind();
    }

    void
    Material::unbind(void) const
    {
         this->shaderprogram->unbind();
    }
}
