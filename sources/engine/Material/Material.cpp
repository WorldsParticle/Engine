#include "Material.hpp"

namespace   WorldParticles
{
    namespace   Engine
    {

        Material::Material(void) :
            name("Default")
        {
            // nothing to do
        }

        Material::Material(const aiMaterial *assimpMaterial) :
            name("Default")
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
    }
}
