#include <algorithm>
#include <log4cpp/Category.hh>

#include "Generator/contentGenerator.hpp"

#include "Generator/data/sceneData.hpp"
#include "Generator/content/sceneContent.hpp"
#include "Generator/content/elementContent.hpp"

using namespace log4cpp;
using GenData::ZoneData;
using GenData::ElementData;

namespace gen
{

ContentGenerator::ContentGenerator()
: _map(nullptr), _datas(),
_contents()
{
    
}

ContentGenerator::~ContentGenerator()
{
    
}

void ContentGenerator::launch(map::MapGraph *map, GenData::SceneData const& datas)
{
    _map = map;
    _datas = datas;
    

    Engine::Transform elemPos;
//    elemPos.translate(glm::vec3(rand() % 50, rand() % 50, 2));
    elemPos.translate(glm::vec3(0.0f, 0.0f, 2.0f));//Tmp, to be sure elements are above the floor
    //elemPos.scale(glm::vec3(0.5, 0.5, 0.5));
    
    int i = 0;
    std::for_each(_datas.zones().begin(), _datas.zones().end(), [&](ZoneData* zone){//TODO change to activeZoneDatas
        std::for_each(zone->elements().begin(), zone->elements().end(), [&](ElementData* element){
           Category::getRoot() << Priority::INFO << "Create content from data : " << element->name;
           
           GenContent::ElementContent * content = new GenContent::ElementContent(element->name, element->filename());
           
//            Engine::SceneGraphNode  * node = _engine->loadModel(element->filename());

            elemPos.translate(glm::vec3(rand() % (10 * i), rand() % (10 * i), 0.0f));
            content->setTransform(elemPos);

            _contents.elements().push_back(content);
        });
        i++;
    });
}

}