
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
            sceneGraph(this),
            materials(),
            animations(),
            meshes(),
            textures()
        {
            // nothing to do.
        }

        Scene::Scene(const AssimpScene &assimpScene) :
            sceneGraph(assimpScene, this),
            materials(assimpScene->getMaterials()),
            animations(assimpScene->getAnimations()),
            meshes(assimpScene->getMeshes()),
            textures(assimpScene->getTextures())
        {

        }

        Scene::Scene(const Scene &other) :
            sceneGraph(other.sceneGraph),
            materials(other.materials),
            animations(other.animations),
            meshes(other.meshes),
            textures(other.textures)
        {
            // nothing to do.
        }

        Scene::Scene(Scene &&other) :
            sceneGraph(std::move(other.sceneGraph)),
            materials(std::move(other.materials)),
            animations(std::move(other.animations)),
            meshes(std::move(other.meshes)),
            textures(std::move(other.textures))
        {

        }

        Scene::~Scene(void)
        {
            // nothing to do.
        }



        Scene &
        Scene::operator=(const Scene &other)
        {
            this->sceneGraph = other.sceneGraph;
            this->materials = other.materials;
            this->animations = other.animations;
            this->meshes = other.meshes;
            this->textures = other.textures;
            return *this;
        }

        Scene &
        Scene::operator=(Scene &&other)
        {
            this->sceneGraph = std::move(other.sceneGraph);
            this->materials = std::move(other.materials);
            this->animations = std::move(other.animations);
            this->meshes = std::move(other.meshes);
            this->textures = std::move(other.textures);
            return *this;
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
