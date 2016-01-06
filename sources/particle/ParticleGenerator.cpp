#include <algorithm>
#include "ParticleGenerator.hpp"
#include "SnowParticle.hpp"
#include "RainParticle.hpp"

ParticleGenerator::ParticleGenerator(const glm::vec3 &position,
                                    const glm::vec3 &rotation,
                                    const glm::vec3 &scale,
                                    ParticleType type)
    : GameObject(position, rotation, scale),
      _maxParticles(100), _minParticles(20), _type(type)
{
    srand((unsigned int)time(0));

    Emit(rand() % _maxParticles + _minParticles);
}

void    ParticleGenerator::Update()
{
    if (_particles.size() < _maxParticles)
    {
        Emit(rand() % _maxParticles + _minParticles);
//        Emit(_maxParticles);
    }

    std::for_each(_particles.begin(), _particles.end(), [&](Particle *p){
        p->Update();
    });

    std::list<Particle*>::iterator it = _particles.begin();
    while (it != _particles.end())
    {
        Particle* tmp = *it;
        if (!tmp->isAlive())
        {
            it = _particles.erase(it);
            delete tmp;
        }
        else
        {
            it++;
        }
    }
}


void ParticleGenerator::Draw(const glm::mat4 &projection, const glm::mat4 &view)
{
  if (_particles.empty())
    return;

  std::for_each(_particles.begin(), _particles.end(), [&](Particle *p){
      p->Draw(projection, view);
  });
}


//----------------------------------------
// Emit is used to emit particles in the scene manually.
//----------------------------------------
void    ParticleGenerator::Emit(int numberParticles)
{
  glm::vec3	position, force;
  Particle	*newParticle;
  int i = 0;
  float delta = 1.0f / numberParticles;

  while (numberParticles > 0 && _maxParticles != _particles.size())
  {
      position.x = (i * delta);
//      newParticle = new Particle(position);
//      ParticleAttributes const& attr = newParticle->getAttributes();
//      newParticle->setLifetime(rand() % 200 / 10.0f);
//      newParticle->setForce(force);

//      force.x = rand() % 3 / 10.0f;
//      force.y = -0.1f;
//      force.z = rand() % 3 / 10.0f;

      switch(_type)
      {
      case SNOW_PARTICLE:
          newParticle = new SnowParticle(position);
          break;
      case RAIN_PARTICLE:
          newParticle = new RainParticle(position);
          break;
      default:
          return;
      }

      //newParticle = new SnowParticle(position);
      const ParticleAttributes& attr = newParticle->getAttributes();

      newParticle->setLifetime(rand() % attr._lifetime / 10.0f);
      force.x = rand() % (int)attr._forceMax.x / 10.0f;
      force.y = attr._forceMax.y / 10.0f;
      force.z = rand() % (int)attr._forceMax.z / 10.0f;
      newParticle->setForce(force);
      //TODO : set other attributes

      _particles.push_back(newParticle);
      --numberParticles;
      i++;
  }
}

////----------------------------------------
//// TODO
////----------------------------------------
//void    ParticleGenerator::Reinit(void)
//{
////  for (std::list<Particle *>::iterator it = this->_particles.begin() ; it != this->_particles.end() ; )
////    {
////  if ((*it)->isAlive() == false)
////    {
////      this->_unusedParticles.push_back((*it));
////      it = this->_particles.erase(it);
////    }
////  else
////    {
////      ++it;
////    }
////    }
//}
