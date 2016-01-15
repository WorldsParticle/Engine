///
/// \file Animation.cpp
///
/// \author Martin-Pierrat Louis (mart_p)
///
/// \date Fri, 15 Jan 2016 13:27:48
///
/// \version 1.0.1
///

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

        Animation::Animation(Animation &&other) noexcept :
            name(std::move(other.name))
        {
            // nothing more to do actually.
        }

        Animation::~Animation(void)
        {

        }



        Animation &
        Animation::operator=(const Animation &other)
        {
            this->name = other.name;
            return *this;
        }

        Animation &
        Animation::operator=(Animation &&other) noexcept
        {
            this->name = std::move(other.name);
            return *this;
        }

    }
}
