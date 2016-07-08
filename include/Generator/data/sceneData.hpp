/* 
 * File:   sceneData.hpp
 * Author: marie
 *
 * Created on 8 juillet 2016, 19:31
 */

#ifndef SCENEDATA_HPP
#define SCENEDATA_HPP

#include <vector>
#include "paramData.hpp"
#include "zoneData.hpp"
#include "Generator/map/map.hpp"

namespace GenData
{

class SceneData : public ParamData
{
public:
    //ctor
    SceneData()
    : ParamData(),
    _zones()
    {
        for (int i = 0; i < map::BIOME_COUNT; i++)
        {
            _zones.push_back(new ZoneData(static_cast<map::Biome>(i)));//TODO how to prevent all zone to be desactivated?
        }
    }
    
    ~SceneData()
    {
        _zones.clear();
    }
    
    inline std::vector<ZoneData *>   &zones()
    { return _zones; }

private:
    std::vector<ZoneData *>    _zones;
};
}

#endif /* SCENEDATA_HPP */

