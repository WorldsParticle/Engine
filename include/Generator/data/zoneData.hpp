/* 
 * File:   zoneData.hpp
 * Author: marie
 *
 * Created on 6 juillet 2016, 19:58
 */

#ifndef ZONEDATA_HPP
#define ZONEDATA_HPP

#include <vector>
#include "paramData.hpp"
#include "elementData.hpp"
#include "climateData.hpp"
//#include "../map/zone.hpp"
#include "../param/boolvalue.hpp"
#include "../param/intvalue.hpp"
#include "climateData.hpp"

namespace GenData
{

class ZoneData : public ParamData
{
public:
    //ctor
    ZoneData(map::Biome const& t, bool a = false)
    : ParamData(),
    type(t), active("active"), density("density"), _elements()//, climate(new ClimateData())
    {
        active.setValue(a);

        density.setMinValue(1);
        density.setMaxValue(100);
        density.setValue(50);

        _params.push_back(&active);
        _params.push_back(&density);

        //TODO true list of elements
        _elements.push_back(new ElementData("Apple tree", "../Engine/resources/models/tree.DAE"));
        _elements.push_back(new ElementData("Suzanne", "../Engine/resources/models/monkey.dae"));
    }


    //type
    map::Biome    type;
    
    inline const std::string    &name() const
    { return map::BiomeName::getBiomeName(type); }


    //params
    gen::BoolValue   active;
    gen::IntValue   density;

    inline std::vector<ElementData *>   &elements()
    { return _elements; }
    
    //ClimateData *climate;
    

private:
    //std::vector<Zone>   voronoiZones;//useful?

    std::vector<ElementData *>    _elements;
};
}

#endif /* ZONEDATA_HPP */

