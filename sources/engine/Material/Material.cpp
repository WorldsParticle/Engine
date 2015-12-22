#include "Material.hpp"

namespace   WorldParticles
{
    namespace   Engine
    {

        ///
        /// PUBLIC CONSTRUCTOR
        ///

        Material::Material(void) :
            color(glm::vec4(1.0, 1.0, 1.0, 1.0))
        {
            // nothing to do
        }

        Material::~Material(void)
        {
            // nothind to do
        }

        ///
        /// PUBLIC GETTER
        ///
        const glm::vec4 &
        Material::getColor(void) const
        {
            return this->color;
        }


        ///
        /// PUBLIC SETTER
        ///

        void
        Material::setColor(const glm::vec4 &color)
        {
            this->color = color;
        }
    }
}
