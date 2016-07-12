#include <algorithm>
#include <math.h>
#include <log4cpp/Category.hh>

#include "Generator/contentGenerator.hpp"

#include "Generator/data/sceneData.hpp"
#include "Generator/content/sceneContent.hpp"
#include "Generator/content/elementContent.hpp"

using namespace log4cpp;
using GenData::ZoneData;
using GenData::ElementData;

#define GEN_ELEM_POS(i, size, elemCount) (static_cast<float>(i) * static_cast<float>(size) / static_cast<float>(elemCount))// + (rand() % (size / elemCount)))

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
    
//    Engine::Transform contentPos;
//    contentPos.translate(glm::vec3(0.0f, 0.0f, 2.0f));//Tmp, to be sure elements are above the floor
//    contentPos.scale(glm::vec3(0.1f, 0.1f, 0.1f));//To fit big trees
    
//    std::for_each(_datas.zones().begin(), _datas.zones().end(), [&](ZoneData* zone){//TODO change to activeZoneDatas
        ZoneData * zone = _datas.zones().at(0);
        int totalElementInZone = 50;//TODO put this in ZoneData
        int width = static_cast<int>(_map->xMax());
        int height = static_cast<int>(_map->yMax());//TODO put this in ZoneData
        
//        std::for_each(zone->elements().begin(), zone->elements().end(), [&](ElementData* element){
            ElementData* element = zone->elements().at(0);

            Category::getRoot() << Priority::INFO << "Create content from data : " << element->name;
            int elemCount = element->density.value() * totalElementInZone / 100;
            int elemCountSide = static_cast<int>(std::sqrt(elemCount));
            for (int i = 0; i < elemCountSide; i++)
            {
                float x = GEN_ELEM_POS(i, width, elemCountSide);

                for (int j = 0; j < elemCountSide; j++)
                {
                    float y = GEN_ELEM_POS(j, height, elemCountSide);

                    GenContent::ElementContent * content = new GenContent::ElementContent(element->name, element->filename());

                    Engine::Transform contentPos;
                    contentPos.translate(glm::vec3(0.0f, 0.0f, 2.0f));//Tmp, to be sure elements are above the floor
                    contentPos.scale(glm::vec3(0.1f, 0.1f, 0.1f));//To fit big trees

                    contentPos.translate(glm::vec3(x, y, 0.0f));
                    content->setTransform(contentPos);
                    _contents.elements().push_back(content);
                }
            }
//        });
//    });
}

}