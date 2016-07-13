
#include "Generator/data/zoneData.hpp"
#include "Generator/map/biome.hpp"

namespace GenData
{

ZoneData::ZoneData(map::Biome const& t, bool a)
: ParamData(),
    type(t), active("active"), density("density"),
    width("width (debug)"), height("height (debug)"), elementCountTotal("element count (debug)"),
    _elements(), _climate(new ClimateData())
{
    active.setValue(a);

    density.setMinValue(1);
    density.setMaxValue(100);
    density.setValue(50);

    width.setMinValue(1);
    width.setMaxValue(1000);
    width.setValue(500);

    height.setMinValue(1);
    height.setMaxValue(1000);
    height.setValue(500);

    elementCountTotal.setMinValue(1);
    elementCountTotal.setMaxValue(100);
    elementCountTotal.setValue(9);

//    _params.push_back(&active);
//    _params.push_back(&density);
    _params.push_back(&width);
    _params.push_back(&height);
    _params.push_back(&elementCountTotal);

    //TODO true list of elements
    _elements.push_back(new ElementData("Apple tree", "../Engine/resources/models/tree.DAE"));
    _elements.push_back(new ElementData("Cherry tree", "../Engine/resources/models/Tree1.obj"));
    _elements.push_back(new ElementData("Other tree", "../Engine/resources/models/Tree2.obj"));
    _elements.push_back(new ElementData("Rock", "../Engine/resources/models/Rock1.obj"));
    _elements.push_back(new ElementData("Little rock", "../Engine/resources/models/Rock2.obj"));
    _elements.push_back(new ElementData("Other rock", "../Engine/resources/models/Rock3.obj"));
    //_elements.push_back(new ElementData("Suzanne", "../Engine/resources/models/monkey.dae"));
    //_elements.push_back(new ElementData("Cube", "../Engine/resources/models/cube.obj"));
}

ZoneData::~ZoneData()
{
    _elements.clear();
    delete _climate;
}

}
