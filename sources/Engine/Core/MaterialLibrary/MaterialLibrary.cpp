///
/// \file MaterialLibrary.cpp
///
/// \author Martin-Pierrat Louis (mart_p)
///
/// \date Sat, 16 Jan 2016 20:48:08
///
/// \version 1.0.2
///

#include    <Engine/MaterialLibrary.hpp>
#include    <Engine/Material.hpp>
#include    <Engine/ShaderProgramLibrary.hpp>

namespace   WorldParticles
{
    namespace   Engine
    {
        MaterialLibrary::MaterialLibrary(void) :
            Library<Material *>()
        {
            // nothing to do.
        }

        MaterialLibrary::MaterialLibrary(const ShaderProgramLibrary &shaderprograms,
                aiMaterial **assimpMaterials, unsigned int size) :
            Library<Material *>()
        {
            this->resources.reserve(size);
            for (unsigned int i = 0 ; i < size ; ++i)
            {
                const auto &shaderprogram = shaderprograms.get(TEST_SHADER_PROGRAM);
                this->resources.push_back(new Material(assimpMaterials[i], shaderprogram));
            }
        }

        MaterialLibrary::MaterialLibrary(const MaterialLibrary &other) :
            Library<Material *>()
        {
            this->resources.reserve(other.resources.size());
            for (Material *resource : other.resources)
            {
                this->resources.push_back(new Material(*resource));
            }
        }

        MaterialLibrary::~MaterialLibrary(void)
        {
            for (Material *resource : this->resources)
            {
                delete resource;
            }
        }


        MaterialLibrary &
        MaterialLibrary::operator=(const MaterialLibrary &other)
        {
             this->resources.reserve(other.resources.size());
             for (Material *resource : other.resources)
             {
                 this->resources.push_back(new Material(*resource));
             }
             return *this;
        }
    }
}
