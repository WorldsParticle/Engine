///
/// \file SpatialGraph.cpp
///
/// \author Martin-Pierrat Louis (mart_p)
///
/// \date Sat, 16 Jan 2016 20:55:32
///
/// \version 1.0.2
///

#include    <log4cpp/Category.hh>

#include    <Engine/SpatialGraph.hpp>
#include    <Engine/Renderer.hpp>
#include    <Engine/Camera.hpp>
#include    <Engine/Object.hpp>
#include    <Engine/Light.hpp>

using namespace     log4cpp;

namespace   WorldParticles
{
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
}
