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

    ///
    /// \brief Destructor
    ///
    virtual ~GameObject(void);

public:
    ///
    /// \brief This function is used to draw the gameobject on the screen
    /// \param projection the projection matrix
    /// \param view the view matrix
    ///
    virtual void    Draw(const glm::mat4 &projection, const glm::mat4 &view) = 0;

    ///
    /// \brief This function is used to update the gameobject in the scene.
    ///
    virtual void    Update() = 0;

public:
    ///
    /// \brief Get the transform of the gameobject.
    /// \return The gameobject transform
    ///
    const Transform &GetTransform(void) const
    {
        return this->transform;
    }

    ///
    /// \brief Get the renderer of the gameobject
    /// \return The renderer of the gameobject
    ///
    const Renderer  *GetRenderer(void) const
    {
        return this->renderer;
    }

    ///
    /// \brief Get the material of the gameobject
    /// \return The material of the gameobject
    ///
    const Material  &GetMaterial(void) const
    {
        return this->material;
    }

protected:
    ///
    /// \brief The transform is used to store the position, scale, rotation of the gameobject
    ///
    Transform   transform;

    ///
    /// \brief The material is used to store the texture, shader, color... of the gameobject.
    ///
    Material    material;

    /// \brief The mesh is used to store the UVs, Vertex of the gameobject.
    Mesh        mesh;

    ///
    /// \brief The renderer is the object that will used the material, the mesh
    /// and the MVP matrix to display the gameobject.
    ///
    Renderer    *renderer;
};

#endif /* __GAMEOBJECT_HPP__ */
