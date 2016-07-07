#include <algorithm>
#include <log4cpp/Category.hh>

#include "Generator/generator.hpp"

#include "Engine/Core.hpp"
#include "Engine/Core/Scene.hpp"
#include "Engine/Core/Terrain.hpp"
#include "Engine/Core/Object.hpp"
#include "Engine/Core/Light.hpp"

#include "Generator/data/elementData.hpp"

#include "Generator/map/map.hpp"
#include "Generator/steps/zoningstep.hpp"
#include "Generator/steps/shaperstep.hpp"
#include "Generator/steps/elevatorstep.hpp"
#include "Generator/steps/riverorstep.hpp"
#include "Generator/steps/moistorstep.hpp"
#include "Generator/steps/biomizatorstep.hpp"
#include "Generator/steps/heightmapingstep.hpp"

using namespace log4cpp;
using GenData::ZoneData;
using GenData::ElementData;

namespace gen
{

Generator::Generator(Engine::Core *engine)
    :   m_steps(),
        m_zoneDatas(),
        //m_activeZoneDatas()
        m_terrain(nullptr),
        m_objects(),
        m_lights(),
        m_engine(engine)
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
        m_zoneDatas.push_back(new ZoneData(static_cast<map::Biome>(i)));//TODO how to prevent all zone to be desactivated?
    }
}

Generator::~Generator()
{
    m_steps.clear();
    m_zoneDatas.clear();

    if (m_terrain)
        delete m_terrain;
    m_objects.clear();//TODO check if not already cleared from the scene
    m_lights.clear();
}

void    Generator::run(map::MapGraph *map)
{
    for (const auto &step: m_steps)
    {
        std::cout << step->name() << std::endl;
        step->launch(map);
    }
}

void    Generator::addTerrain(map::HeightMap &hm)
{
    Engine::Scene   *scene = m_engine->scenes().front();
    if (!scene)
    {
        Category::getRoot() << Priority::WARN << "No scene to add terrain";
        return;
    }

    if (m_terrain)
        delete m_terrain;
    m_terrain = new Engine::Terrain(hm, scene, scene->getShaderPrograms());
    scene->add(m_terrain);
    
    runEntityGenerator();
}

void    Generator::runEntityGenerator()
{
    //TODO call element generation

        //core
        //scenecourante
    //parcours les genentity pour faire les addobject, addlight etc...

//   m_engine->addModel(element->filename());
    
    std::for_each(zoneDatas().begin(), zoneDatas().end(), [&](ZoneData* zone){//TODO change to activeZoneDatas
        std::for_each(zone->elements().begin(), zone->elements().end(), [&](ElementData* element){
           Category::getRoot() << Priority::INFO << "Create entity from element : " << element->name;
           
            //TODO don't call addModel here, just create the Entity and Node instead
//            Engine::Scene   *scene = m_engine->scenes().front();
//            if (!scene)
//            {
//                Category::getRoot() << Priority::WARN << "No scene to add element";
//            }
//            else
//            {
           m_engine->addModel(element->filename());
//                scene->
                        
//            }
        });
    });

    //TODO add everything to the scene
}

GenerationStep  *Generator::stepFromName(const std::string &namee)
{
    for (const auto &s: m_steps)
        if (s->name() == namee)
            return s;
    return (nullptr);
}



















//TODO degueulasse et fonctionne pas
//const std::vector<GenData::ZoneData *>  &Generator::activeZoneDatas()
//{
//    m_activeZoneDatas.clear();
//
//    std::copy_if(m_zoneDatas.begin(), m_zoneDatas.end(), m_activeZoneDatas.begin(),
//            [](GenData::ZoneData *z){
//        return (z->active.value());
//    });
//
//    return m_activeZoneDatas;
//}

}
