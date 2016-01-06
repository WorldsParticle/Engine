#ifndef SNOWPARTICLE_H
#define SNOWPARTICLE_H

#include "Particle.hpp"

class SnowParticle : public Particle
{
public:
    SnowParticle(const glm::vec3 &position = glm::vec3(0.0),
                const glm::vec3 &rotation = glm::vec3(0.0),
                const glm::vec3 &scale = glm::vec3(1.0),
                ParticleType type = SNOW_PARTICLE);

};

#endif // SNOWPARTICLE_H
