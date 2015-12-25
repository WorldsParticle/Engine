#include    "Texture.hpp"

namespace   WorldParticles
{
    namespace   Engine
    {
        Texture::Texture(void)
        {
            // nothing to do atm.
        }

        Texture::Texture(const aiTexture *assimpTexture)
        {
            // nothing to do atm.
        }

        Texture::Texture(Texture &&other)
        {
            // nothing to do atm.
        }

        Texture::~Texture(void)
        {
            // nothing to do atm.
        }



        Texture &
        Texture::operator=(const Texture &other)
        {
            return *this;
        }

        Texture &
        Texture::operator=(Texture &&other)
        {
             return *this;
        }
    }
}
