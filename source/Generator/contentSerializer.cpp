#include <algorithm>
#include <log4cpp/Category.hh>

#include "Generator/contentSerializer.hpp"

#include "Generator/data/sceneData.hpp"
//#include "Generator/content/sceneContent.hpp"
#include "Generator/content/elementContent.hpp"

#include "Engine/Core.hpp"
#include "Engine/Core/SceneGraphNode.hpp"

using namespace log4cpp;

namespace gen
{

ContentSerializer::ContentSerializer(Engine::Core *engine)
: _contents(), _engine(engine)
{
    
}

ContentSerializer::~ContentSerializer()
{
    
}

void ContentSerializer::launch(GenContent::SceneContent const& contents)
{
    _contents = contents;
    
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
    std::for_each(_contents.elements().begin(), _contents.elements().end(), [&](GenContent::ElementContent* element){
       Category::getRoot() << Priority::INFO << "Add node for content : " << element->name;

//           GenContent::ElementContent * content = new GenContent::ElementContent(element->name, element->filename);

        Engine::SceneGraphNode  * node = _engine->loadModel(element->filename);
        node->setTransform(element->getTransform());
    });
    
    _engine->setFramebufferActivation(_contents.framebuffer);
    float sky = static_cast<float>(_contents.exploHour) / 24.0f;
    _engine->setSkyColor(glm::vec4(sky, sky, sky, 1.0f));
}

}


