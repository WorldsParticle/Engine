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
            shaderprograms(),
            materials(),
            animations(),
            meshes(),
            textures(),
            renderer(this),
            spatialgraph(&this->renderer, this),
            scenegraph(this)
        {
            // nothing to do.
        }

        Scene::Scene(const AssimpScene &s) :
            shaderprograms(),
            materials(shaderprograms, s.getMaterials(), s.getMaterialsNumber()),
            animations(s.getAnimations(), s.getAnimationsNumber()),
            meshes(materials, s.getMeshes(), s.getMeshesNumber()),
            textures(s.getTextures(), s.getTexturesNumber()),
            renderer(this),
            spatialgraph(&this->renderer, this),
            scenegraph(s, this)
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
            this->scenegraph.update();
        }

        void    Scene::render(void)
        {
            Category    &root = Category::getRoot();
            root << Priority::DEBUG << "Scene render()";
            this->spatialgraph.cull();
            this->renderer.render();
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



        void
        Scene::add(Object *object)
        {
            this->spatialgraph.add(object);
        }

        void
        Scene::add(Light *light)
        {
            this->spatialgraph.add(light);
        }

        void
        Scene::add(Camera *camera)
        {
             this->spatialgraph.add(camera);
        }

    }
}
