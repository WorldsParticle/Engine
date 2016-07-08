
#include "Generator/contentSerializer.hpp"

#include "Generator/data/sceneData.hpp"
#include "Generator/content/sceneContent.hpp"

namespace gen
{

ContentSerializer::ContentSerializer(Engine::Core *engine)
: _contents(nullptr), _engine(engine)
{
    
}

ContentSerializer::~ContentSerializer()
{
    
}

void ContentSerializer::launch(GenContent::SceneContent *contents)
{
    _contents = contents;
    //TODO
}

}


