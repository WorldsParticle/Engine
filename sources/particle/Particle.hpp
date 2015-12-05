#ifndef PARTICLE_HPP
#define PARTICLE_HPP

#include <iostream>
#include "Cube.hpp"
#include "GameClock.hpp"

class Particle : public WorldParticles::Engine::Primitives::Cube
{
    typedef WorldParticles::Engine::Primitives::Cube BaseClass;

public:
    Particle(const glm::vec3 &position = glm::vec3(0.0),
            const glm::vec3 &rotation = glm::vec3(0.0),
            const glm::vec3 &scale = glm::vec3(1.0));

public:
    void Update(void);

   //----------------------------------------
   //
   //----------------------------------------
   float	getLifetime(void) const
   {
     return _lifetime;
   }

   //----------------------------------------
   //
   //----------------------------------------
   bool	isAlive(void) const
   {
     return _lifetime > 0.0f;
   }

   //----------------------------------------
   //
   //----------------------------------------
   const glm::vec3	&getForce(void) const
   {
     return _force;
   }

public:
   //----------------------------------------
   //
   //----------------------------------------
   void	setLifetime(float newLifetime)
   {
     this->_lifetime = newLifetime;
   }

   //----------------------------------------
   //
   //----------------------------------------
   void	setForce(const glm::vec3 &newForce)
   {
     this->_force = newForce;
   }

private:
    //----------------------------------------
    // This attribute is used to save the lifetime of the particle.
    //----------------------------------------
    float	_lifetime;

    //----------------------------------------
    // This attribute is used to save the 3D position of the Particle
    //----------------------------------------
    glm::vec3	_force;
};

#endif // PARTICLE_HPP
