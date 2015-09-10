#include <ctime>
#include <cstdlib>
#include "fire.h"

static float	rainbowClrs[12][3] = 
  {
    {1.0, 0.5, 0.5}, {1.0, 0.75, 0.5}, {1.0, 1.0, 0.5}, {0.75, 1.0, 0.5},
    {0.5, 1.0, 0.5}, {0.5, 1.0, 0.75}, {0.5, 1.0, 1.0}, {0.5, 0.75, 1.0},
    {0.5, 0.5, 1.0}, {0.75, 0.5, 1.0}, {1.0, 0.5, 1.0}, {1.0, 0.5, 0.75}
  };

static float	myRandf()
{
  return static_cast<float>(rand() % 1001) / 1000.;
}

static float	myRandnf()
{
  return static_cast<float>(rand() % 2001 - 1000) / 1000.;
}

Particle	*Fire::particles_ = NULL;
unsigned int	Fire::maxPart_ = 1000;

void	Fire::initialize(unsigned int maxPart)
{
  if (particles_ != NULL)
    delete[] particles_;

  maxPart_ = maxPart;
  particles_ = new Particle[maxPart_];

  for (unsigned int i = 0; i < maxPart; ++i)
      placeParticle(i);
}

void	Fire::drawBurn(const Vec3D &center,
               const Vec3D &dir,
               const Vec3D &grav,
		       float time)
{
  float	x;
  float	y;
  float	z;
  float	alpha;

  time *= BURN_SPEED;

  glBegin(GL_TRIANGLE_STRIP);
  for (unsigned int i = 0; i < maxPart_; ++i)
    {
      alpha = time * particles_[i].fade;
      alpha -= static_cast<int>(alpha);

      glColor4f(particles_[i].clr.x(),
        particles_[i].clr.y(),
        particles_[i].clr.z(),
		1 - alpha);

      x = center.x() + particles_[i].factor * dir.x() + alpha * (particles_[i].acc.x() + grav.x());
      y = center.y() + particles_[i].factor * dir.y() + alpha * (particles_[i].acc.y() + grav.y());
      z = center.z() + particles_[i].factor * dir.z() + alpha * (particles_[i].acc.z() + grav.z());
      glVertex3f(x, y, z);
    }
  glEnd();
}

void	Fire::drawAppear(const Vec3D &center,
             const Vec3D &dir,
             const Vec3D &grav,
			 float time)
{
  float x;
  float y;
  float z;
  float alpha;
  float diff;

  time *= APPEAR_SPEED;

  glBegin(GL_TRIANGLE_STRIP);
  for (unsigned int i = 0; i < maxPart_; ++i)
    {
      if (time < particles_[i].factor)
	continue;

      diff = time - particles_[i].factor;
      alpha = diff * particles_[i].fade;
      alpha -= static_cast<int>(alpha);

      glColor4f(particles_[i].clr.x(),
                particles_[i].clr.y(),
                particles_[i].clr.z(),
                1 - alpha);

      x = center.x() + particles_[i].factor * dir.x() + alpha * (particles_[i].acc.x() + grav.x());
      y = center.y() + particles_[i].factor * dir.y() + alpha * (particles_[i].acc.y() + grav.y());
      z = center.z() + particles_[i].factor * dir.z() + alpha * (particles_[i].acc.z() + grav.z());
      glVertex3f(x, y, z);
    }
  glEnd();
}

void	Fire::drawDisappear(const Vec3D &center,
               const Vec3D &dir,
               const Vec3D &grav,
			   float time)
{
  float x;
  float y;
  float z;
  float alpha;

  time *= DISAPPEAR_SPEED;

  glBegin(GL_TRIANGLE_STRIP);
  for (unsigned int i = 0; i < maxPart_; ++i)
    {
      alpha = time / particles_[i].fade;
      alpha -= static_cast<int>(alpha);
      glColor4f(particles_[i].clr.x(),
                particles_[i].clr.y(),
                particles_[i].clr.z(),
                alpha);

      x = center.x() + particles_[i].factor * dir.x() + alpha * (particles_[i].acc.x() + grav.x());
      y = center.y() + particles_[i].factor * dir.y() + alpha * (particles_[i].acc.y() + grav.y());
      z = center.z() + particles_[i].factor * dir.z() + alpha * (particles_[i].acc.z() + grav.z());
      glVertex3f(x, y, z);
    }
  glEnd();
}

void	Fire::placeParticle(unsigned int i)
{
  float         factor = static_cast<float>(i) / static_cast<float>(maxPart_);

  particles_[i].factor = factor;
  particles_[i].fade = myRandf();
  particles_[i].acc = Vec3D(myRandnf() / 2., myRandnf() / 2., myRandnf() / 2.);

  particles_[i].clr = Vec3D(rainbowClrs[static_cast<int>(factor * 12)][0],
			 rainbowClrs[static_cast<int>(factor * 12)][1],
			 rainbowClrs[static_cast<int>(factor * 12)][2]);
}
