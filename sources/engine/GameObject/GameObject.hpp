#ifndef     __GAMEOBJECT_HPP__
# define    __GAMEOBJECT_HPP__

#include    "worldparticles.hpp"

#include    "glm/glm.hpp"

#include    "Transform.hpp"
#include    "Renderer.hpp"
#include    "Mesh.hpp"

class       GameObject
{
public:
    ///
    /// \brief GameObject
    /// \param position
    /// \param rotation
    /// \param scale
    ///
    GameObject(const glm::vec3 &position = glm::vec3(0.0),
               const glm::vec3 &rotation = glm::vec3(0.0),
               const glm::vec3 &scale = glm::vec3(1.0));

public:
    virtual void    Draw(const glm::mat4 &projection, const glm::mat4 &view) = 0;
    virtual void    Update() = 0;

public:
    const Transform &GetTransform(void) const
    {
        return this->transform;
    }

    const Renderer  *GetRenderer(void) const
    {
        return this->renderer;
    }

    const Material  &GetMaterial(void) const
    {
        return this->material;
    }

    const Mesh      &GetMesh(void) const
    {

    }

protected:
    Transform   transform;
    Material    material;
    Mesh        mesh;
    Renderer    *renderer;
};

#endif /* __GAMEOBJECT_HPP__ */
