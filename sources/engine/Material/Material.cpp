#include "Material.hpp"

namespace   WorldParticles
{
    namespace   Engine
    {

        Material::Material(void)
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

        void
        Material::setColor(const glm::vec4 &color)
        {
            this->color = color;
        }
    }
}
