#include "Material.hpp"

namespace   WorldParticles
{
    namespace   Engine
    {

        Material::Material(void) :
            color(glm::vec4(1.0f))
        {
            // nothing to do
        }

        Material::Material(const aiMaterial *assimpMaterial) :
            color(glm::vec4(1.0f))
        {
            // nothing to do atm.
        }

        Material::Material(const Material &other) :
            color(other.color)
        {
            // nothing to do.
        }

        Material::Material(Material &&other) noexcept :
            color(std::move(other.color))
        {
            // nothing to do.
        }

        Material::~Material(void) noexcept
        {
            // nothind to do.
        }



        Material &
        Material::operator=(const Material &other)
        {
            this->color = other.color;
            return *this;
        }

        Material &
        Material::operator=(Material &&other) noexcept
        {
            this->color = std::move(other.color);
            return *this;
        }



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
