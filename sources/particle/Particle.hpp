#ifndef PARTICLE_HPP
#define PARTICLE_HPP

#include <iostream>
#include "Cube.hpp"

class Particle : public WorldParticles::Engine::Primitives::Cube
{
    typedef WorldParticles::Engine::Primitives::Cube BaseClass;

public:
    Particle(const glm::vec3 &position = glm::vec3(0.0),
            const glm::vec3 &rotation = glm::vec3(0.0),
            const glm::vec3 &scale = glm::vec3(1.0))
        : Cube(position, rotation, scale)
    {}

public:
    void Update(void)
    {
        float elapsedTime = 0.1f;//en secondes

        static_cast<BaseClass *>(this)->Update();

        _lifetime -= elapsedTime;

        glm::vec3 position(transform.GetPosition());
        transform.SetPosition( position + _force * elapsedTime );

        //TODO : gérer la rotation selon l'orientation de la cam

        // this->_rotation.y = glm::mod(this->_rotation.y + 0.01f, 360.0f);

        glm::vec3 scale(transform.GetScale());
        scale.x += 0.001f;
        scale.y += 0.001f;
        scale.z += 0.001f;
        transform.SetScale(scale);
    }

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
