#include    "MeshLibrary.hpp"

namespace   WorldParticles
{
    namespace   Engine
    {
        MeshLibrary::MeshLibrary(void) :
            Library<Mesh>()
        {
            // nothing to do.
        }

        MeshLibrary::MeshLibrary(const aiMesh *assimpMeshes, unsigned int size)
        {
            this->resources.reserve(size);
            for (unsigned int i = 0 ; i < size ; ++i)
            {
                this->resources.push_back(new Mesh(assimpMeshes[i]));
            }
        }

        MeshLibrary::~MeshLibrary(void)
        {
            // nothing to do.
        }
    }
}
