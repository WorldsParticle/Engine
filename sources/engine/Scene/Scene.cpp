
#include    <glm/glm.hpp>
#include    <algorithm>

#include    "Scene.hpp"
#include    "Cube.hpp"

namespace WorldParticles
{
    namespace Engine
    {

        /// TODO : delete push object
        Scene::Scene(void) :
            materials(),
            animations(),
            meshes(),
            textures(),
            sceneGraph()
        {
            // nothing to do.
        }

        Scene::Scene(const Scene &other) :
            materials(),
            animations(),
            meshes(),
            textures(),
            sceneGraph(other.sceneGraph)
        {
            this->materials.reserve(other.materials.size());
            for (Material *material : other.materials)
            {
                this->materials.push_back(new Material(*material));
            }
            this->animations.reserve(other.animations.size());
            for (Animation *animation : other.animations)
            {
                this->animations.push_back(new Animation(*animation));
            }
            this->meshes.reserve(other.meshes.size());
            for (Mesh *mesh : other.meshes)
            {
                this->meshes.push_back(new Mesh(*mesh));
            }
            this->textures.reserve(other.textures.size());
            for (Texture *texture : other.textures)
            {
                 this->textures.push_back(new Texture(*texture));
            }
        }

        Scene::Scene(Scene &&other) :
            materials(std::move(other.materials)),
            animations(std::move(other.animations)),
            meshes(std::move(other.meshes)),
            textures(std::move(other.textures)),
            sceneGraph(std::move(other.sceneGraph))
        {

        }

        Scene::~Scene(void)
        {
            for (Material *material : this->materials)
            {
                delete material;
            }
            for (Animation *animation : this->animations)
            {
                delete animation;
            }
            for (Mesh *mesh : this->meshes)
            {
                delete mesh;
            }
            for (Texture *texture : this->textures)
            {
                delete texture;
            }
        }



        void    Scene::update(void)
        {
            this->sceneGraph.update();
        }

        void    Scene::draw(void)
        {
            //this->renderGraph.draw();
        }

    }
}
