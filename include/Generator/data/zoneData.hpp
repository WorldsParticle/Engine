/* 
 * File:   zoneData.hpp
 * Author: marie
 *
 * Created on 6 juillet 2016, 19:58
 */

#ifndef ZONEDATA_HPP
#define ZONEDATA_HPP

#include <vector>
#include "Generator/map/biome.hpp"

#include "paramData.hpp"
#include "elementData.hpp"
#include "climateData.hpp"
#include "Generator/param/boolvalue.hpp"
#include "Generator/param/intvalue.hpp"


namespace GenData
{

class ZoneData : public ParamData
{
public:
    ZoneData(map::Biome const& t, bool a = false);
    ~ZoneData();

    //type
    map::Biome    type;
    
    inline const std::string    &name() const
    { return map::BiomeName::getBiomeName(type); }


    //params
    gen::BoolValue   active;
    gen::IntValue   density;

    inline std::vector<ElementData *>   &elements()
    { return _elements; }
    
    inline ClimateData *    climate()
    { return _climate; }

private:
    //std::vector<Zone>   voronoiZones;//useful?

    std::vector<ElementData *>    _elements;

    ClimateData *                 _climate;
};
}

#endif /* ZONEDATA_HPP */

