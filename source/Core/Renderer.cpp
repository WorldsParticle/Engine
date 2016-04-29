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

#include    <GL/glew.h>
#include    <log4cpp/Category.hh>

#include    "Engine/Core/Renderer.hpp"
#include    "Engine/Core/Object.hpp"
#include    "Engine/Core/Camera.hpp"
#include    "Engine/Core/Light.hpp"
#include    "Engine/Core/Terrain.hpp"
#include    "Engine/Core/Transform.hpp"
#include    "Engine/Core/Mesh.hpp"
#include    "Engine/Nuages/Nuages.hpp"

using namespace     log4cpp;

namespace   Engine
{
    Renderer::Renderer(Scene *scene) :
        m_scene(scene),
        m_objects(),
        m_cameras(),
        m_lights(),
		m_terrains()
    {

    }

    Renderer::Renderer(const Renderer &other) :
        m_scene(other.m_scene),
        m_objects(),
        m_cameras(),
        m_lights(),
		m_terrains()
	{

    }

    Renderer::Renderer(Renderer &&other) noexcept :
        m_scene(std::move(other.m_scene)),
        m_objects(),
        m_cameras(),
        m_lights(),
		m_terrains()
	{

    }

    Renderer::~Renderer(void) noexcept
    {

    }



    Renderer &
    Renderer::operator=(const Renderer &other)
    {
        this->m_scene = other.m_scene;
        return *this;
    }

    Renderer &
    Renderer::operator=(Renderer &&other) noexcept
    {
        this->m_scene = std::move(other.m_scene);
        return *this;
    }



    void
    Renderer::add(Object *object)
    {
        //Category &root = Category::getRoot();

        //root << Priority::DEBUG << "Renderer - add object()" << object->getName();
        this->m_objects.push_back(object);
    }

    void
    Renderer::add(Camera *camera)
    {
        //Category &root = Category::getRoot();

        //root << Priority::DEBUG << "Renderer - add camera()" << camera->getName();
        this->m_cameras.push_back(camera);
    }

	void
		Renderer::add(Light *light)
	{
		//Category &root = Category::getRoot();

		//root << Priority::DEBUG << "Renderer - add light() : " << light->getName();
		this->m_lights.push_back(light);
	}

	void
		Renderer::add(Terrain *terrain)
	{
		//Category &root = Category::getRoot();

		//root << Priority::DEBUG << "Renderer - add light() : " << light->getName();
		this->m_terrains.push_back(terrain);
	}


    void
        Renderer::add(Nuages *nuages)
    {
        //Category &root = Category::getRoot();

        //root << Priority::DEBUG << "Renderer - add light() : " << light->getName();
        this->m_nuages.push_back(nuages);
    }



    void
    Renderer::render(void)
    {
        glEnable(GL_DEPTH_TEST);
        for (Camera *camera : this->m_cameras)
        {
            const glm::mat4 &projection = camera->getProjection();
            const glm::mat4 &view = camera->getView();

            glClearColor(155.0f / 255.0f , 155.0f / 255.0f, 155.0f / 255.0f, 1.0);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            const glm::ivec2 &size = camera->size();
            glViewport(0, 0, size.x, size.y);

            for (Object *object : this->m_objects)
            {
                const glm::mat4 &model = object->getTransform().getMatrix();
                const std::list<Mesh *>     &meshes = object->getMeshes();
                for (Mesh *part : meshes)
                {
                    part->draw(model, view, projection);
                }
            }
            for (Terrain *terrain : this->m_terrains)
            {
                const glm::mat4 &model = terrain->getTransform().getMatrix();
                terrain->mesh()->draw(model, view, projection);
            }
            for (Nuages *nuages : this->m_nuages)
            {
                const glm::mat4 &model = nuages->getTransform().getMatrix();
                nuages->mesh()->draw(model, view, projection);
            }
        }
        this->m_cameras.clear();
        this->m_objects.clear();
		this->m_lights.clear();
		this->m_terrains.clear();
        this->m_nuages.clear();
    }
}
//
//        std::vector<float> const &getVertex() {
//            return _heightmap->getPoints();
//        }
//        std::vector<int> const &getIndices() {
//            return _heightmap->getIndices();
//        }
//        std::vector<float> const &getNormals() {
//            return _heightmap->getNormals();
//        }
//
