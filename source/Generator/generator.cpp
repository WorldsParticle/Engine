#include "Generator/generator.hpp"

#include "Generator/map/map.hpp"
#include "Generator/steps/zoningstep.hpp"
#include "Generator/steps/shaperstep.hpp"
#include "Generator/steps/elevatorstep.hpp"
#include "Generator/steps/riverorstep.hpp"
#include "Generator/steps/moistorstep.hpp"
#include "Generator/steps/biomizatorstep.hpp"
#include "Generator/steps/heightmapingstep.hpp"

using GenData::ZoneData;

namespace gen
{

Generator::Generator()
    : m_steps(),
      m_zoneDatas()
{
    m_steps.push_back(new ZoningStep());
    m_steps.push_back(new ShaperStep());
    m_steps.push_back(new ElevatorStep());
    m_steps.push_back(new RiverorStep());
    m_steps.push_back(new MoistorStep());
    m_steps.push_back(new BiomizatorStep());
    m_steps.push_back(new HeightMapingStep());
    
    for (int i = 0; i < map::BIOME_COUNT; i++)
    {
        m_zoneDatas.push_back(ZoneData(static_cast<map::Biome>(i)));
        //TODO how to prevent all zone to be desactivated?
        
        //test compil
        //std::cout << map::BiomeName::getBiomeName(map::OCEAN);
    }
}

void    Generator::run(map::MapGraph *map)
{
    for (const auto &step: m_steps)
    {
        std::cout << step->name() << std::endl;
        step->launch(map);
    }
}

GenerationStep  *Generator::stepFromName(const std::string &namee)
{
    for (const auto &s: m_steps)
        if (s->name() == namee)
            return s;
    return (nullptr);
}

}
