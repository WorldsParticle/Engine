#include <algorithm>
#include "ParticleGenerator.hpp"

void    ParticleGenerator::Update()
{
  // std::cout << "particles used : " << this->_particles.size() << std::endl;
  // std::cout << "particles unused : " << this->_unusedParticles.size() << std::endl;

    std::for_each(_particles.begin(), _particles.end(), [](Particle *p){
        p->Update();
    });
}


void ParticleGenerator::Draw(const glm::mat4 &projection, const glm::mat4 &view)
{
  if (this->_particles.empty())
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
      force.y = -0.1f;

      newParticle = new Particle(position);
      newParticle->setLifetime(5.0f);
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
