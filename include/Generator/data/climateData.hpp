/* 
 * File:   climateData.hpp
 * Author: marie
 *
 * Created on 6 juillet 2016, 20:07
 */

#ifndef CLIMATEDATA_HPP
#define CLIMATEDATA_HPP

#include "paramData.hpp"
//#include "particleData.hpp"

#include "Generator/param/intvalue.hpp"
#include "Generator/param/boolvalue.hpp"

namespace GenData
{
    class ClimateData : public ParamData
    {
    public:
        ClimateData()
        : ParamData(),
            exploHour("exploration hour"), frameBuffer("post effect")//, particles()
        {
            exploHour.setMinValue(0);
            exploHour.setMaxValue(23);
            exploHour.setValue(12);

            frameBuffer.setValue(false);

            _params.push_back(&exploHour);
            _params.push_back(&frameBuffer);
        }
        
        gen::IntValue    exploHour;//on 24h
        gen::BoolValue   frameBuffer;
        
        //std::vector<ParticleData>   particles;
        
    private:
        //skybox infos
    };
}

#endif /* CLIMATEDATA_HPP */

