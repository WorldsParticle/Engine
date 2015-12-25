#include    "PerspectiveCamera.hpp"

namespace   WorldParticles
{
    namespace   Engine
    {
        PerspectiveCamera::PerspectiveCamera(void)
        {
            this->projection = glm::perspective(this->fov, this->aspect,
                    this->clippingPlane.near, this->clippingPlane.far);
            this->view = glm::lookat(this->position, this->lookat, this->up);
        }

        PerspectiveCamera::PerspectiveCamera(const PerspectiveCamera &other) :
            projection(other.projection),
            view(other.view)
        {
            this->projection = glm::perspective(this->fov, this->aspect,
                    this->clippingPlane.near, this->clippingPlane.far);
            this->view = glm::lookat(this->position, this->lookat, this->up);
            // nothing to do.
        }

        PerspectiveCamera::PerspectiveCamera(PerspectiveCamera &&other) :
            projection(std::move(other.projection)),
            view(std::move(other.view))
        {
            // nothing to do.
        }

        PerspectiveCamera::~PerspectiveCamera(void)
        {
            // nothing to do.
        }



        PerspectiveCamera &
        PerspectiveCamera::operator=(const PerspectiveCamera &other)
        {
            this->projection = other.projection;
            this->view = other.view;
            return *this;
        }

        PerspectiveCamera &
        PerspectiveCamera::operator=(PerspectiveOperator &&other)
        {
            this->projection = std::move(other.projection);
            this->view = std::move(other.view);
            return *this;
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
    }
}
