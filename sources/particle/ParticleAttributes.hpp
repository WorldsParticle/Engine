#ifndef PARTICLEATTRIBUTES_HPP
#define PARTICLEATTRIBUTES_HPP

#include    "glm/glm.hpp"


enum ParticleType { RAIN_PARTICLE, SNOW_PARTICLE };

/**
 * @brief The ParticleAttributes struct
 * Initial attributes of a particle
 */
struct ParticleAttributes
{
    //----------------------------------------
    // Maximum lifetime of the particle.
    //----------------------------------------
    int 	_lifetime = 0;

    glm::vec3	_forceMin = glm::vec3(0),
                _forceMax = glm::vec3(0);

    //----------------------------------------
    // Color of the Particle
    //----------------------------------------
    glm::vec4	_color = glm::vec4(1);

    glm::vec3   _scale = glm::vec3(1);

    //virtual ~ParticleAttributes() = 0;
};

//struct RainParticleAttributes : public ParticleAttributes
//{
//    RainParticleAttributes()
//        : ParticleAttributes()//, _lifetime(5.0f), _forceMax(3, -1, 3), _forceMin(0, -1, 0)
//    {
//        _lifetime = 5.0f;
//        _forceMin = glm::vec3(0,-3,0);
//        _forceMax = glm::vec3(3,-3,3);
//        _color = glm::vec4(100,100,255,255);
//        _baseScale = glm::vec3(0.1f,0.1f,0.1f);
//    }
//};

//struct SnowParticleAttributes : public ParticleAttributes
//{
//    SnowParticleAttributes()
//        : ParticleAttributes()
//    {
//        _lifetime = 5.0f;
//        _forceMin = glm::vec3(0,-1,0);
//        _forceMax = glm::vec3(3,-1,3);
//        _color = glm::vec4(255,255,255,255);
//        _baseScale = glm::vec3(0.1f,0.1f,0.1f);
//    }
//};


#endif // PARTICLEATTRIBUTES_HPP

