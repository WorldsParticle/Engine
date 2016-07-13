
#include "Generator/data/zoneData.hpp"
#include "Generator/map/biome.hpp"

namespace GenData
{

ZoneData::ZoneData(map::Biome const& t, bool a)
: ParamData(),
type(t), active("active"), density("density"), _elements(), _climate(new ClimateData())
{
    active.setValue(a);

    density.setMinValue(1);
    density.setMaxValue(100);
    density.setValue(50);

    _params.push_back(&active);
    _params.push_back(&density);

    //TODO true list of elements
    _elements.push_back(new ElementData("Apple tree", "../Engine/resources/models/tree.DAE"));
    _elements.push_back(new ElementData("Rock", "../Engine/resources/models/Rock1.obj"));
    //_elements.push_back(new ElementData("Suzanne", "../Engine/resources/models/monkey.dae"));
    //_elements.push_back(new ElementData("Cube", "../Engine/resources/models/cube.obj"));
}

ZoneData::~ZoneData()
{
    _elements.clear();
    delete _climate;
}

}
