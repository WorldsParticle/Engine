#include    <log4cpp/Category.hh>
#include    <glm/gtc/matrix_transform.hpp>

#include    "PerspectiveCamera.hpp"
#include    "Scene.hpp"

using namespace     log4cpp;

namespace   WorldParticles
{
    namespace   Engine
    {
        PerspectiveCamera::PerspectiveCamera(SceneGraphNode *node) :
            Camera(node),
            projection(glm::mat4(1)),
            view(glm::mat4(1))
        {
            this->projection = glm::perspective(this->fov, this->aspect,
                    this->clippingPlane.near, this->clippingPlane.far);
            this->view = glm::lookAt(this->position, this->lookat, this->up);

            this->scene->add(this);

        }

        PerspectiveCamera::PerspectiveCamera(const aiCamera *assimpCamera,
                SceneGraphNode *node) :
            Camera(assimpCamera, node),
            projection(glm::mat4(1)),
            view(glm::mat4(1))
        {
            this->projection = glm::perspective(this->fov, this->aspect,
                    this->clippingPlane.near, this->clippingPlane.far);
            this->view = glm::lookAt(this->position, this->lookat, this->up);

            this->scene->add(this);
        }

        PerspectiveCamera::~PerspectiveCamera(void)
        {
            // nothing to do.
        }



        PerspectiveCamera *
        PerspectiveCamera::clone(void) const
        {
            return new PerspectiveCamera(*this);
        }

        void
        PerspectiveCamera::update(void)
        {
            Category    &root = Category::getRoot();

            root << Priority::DEBUG << "PerspectiveCamera - update()";
            // nothing to do.
        }
    }
}
