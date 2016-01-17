///
/// \file Scene.cpp
///
/// \author Martin-Pierrat Louis (mart_p)
///
/// \date Sat, 16 Jan 2016 20:50:48
///
/// \version 1.0.2
///

#include    <glm/glm.hpp>
#include    <algorithm>
#include    <log4cpp/Category.hh>

#include    <Engine/Scene.hpp>
#include    <Engine/AssimpScene.hpp>

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
            this->scenegraph.update();
        }

        void    Scene::render(void)
        {
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
