#include    "TextureLibrary.hpp"

namespace   WorldParticles
{
    namespace   Engine
    {
        TextureLibrary::TextureLibrary(void) :
            Library<Texture *>()
        {
            // nothing to do.
        }

        TextureLibrary::TextureLibrary(aiTexture **assimpTextures, unsigned int size) :
            Library<Texture *>()
        {
            this->resources.reserve(size);
            for (unsigned int i = 0 ; i < size ; ++i)
            {
                this->resources.push_back(new Texture(assimpTextures[i]));
            }
        }

        TextureLibrary::TextureLibrary(const TextureLibrary &other) :
            Library<Texture *>()
        {
            this->resources.reserve(other.resources.size());
            for (Texture *resource : other.resources)
            {
                this->resources.push_back(new Texture(*resource));
            }
        }

        TextureLibrary::~TextureLibrary(void)
        {
            // nothing to do.
        }



        TextureLibrary &
        TextureLibrary::operator=(const TextureLibrary &other)
        {
             this->resources.reserve(other.resources.size());
             for (Texture *resource : other.resources)
             {
                 this->resources.push_back(new Texture(*resource));
             }
             return *this;
        }

    }
}
