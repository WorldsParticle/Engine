
#include "Generator/contentGenerator.hpp"

#include "Generator/data/sceneData.hpp"
#include "Generator/content/sceneContent.hpp"

namespace gen
{

ContentGenerator::ContentGenerator()
: _map(nullptr), _datas(nullptr),
_contents(new GenContent::SceneContent())
{
    
}

ContentGenerator::~ContentGenerator()
{
    
}

void ContentGenerator::launch(map::MapGraph *map, GenData::SceneData *datas)
{
    _map = map;
    _datas = datas;
    
    //TODO
}

}