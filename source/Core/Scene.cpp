//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 3 of the License, or
// any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this program; If not, see <http://www.gnu.org/licenses/>.
//
// Copyright (C) 2016 Martin-Pierrat Louis (louismartinpierrat@gmail.com)
//

#include    <glm/glm.hpp>
#include    <algorithm>
#include    <log4cpp/Category.hh>

#include    "Engine/Core/Scene.hpp"
#include    "Engine/Core/AssimpScene.hpp"

using namespace     log4cpp;

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
