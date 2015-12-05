#include "Particle.hpp"

Particle::Particle(const glm::vec3 &position,
                    const glm::vec3 &rotation,
                    const glm::vec3 &scale,
                    ParticleType type)
    : Cube(position, rotation, scale), _type(type)
{

    transform.SetPosition(glm::vec3(rand()%30 / 10.0f, 4.0f, rand()%30 / 10.0f));
}

void Particle::Update(void)
{
    float elapsedTime = WorldParticles::Engine::GameClock::elapsedTime() / 1000.0f;	//en secondes

    _lifetime -= elapsedTime;

    glm::vec3 position(transform.GetPosition());
    transform.SetPosition(position + _force * elapsedTime);

    //TODO : gérer la rotation selon l'orientation de la cam

    // this->_rotation.y = glm::mod(this->_rotation.y + 0.01f, 360.0f);

    /*glm::vec3 scale(transform.GetScale());
    scale.x += 0.001f;
    scale.y += 0.001f;
    scale.z += 0.001f;
    transform.SetScale(scale);*/
}
