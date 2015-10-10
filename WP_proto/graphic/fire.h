#ifndef FIRE_HPP
#define FIRE_HPP

#include <GL/gl.h>
#include <GL/glu.h>
#ifdef _WIN32
# include "model/tools.h"
#else
# include "../model/tools.h"
#endif

#define APPEAR_SPEED	5
#define BURN_SPEED	2
#define DISAPPEAR_SPEED	2

struct Particle
{
  float               factor;
  float               fade;
  Vec3D               clr;
  Vec3D               acc;
};

class Fire
{
public:
  static void	initialize(unsigned int maxPart = 5000);   // RESIZE LE NOMBRE MAX DE PARTICULE

  static void	drawBurn(const Vec3D &center,
             const Vec3D &dir,
             const Vec3D &grav,
			 float time);
  static void	drawAppear(const Vec3D &center,
               const Vec3D &dir,
               const Vec3D &grav,
			   float time);
  static void	drawDisappear(const Vec3D &center,
                 const Vec3D &dir,
                 const Vec3D &grav,
			     float time);

  typedef void  (*drawFunc)(const Vec3D &, const Vec3D &, const Vec3D &, float);

private:
  Fire(void);
  static void	placeParticle(unsigned int i);

  static Particle	*particles_;
  static unsigned int	maxPart_;
};

#endif /* FIRE_HPP */
