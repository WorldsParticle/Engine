#include "RainParticle.hpp"

RainParticle::RainParticle(const glm::vec3 &position,
                    const glm::vec3 &rotation,
                    const glm::vec3 &scale,
                    ParticleType type)
    : Particle(position, rotation, scale, type)
{
    _attr._lifetime = 50.0f;
    _attr._forceMin = glm::vec3(0,-3,0);
    _attr._forceMax = glm::vec3(1,-10,1);
    _attr._color = glm::vec4(100,100,255,255);
    _attr._scale = glm::vec3(0.1f,0.1f,0.1f);
}
