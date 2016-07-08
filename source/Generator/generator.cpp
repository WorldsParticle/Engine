#include <algorithm>
#include <log4cpp/Category.hh>

#include "Generator/generator.hpp"

#include "Engine/Core.hpp"
#include "Engine/Core/Scene.hpp"
#include "Engine/Core/Terrain.hpp"
#include "Engine/Core/Object.hpp"
#include "Engine/Core/Light.hpp"
#include "Engine/Core/SceneGraphNode.hpp"

#include "Generator/data/elementData.hpp"

#include "Generator/map/map.hpp"
#include "Generator/steps/zoningstep.hpp"
#include "Generator/steps/shaperstep.hpp"
#include "Generator/steps/elevatorstep.hpp"
#include "Generator/steps/riverorstep.hpp"
#include "Generator/steps/moistorstep.hpp"
#include "Generator/steps/biomizatorstep.hpp"
#include "Generator/steps/heightmapingstep.hpp"

#include "Generator/contentGenerator.hpp"
#include "Generator/contentSerializer.hpp"

using namespace log4cpp;
using GenData::ZoneData;
using GenData::ElementData;

namespace gen
{

Generator::Generator(Engine::Core *engine)
    :   m_steps(),
        m_contentGenerator(),
        m_contentSerializer(engine),
        m_map(nullptr),
        m_datas(),
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
}

Generator::~Generator()
{
    m_steps.clear();

    if (m_terrain)
        delete m_terrain;
    m_objects.clear();//TODO check if not already cleared from the scene
    m_lights.clear();
}

void    Generator::run(map::MapGraph *map)
{
    m_map = map;
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
    
    generateContents();//tmp call
}

void    Generator::generateContents()
{
    m_contentGenerator.launch(nullptr, &m_datas);
    
//    Engine::SceneGraphNode  * node = m_engine->loadModel("../Engine/resources/models/tree.DAE");
//    std::cout << "Successfully loaded node " << node << std::endl;
//    
//    if (node)
//    {
//        Engine::Scene   *scene = m_engine->scenes().front();
//        Engine::SceneGraphNode  * duplicatedNode = new Engine::SceneGraphNode(*node);
//        scene->add(dynamic_cast<Engine::Object *>(duplicatedNode->getEntity()));
//        std::cout << "Successfully duplicated node" << std::endl;
//    }
//    
    Engine::Transform elemPos;
//    elemPos.translate(glm::vec3(rand() % 50, rand() % 50, 2));
    elemPos.translate(glm::vec3(0.0f, 0.0f, 2.0f));//Tmp, to be sure elements are above the floor
    //elemPos.scale(glm::vec3(0.5, 0.5, 0.5));
    
    std::for_each(m_datas.zones().begin(), m_datas.zones().end(), [&](ZoneData* zone){//TODO change to activeZoneDatas
        std::for_each(zone->elements().begin(), zone->elements().end(), [&](ElementData* element){
           Category::getRoot() << Priority::INFO << "Create entity from element : " << element->name;
           
            Engine::SceneGraphNode  * node = m_engine->loadModel(element->filename());

            elemPos.translate(glm::vec3(rand() % 50, 10.0f, 0.0f));
            node->setTransform(elemPos);
        });
    });
}

void    Generator::serializeContents()
{
    m_contentSerializer.launch(m_contentGenerator.contents());
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
