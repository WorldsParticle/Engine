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
        m_event_register(),
        m_shaderprograms(),
        m_textures(),
        m_materials(),
        m_animations(),
        m_meshes(),
        m_renderer(this),
        m_spatialgraph(this->m_renderer, this),
        m_scenegraph(this)
    {
        // nothing to do.
    }

    Scene::Scene(const AssimpScene &s, const std::string &modelPath) :
        m_event_register(),
        m_shaderprograms(),
        m_textures(s),
        m_materials(this->m_shaderprograms, s.getMaterials(), s.getMaterialsNumber(), m_textures),
        m_animations(s.getAnimations(), s.getAnimationsNumber()),
        m_meshes(this->m_materials, s.getMeshes(), s.getMeshesNumber()),
        m_renderer(this),
        m_spatialgraph(this->m_renderer, this),
        m_scenegraph(s, this)
    {
        // nothing to do.
    }

    Scene::~Scene(void)
    {
        // nothing to do.
    }



    void
    Scene::update(void)
    {
        this->m_scenegraph.update();
    }

    void
    Scene::render(void)
    {
        this->m_spatialgraph.cull();
        this->m_renderer.render();
    }

    void
    Scene::push_event(const Event::Event &event)
    {
        this->m_event_register.push_event(event);
    }



    Material *
    Scene::getMaterial(unsigned int id) const
    {
        return this->m_materials.get(id);
    }

    Animation *
    Scene::getAnimation(const std::string &name) const
    {
        return this->m_animations.get(name);
    }

    Mesh *
    Scene::getMesh(unsigned int id) const
    {
        return this->m_meshes.get(id);
    }

    Texture *
    Scene::getTexture(const std::string &name) const
    {
        return this->m_textures.get(name);
    }



    void
    Scene::add(Object *object)
    {
        this->m_spatialgraph.add(object);
    }

    void
    Scene::add(Light *light)
    {
        this->m_spatialgraph.add(light);
    }

    void
    Scene::add(Camera *camera)
    {
        this->m_spatialgraph.add(camera);
    }



    void
    Scene::register_callback(const Event::Type &event_type,
            const std::function<void(const Event::Event &)> &callback)
    {
         this->m_event_register.register_callback(event_type, callback);
    }

}
