
#include    "SpatialGraph.hpp"

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

        }

        void
        SpatialGraph::add(Light *light)
        {

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
