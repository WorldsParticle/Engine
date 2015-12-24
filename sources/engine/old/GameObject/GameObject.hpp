#ifndef     __GAMEOBJECT_HPP__
# define    __GAMEOBJECT_HPP__

#include    <glm/glm.hpp>
#include    <memory>

#include    "worldparticles.hpp"
#include    "Transform.hpp"
#include    "IRenderer.hpp"
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
                virtual void    draw(const glm::mat4 &projection, const glm::mat4 &view) = 0;

                ///
                /// \brief This function is used to update the gameobject in the scene.
                ///
                virtual void    update(void) = 0;

            public:
                ///
                /// \brief Get the transform of the gameobject.
                /// \return The gameobject transform
                ///
                const Transform                         &getTransform(void) const;

                ///
                /// \brief Get the renderer of the gameobject
                /// \return The renderer of the gameobject
                ///
                const IRenderer                         *getRenderer(void) const;

                ///
                /// \brief Get the material of the gameobject
                /// \return The material of the gameobject
                ///
                const std::shared_ptr<Material>         &getMaterial(void) const;

                ///
                /// \brief Getter for the Mesh attribute.
                ///
                const std::shared_ptr<Mesh>             &getMesh(void) const;

                ///
                /// \brief Getter for the shader program used to render this gameobject.
                ///
                const std::shared_ptr<ShaderProgram>    &getShaderProgram(void) const;

            public:
                ///
                /// \brief Setter for the transform attribute.
                ///
                void                setTransform(const Transform &transform);

                ///
                /// \brief Setter for the renderer attribute;
                ///
                void                setRenderer(IRenderer *renderer);

                ///
                /// \brief Setter for the material attribute.
                ///
                void                setMaterial(std::shared_ptr<Material> &material);

                ///
                /// \brief Setter for the mesh attrbute.
                ///
                void                setMesh(std::shared_ptr<Mesh> &mesh);

                ///
                /// \brief Setter for the shader program used to render the gameobject.
                ///
                void                setShaderProgram(std::shared_ptr<ShaderProgram> &shaderprogram);

            protected:
                ///
                /// \brief The transform is used to store the position, scale, rotation of the gameobject
                ///
                Transform                       transform;

                ///
                /// \brief The material is used to store the texture, shader, color... of the gameobject.
                ///
                std::shared_ptr<Material>       material;

                ///
                /// \brief The mesh is used to store the UVs, Vertex of the gameobject.
                ///
                std::shared_ptr<Mesh>           mesh;

                ///
                /// \brief The shaderprogram used to draw the gameobject.
                ///
                std::shared_ptr<ShaderProgram>  shaderprogram;

                ///
                /// \brief The renderer is the object that will used the material, the mesh
                /// and the MVP matrix to display the gameobject.
                ///
                IRenderer                       *renderer;
        };
    }
}

#endif /* __GAMEOBJECT_HPP__ */
