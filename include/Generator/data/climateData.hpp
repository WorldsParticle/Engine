/* 
 * File:   climateData.hpp
 * Author: marie
 *
 * Created on 6 juillet 2016, 20:07
 */

#ifndef CLIMATEDATA_HPP
#define CLIMATEDATA_HPP

#include "particleData.hpp"

namespace GenData
{
    struct ClimateData
    {
        ClimateData()
        : exploHour(12), particles()
        {}
        
        int exploHour;//on 24h
        
        std::vector<ParticleData>   particles;
        
    private:
        //skybox infos
    };
}

#endif /* CLIMATEDATA_HPP */

