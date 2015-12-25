
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

        Scene::Scene(const aiScene *assimpScene, const std::map<std::string, Entity *> &entities) :
            sceneGraph(assimpScene->mRootNode, entities, this),
            materials(assimpScene->mMaterials, assimpScene->mNumMaterials),
            animations(assimpScene->mAnimations, assimpScene->mNumAnimations),
            meshes(assimpScene->mMeshes, assimpScene->mNumMeshes),
            textures(assimpScene->mTextures, assimpScene->mNumTextures)
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
