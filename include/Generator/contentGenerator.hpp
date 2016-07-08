/* 
 * File:   contentGenerator.hpp
 * Author: marie
 *
 * Created on 8 juillet 2016, 23:00
 */

#ifndef CONTENTGENERATOR_HPP
#define CONTENTGENERATOR_HPP

#include "Engine/Configuration.hpp"
//#include "data/sceneData.hpp"

namespace map
{
class MapGraph;
}

namespace GenData
{
class SceneData;
}

namespace GenContent
{
class SceneContent;
}

namespace gen
{
///
/// \brief This class will do the procedural generation of environment contents
/// using the datas given by the generator via the GenData::SceneData class
/// as its parameters
///
class ENGINE_EXPORTS ContentGenerator
{
public:
    ContentGenerator();
    ~ContentGenerator();
    
    void launch(map::MapGraph *map, GenData::SceneData *datas);
    
    inline GenContent::SceneContent  *contents() {
        return _contents;
    }
    
private:
    map::MapGraph       *_map;
    GenData::SceneData  *_datas;
    GenContent::SceneContent  *_contents;
};
}

#endif /* CONTENTGENERATOR_HPP */

