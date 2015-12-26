#include    <log4cpp/Category.hh>

#include    "MeshLibrary.hpp"

using namespace     log4cpp;

namespace   WorldParticles
{
    namespace   Engine
    {
        MeshLibrary::MeshLibrary(void) :
            Library<Mesh>()
        {
            // nothing to do.
        }

        MeshLibrary::MeshLibrary(aiMesh **assimpMeshes, unsigned int size)
        {
            Category    &root = Category::getRoot();

            root << Priority::DEBUG << "MeshLibrary constructor with size = " << size;
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
