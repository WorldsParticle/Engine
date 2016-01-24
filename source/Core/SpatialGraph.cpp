///
/// \file SpatialGraph.cpp
///
/// \author Martin-Pierrat Louis (mart_p)
///
/// \date Sun, 17 Jan 2016 07:50:57
///
/// \version 1.0.5
///

#include    <log4cpp/Category.hh>

#include    "Engine/Core/SpatialGraph.hpp"
#include    "Engine/Core/Renderer.hpp"
#include    "Engine/Core/Camera.hpp"
#include    "Engine/Core/Object.hpp"
#include    "Engine/Core/Light.hpp"

using namespace     log4cpp;

namespace   Engine
{
    SpatialGraph::SpatialGraph(Renderer *renderer, Scene *scene) :
        scene(scene),
        renderer(renderer)
    {

    }

    SpatialGraph::~SpatialGraph(void)
    {

    }



    void
    SpatialGraph::add(Object *object)
    {
        this->objects.push_back(object);
    }

    void
    SpatialGraph::add(Light *light)
    {
        this->lights.push_back(light);
    }

    void
    SpatialGraph::add(Camera *camera)
    {
        this->cameras.push_back(camera);
    }



    void
    SpatialGraph::cull(void)
    {
        for (Camera *camera : this->cameras)
        {
            this->renderer->add(camera);
        }
        for (Object *object : this->objects)
        {
            this->renderer->add(object);
        }
        for (Light *light : this->lights)
        {
             this->renderer->add(light);
        }
    }

}
