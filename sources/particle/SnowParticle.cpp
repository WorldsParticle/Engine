#include "SnowParticle.hpp"

SnowParticle::SnowParticle(const glm::vec3 &position,
                    const glm::vec3 &rotation,
                    const glm::vec3 &scale,
                    ParticleType type)
    : Particle(position, rotation, scale, type)
{
    _attr._lifetime = 50.0f;
    _attr._forceMin = glm::vec3(0,-1,0);
    _attr._forceMax = glm::vec3(3,-1,3);
    _attr._color = glm::vec4(255,255,255,255);
    _attr._scale = glm::vec3(0.1f,0.1f,0.1f);
}

