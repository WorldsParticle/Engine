#include    "Camera.hpp"

#include    <glm/gtc/matrix_transform.hpp>

/// TODO C'est totalement pas cohérent de devoir inclure le GLWindow pour faire
/// de l'opengl.
#include    "glwindow.h"

namespace WorldParticles
{
    namespace Engine
    {

        Camera::Camera(SceneGraphNode *node) :
            Entity(node),
            name(""),
            clippingPlane{0.0f, 0.0f},
            aspect(0.0f),
            fov(0.0f),
            up(glm::vec3(0.0f)),
            lookat(glm::vec3(0.0f)),
            position(glm::vec3(0.0f))
        {
            // nothing to do.
        }

        Camera::Camera(const aiCamera *assimpCamera, SceneGraphNode *node) :
            Entity(node),
            name(assimpCamera->mName.C_Str()),
            clippingPlane{assimpCamera->mClipPlaneNear, assimpCamera->mClipPlaneFar},
            aspect(assimpCamera->mAspect),
            fov(assimpCamera->mHorizontalFOV * 2.0f),
        {
            auto convert = [&](const aiVector3D &v) {return glm::vec3(v.x, v.y, v.z);};
            this->up = convert(assimpCamera->mUp);
            this->lookat = convert(assimpCamera->mLookAt);
            this->position = convert(assimpCamera->mPosition);
        }

        Camera::Camera(const Camera &other) :
            Entity(other),
            name(other.name),
            clippingPlane(other.clippingPlane),
            aspect(other.aspect),
            fov(other.fov),
            up(other.up),
            lookat(other.lookat),
            position(other.position)
        {
            // nothing to do.
        }

        Camera::Camera(Camera &&other) :
            Entity(std::move(other)),
            name(std::move(other.name)),
            clippingPlane(std::move(other.clippingPlane)),
            aspect(std::move(other.aspect)),
            fov(std::move(other.fov)),
            up(std::move(other.up)),
            lookat(std::move(other.lookat)),
            position(std::move(other.position))
        {
            // nothing to do.
        }

        Camera::~Camera(void)
        {
            // nothing to do.
        }



        Camera &
        Camera::operator=(const Camera &other)
        {
            this->name = other.name;
            this->clippingPlane = other.clippingPlane;
            this->aspect = other.aspect;
            this->fov = other.fov;
            this->up = other.up;
            this->lookat = other.lookat;
            this->position = other.position;
            return *this;
        }

        Camera &
        Camera::operator=(Camera &&other)
        {
            this->name = std::move(other.name);
            this->clippingPlane = std::move(other.clippingPlane);
            this->aspect = std::move(other.aspect);
            this->fov = std::move(other.fov);
            this->up = std::move(other.up);
            this->lookat = std::move(other.lookat);
            this->position = std::move(other.position);
            return *this;
        }

    }
}
