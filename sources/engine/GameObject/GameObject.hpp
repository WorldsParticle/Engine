#ifndef     __GAMEOBJECT_HPP__
# define    __GAMEOBJECT_HPP__

#include    <glm/glm.hpp>
#include    <memory>

#include    "worldparticles.hpp"
#include    "Transform.hpp"
#include    "Renderer.hpp"
#include    "Material.hpp"
#include    "Mesh.hpp"

namespace   WorldParticles
{
    namespace   Engine
    {
        ///
        /// \brief This class is used to represent an object in the 3D world. This object must be drawable.
        ///
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
                /// \brief This method should be used to initialise a gameobject.
                ///
                virtual bool    initialise(void) = 0;

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
                    return this->_transform;
                }

                ///
                /// \brief Get the renderer of the gameobject
                /// \return The renderer of the gameobject
                ///
                const Renderer  *GetRenderer(void) const
                {
                    return this->_renderer;
                }

                ///
                /// \brief Get the material of the gameobject
                /// \return The material of the gameobject
                ///
                const Material  &GetMaterial(void) const
                {
                    return this->_material;
                }

            protected:
                ///
                /// \brief The transform is used to store the position, scale, rotation of the gameobject
                ///
                Transform               _transform;

                ///
                /// \brief The material is used to store the texture, shader, color... of the gameobject.
                /// TODO : should be a pointer
                Material                _material;

                ///
                /// \brief The mesh is used to store the UVs, Vertex of the gameobject.
                ///
                std::shared_ptr<Mesh>   _mesh;

                ///
                /// \brief The renderer is the object that will used the material, the mesh
                /// and the MVP matrix to display the gameobject.
                ///
                Renderer                *_renderer;
        };
    }
}

#endif /* __GAMEOBJECT_HPP__ */
