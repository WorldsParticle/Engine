#include    <log4cpp/Category.hh>

#include    "MeshLibrary.hpp"
#include    "MaterialLibrary.hpp"

using namespace     log4cpp;

namespace   WorldParticles
{
    namespace   Engine
    {
        MeshLibrary::MeshLibrary(void) :
            Library<Mesh *>()
        {
            // nothing to do.
        }

        MeshLibrary::MeshLibrary(const MaterialLibrary &materials,
                aiMesh **assimpMeshes, unsigned int size) :
            Library<Mesh *>()
        {
            Category    &root = Category::getRoot();

            root << Priority::DEBUG << "MeshLibrary constructor with size = " << size;
            this->resources.reserve(size);
            for (unsigned int i = 0 ; i < size ; ++i)
            {
                const aiMesh *amesh = assimpMeshes[i];
                Material *material = materials.get(amesh->mMaterialIndex);
                this->resources.push_back(new Mesh(amesh, material));
            }
        }

        MeshLibrary::MeshLibrary(const MeshLibrary &other) :
            Library<Mesh *>()
        {
            this->resources.reserve(other.resources.size());
            for (Mesh *resource : other.resources)
            {
                 this->resources.push_back(new Mesh(*resource));
            }
        }

        MeshLibrary::~MeshLibrary(void)
        {
            for (Mesh *resource : this->resources)
            {
                delete resource;
            }
        }



        MeshLibrary &
        MeshLibrary::operator=(const MeshLibrary &other)
        {
             this->resources.reserve(other.resources.size());
             for (Mesh *resource : other.resources)
             {
                 this->resources.push_back(new Mesh(*resource));
             }
             return *this;
        }
    }
}