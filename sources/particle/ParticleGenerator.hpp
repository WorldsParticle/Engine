#ifndef PARTICLEGENERATOR_HPP
#define PARTICLEGENERATOR_HPP

#include <list>
#include "GameObject.hpp"
#include "Particle.hpp"
#include <ctime>


class ParticleGenerator : public WorldParticles::Engine::GameObject
{
public:
    ParticleGenerator(const glm::vec3 &position = glm::vec3(0.0),
                      const glm::vec3 &rotation = glm::vec3(0.0),
                      const glm::vec3 &scale = glm::vec3(1.0),
                      ParticleType type = RAIN_PARTICLE);
    ~ParticleGenerator()
    {}

    void    Draw(const glm::mat4 &projection, const glm::mat4 &view);

    void    Update();

    //----------------------------------------
    // Emit is used to emit particles in the scene manually.
    //----------------------------------------
    void    Emit(int numberParticles);

private:
    //----------------------------------------
    // This attribute is used to save the type of the generated particles
    //----------------------------------------
    ParticleType		_type;

    //----------------------------------------
    // This attribute is used to save the max particles number that can be draw by this ParticleSystem
    //----------------------------------------
    unsigned int		_maxParticles = 100;

    //----------------------------------------
    // This attribute is used to save the min particles number that we want to see on the screen
    //----------------------------------------
    unsigned int		_minParticles;

    //----------------------------------------
    // this attribute is used to contains particles that are used to draw animation.
    //----------------------------------------
    std::list<Particle *>	_particles;
//	std::list<Particle *>	_unused_particles;
};

#endif // PARTICLEGENERATOR_H
