#include    "MaterialLibrary.hpp"
#include    "Material.hpp"

namespace   WorldParticles
{
    namespace   Engine
    {
        MaterialLibrary::MaterialLibrary(void) :
            Library<Material>()
        {
            // nothing to do.
        }

        MaterialLibrary::MaterialLibrary(const aiMaterial **assimpMaterials, unsigned int size) :
            Library<Material>()
        {
            this->resources.reserve(size);
            for (unsigned int i = 0 ; i < size ; ++i)
            {
                this->resources.push_back(new Material(assimpMaterials[i]));
            }
        }

        MaterialLibrary::~MaterialLibrary(void)
        {
            // nothing to do.
        }
    }
}
