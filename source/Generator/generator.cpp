#include "Generator/generator.hpp"

#include "Generator/map/map.hpp"
#include "Generator/steps/zoningstep.hpp"
#include "Generator/steps/shaperstep.hpp"
#include "Generator/steps/elevatorstep.hpp"
#include "Generator/steps/riverorstep.hpp"
#include "Generator/steps/moistorstep.hpp"
#include "Generator/steps/biomizatorstep.hpp"
#include "Generator/heightmap.hpp"

namespace gen
{

Generator::Generator() :
    m_heightmap(nullptr),
    m_steps()
{
    m_steps.push_back(new ZoningStep());
    m_steps.push_back(new ShaperStep());
    m_steps.push_back(new ElevatorStep());
    m_steps.push_back(new RiverorStep());
    m_steps.push_back(new MoistorStep());
    m_steps.push_back(new BiomizatorStep());
}

void    Generator::run(map::MapGraph *map)
{
    for (const auto &step: m_steps)
    {
        std::cout << step->name();
        step->launch(map);
    }

    m_heightmap = new map::HeightMap(map->xMax(), map->yMax());
    std::cout << "making heightmap..." << std::endl;
    m_heightmap->init(*map);
}

}
