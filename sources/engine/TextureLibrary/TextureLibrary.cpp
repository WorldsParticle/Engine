#include    "TextureLibrary.hpp"

namespace   WorldParticles
{
    namespace   Engine
    {
        TextureLibrary::TextureLibrary(void) :
            Library<Texture>()
        {
            // nothing to do.
        }

        TextureLibrary::TextureLibrary(const aiTexture *assimpTextures, unsigned int size) :
            Library<Texture>()
        {
            this->resources.reserve(size);
            for (unsigned int i = 0 ; i < size ; ++i)
            {
                this->resources.push_back(new Texture(assimpTextures[i]));
            }
        }

        TextureLibrary::~TextureLibrary(void)
        {
            // nothing to do.
        }

    }
}
