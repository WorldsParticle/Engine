#include    <log4cpp/Category.hh>

#include    "Renderer.hpp"
#include    "Object.hpp"
#include    "Camera.hpp"
#include    "Light.hpp"

using namespace     log4cpp;

namespace   WorldParticles
{
    namespace   Engine
    {
        Renderer::Renderer(Scene *scene) :
            scene(scene)
        {

        }

        Renderer::Renderer(const Renderer &other) :
            scene(other.scene)
        {

        }

        Renderer::Renderer(Renderer &&other) noexcept :
            scene(std::move(other.scene))
        {

        }

        Renderer::~Renderer(void) noexcept
        {

        }



        Renderer &
        Renderer::operator=(const Renderer &other)
        {
            this->scene = other.scene;
            return *this;
        }

        Renderer &
        Renderer::operator=(Renderer &&other) noexcept
        {
            this->scene = std::move(other.scene);
            return *this;
        }



        void
        Renderer::add(Object *object)
        {
            this->objects.push_back(object);
        }

        void
        Renderer::add(Camera *camera)
        {
            this->cameras.push_back(camera);
        }

        void
        Renderer::add(Light *light)
        {
            this->lights.push_back(light);
        }



        void
        Renderer::render(void)
        {
            Category    &root = Category::getRoot();

            root << Priority::DEBUG << "Renderer - render()";
            for (Camera *camera : this->cameras)
            {
                //camera.getProjection();
                //camera.getView();
                for (Object *object : this->objects)
                {
                    //object->getMatrix();
                    //for (GeometryPart *part : object->geometry)
                    {
                        //bind(part.material);
                        //bind(part.buffers);
                        //glDraw(Triangle);
                    }
                }
            }
            this->cameras.clear();
            this->objects.clear();
            this->lights.clear();
        }
    }
}
