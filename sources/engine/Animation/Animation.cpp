#include    "Animation.hpp"

namespace   WorldParticles
{
    namespace   Engine
    {
        Animation::Animation(void) :
            name("")
        {
            // nothing more to do actually.
        }

        // TODO GSL NOT NULL
        Animation::Animation(const aiAnimation *assimpAnimation) :
            name(assimpAnimation->mName.C_Str())
        {
            // TODO
        }

        Animation::Animation(const Animation &other) :
            name(other.name)
        {
            // nothing more to do actually.
        }

        Animation::Animation(Animation &&other) :
            name(std::move(other.name))
        {
            // nothing more to do actually.
        }



        Animation &
        Animation::operator=(const Animation &other)
        {
            this->name = other.name;
            return *this;
        }

        Animation &
        Animation::operator=(Animation &&other)
        {
            this->name = std::move(other.name);
            return *this;
        }

    }
}
