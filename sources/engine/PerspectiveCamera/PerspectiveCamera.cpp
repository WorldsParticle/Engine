#include    <log4cpp/Category.hh>
#define GLM_SWIZZLE
#define     GLM_SWIZZLE_XYZW
#include    <glm/glm.hpp>
#include    <glm/gtc/matrix_transform.hpp>

#include    "Transform.hpp"
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
            Category    &root = Category::getRoot();

            const Transform &transform = this->getTransform();
            glm::vec4 realPosition = transform.getMatrix() * glm::vec4(this->position, 1.0);

            root << Priority::DEBUG << "Camera fov " << this->fov;
            root << Priority::DEBUG << "Camera aspect " << this->aspect;
            root << Priority::DEBUG << "Camera near " << this->clippingPlane.near;
            root << Priority::DEBUG << "Camera far " << this->clippingPlane.far;
            root << Priority::DEBUG << "Camera position " << realPosition.x << " " << realPosition.y << " " << realPosition.z;
            root << Priority::DEBUG << "Camera lookat " << this->lookat.x << " " << this->lookat.y << " " << this->lookat.z;
            root << Priority::DEBUG << "Camera up " << this->up.x << " " << this->up.y << " " << this->up.z;

            this->projection = glm::perspective(this->fov, this->aspect,
                    this->clippingPlane.near, this->clippingPlane.far);
            this->view = glm::lookAt(realPosition.xyz(), this->lookat, this->up);

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
            // nothing to do.
        }



        const glm::mat4 &
        PerspectiveCamera::getProjection(void) const
        {
             return this->projection;
        }

        const glm::mat4 &
        PerspectiveCamera::getView(void) const
        {
             return this->view;
        }
    }
}
