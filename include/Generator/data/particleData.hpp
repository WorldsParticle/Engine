/* 
 * File:   particleData.hpp
 * Author: marie
 *
 * Created on 6 juillet 2016, 20:09
 */

#ifndef PARTICLEDATA_HPP
#define PARTICLEDATA_HPP

namespace Engine
{
    //TODO move this enum to engine
    enum ParticleType
    {
        RAIN,
        SNOW
    };
}

namespace GenData
{
    struct ParticleData
    {
        ParticleData(Engine::ParticleType const& t = Engine::RAIN)
        : type(t), density(1)
        {}
        
        Engine::ParticleType    type;
        int             density;
        
        //...
    };
}

#endif /* PARTICLEDATA_HPP */

