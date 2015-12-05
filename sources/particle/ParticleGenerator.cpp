#include <algorithm>
#include "ParticleGenerator.hpp"

ParticleGenerator::ParticleGenerator(const glm::vec3 &position,
                                    const glm::vec3 &rotation,
                                    const glm::vec3 &scale)
    : GameObject(position, rotation, scale), _maxParticles(100), _minParticles(20)
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

//	if(_particles.size() < _maxParticles)
//		Emit(1);
//	for (std::list<Particle *>::iterator it = this->_particles.begin(); it != this->_particles.end(); ++it)
//	{
//		(*it)->Update();
//		if ((*it)->isAlive() == false)
//		{
//			_unused_particles.push_back(*it);
//			it = _particles.erase(it);
//		}
//	}
//	_unused_particles.clear();

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
	  force.x = rand() % 3 / 10.0f;
      force.y = -0.1f;
	  force.z = rand() % 3 / 10.0f;

      newParticle = new Particle(position);
      newParticle->setLifetime(rand() % 200 / 10.0f);
      newParticle->setForce(force);

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