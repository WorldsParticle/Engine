#ifndef PARTICLEGENERATOR_HPP
#define PARTICLEGENERATOR_HPP

#include <list>
#include "GameObject.hpp"
#include "Particle.hpp"



class ParticleGenerator : public WorldParticles::Engine::GameObject
{
public:
    ParticleGenerator(const glm::vec3 &position = glm::vec3(0.0),
                      const glm::vec3 &rotation = glm::vec3(0.0),
                      const glm::vec3 &scale = glm::vec3(1.0))
        :GameObject(position, rotation, scale), _particle(new Particle())
    {
        std::cout << "ctor : generateur de particules" << std::endl;
        Emit(3);
    }

    ~ParticleGenerator()
    {}

    void    Draw(const glm::mat4 &projection, const glm::mat4 &view);

    void    Update();

    //----------------------------------------
    // Emit is used to emit particles in the scene manually.
    //----------------------------------------
    void    Emit(int numberParticles);

private:
    Particle *  _particle;//test

    //----------------------------------------
    // This attribute is used to save the max particles number that can be draw by this ParticleSystem
    //----------------------------------------
    unsigned int		_maxParticles;

    //----------------------------------------
    // this attribute is used to contains particles that are used to draw animation.
    //----------------------------------------
    std::list<Particle *>	_particles;
};

#endif // PARTICLEGENERATOR_H
