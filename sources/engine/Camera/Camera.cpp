#include    <glm/gtc/matrix_transform.hpp>

#include    "Camera.hpp"

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
            up(glm::vec3(0.0f)),
            lookat(glm::vec3(0.0f)),
            position(glm::vec3(0.0f))
        {
            auto convert = [&](const aiVector3D &v) {return glm::vec3(v.x, v.y, v.z);};
            this->up = convert(assimpCamera->mUp);
            this->lookat = convert(assimpCamera->mLookAt);
            this->position = convert(assimpCamera->mPosition);
        }

        Camera::~Camera(void)
        {
            // nothing to do.
        }



        const std::string &
        Camera::getName(void) const
        {
             return this->name;
        }

    }
}
