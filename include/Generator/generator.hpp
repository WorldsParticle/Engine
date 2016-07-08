#ifndef GENERATOR_MARIE_H
#define GENERATOR_MARIE_H

#include "steps/generationstep.hpp"
//#include "data/zoneData.hpp"
#include "data/sceneData.hpp"
#include <map>
#include <algorithm>

namespace map
{
class MapGraph;
}

namespace Engine
{
class Core;
class Terrain;
class Object;
class Light;
}

namespace gen
{

///
/// \brief This class run a bunch of step whose fill the mapgraph
/// for now it will juste launch one by one the generation steps which have been assigned (actually in a static way)
///
class ENGINE_EXPORTS Generator
{
public:
    Generator(Engine::Core *engine);
    ~Generator();

    void    run(map::MapGraph *map);//rename in launchMapSteps
    void    launchContentsGeneration();
    void    serializeContents();

    void    addTerrain(map::HeightMap &);

public:
    inline const std::vector<GenerationStep *>  &steps()
    { return m_steps; }

    GenerationStep  *stepFromName(const std::string &namee);

    inline const std::vector<GenData::ZoneData *>  &zoneDatas()
    { return m_datas.zones(); }

protected:
    std::vector<GenerationStep *>       m_steps;
    GenData::SceneData                  m_datas;
//    std::vector<GenData::ZoneData *>    m_zoneDatas;
    
protected:
    Engine::Terrain *                   m_terrain;//TODO multiple terrain ?
    std::vector<Engine::Object *>       m_objects;
    std::vector<Engine::Light *>        m_lights;
    //m_particles;
    //m_skybox;
    
private:
//    std::vector<GenData::ZoneData *>    m_activeZoneDatas;    
    Engine::Core *m_engine;
};

}

#endif // GENERATOR_H
