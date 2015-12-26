#include    <glm/glm.hpp>
#include    <algorithm>
#include    <log4cpp/Category.hh>

#include    "Scene.hpp"
#include    "AssimpScene.hpp"

using namespace     log4cpp;

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
            sceneGraph(this)
        {
            // nothing to do.
        }

        Scene::Scene(const AssimpScene &s) :
            materials(s.getMaterials(), s.getMaterialsNumber()),
            animations(s.getAnimations(), s.getAnimationsNumber()),
            meshes(s.getMeshes(), s.getMeshesNumber()),
            textures(s.getTextures(), s.getTexturesNumber()),
            sceneGraph(s, this)
        {
            // nothing to do.
        }

        Scene::~Scene(void)
        {
            // nothing to do.
        }



        void    Scene::update(void)
        {
            Category    &root = Category::getRoot();
            root << Priority::DEBUG << "Scene update()";
            this->sceneGraph.update();
        }

        void    Scene::draw(void)
        {
            Category    &root = Category::getRoot();
            root << Priority::DEBUG << "Scene draw()";
            //this->renderGraph.draw();
        }



        Material *
        Scene::getMaterial(unsigned int id) const
        {
            return this->materials.get(id);
        }

        Animation *
        Scene::getAnimation(unsigned int id) const
        {
            return this->animations.get(id);
        }

        Mesh *
        Scene::getMesh(unsigned int id) const
        {
            return this->meshes.get(id);
        }

        Texture *
        Scene::getTexture(unsigned int id) const
        {
            return this->textures.get(id);
        }

    }
}
