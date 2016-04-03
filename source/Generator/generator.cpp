#include "Generator/generator.hpp"

#include "Generator/map/map.hpp"
#include "Generator/voronoi/voronoi.hpp"
#include "Generator/shaper.hpp"
#include "Generator/elevator.hpp"
#include "Generator/riveror.hpp"
#include "Generator/moistor.hpp"
#include "Generator/biomizator.hpp"
#include "Generator/heightmap.hpp"

namespace GEN
{

Generator::Generator() :
    _map(nullptr),
    _heightmap(nullptr),
    _fillStep(nullptr),
    _shapeStep(nullptr),
    _elevateStep(nullptr),
    _riverStep(nullptr),
    _moistureStep(nullptr),
    _biomeStep(nullptr)
{
    _fillStep = new VOR::Voronoi();
}

MAP_NAMESPACE::Map    *Generator::generate(double xMax, double yMax, unsigned int zoneNumber)
{
    _map = new MAP_NAMESPACE::Map(xMax, yMax, zoneNumber);

    MAP_NAMESPACE::Zone::indexMax = 0;
    MAP_NAMESPACE::Corner::indexMax = 0;
    MAP_NAMESPACE::CrossedEdge::indexMax = 0;

    _fillStep->generate(_map);

    _shapeStep = new SHA::Shaper();
    _shapeStep->generate(_map);

    _elevateStep = new ELE::Elevator();
    _elevateStep->generate(_map);

    _riverStep = new RIV::Riveror();
    _riverStep->generate(_map);

    _moistureStep = new MOI::Moistor();
    _moistureStep->generate(_map);

    _biomeStep = new BIO::Biomizator();
    _biomeStep->generate(_map);

    MAP_NAMESPACE::HeightMap h(xMax, yMax);
    std::cout << "making heightmap..." << std::endl;
    h.init(*_map);
    std::cout << "painting..." << std::endl;
    h.paintByHeight();
    h.paintByMoisture();
    h.paintByLandType();
    h.paintByBiome();
    std::cout << "painted..." << std::endl;
    _heightmap = new MAP_NAMESPACE::HeightMap(h);

    return _map;
}

}
