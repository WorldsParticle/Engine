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

#include    <log4cpp/Category.hh>

#include    "Engine/Core/SpatialGraph.hpp"
#include    "Engine/Core/Renderer.hpp"
#include    "Engine/Core/Camera.hpp"
#include    "Engine/Core/Object.hpp"
#include    "Engine/Core/Light.hpp"
#include    "Engine/Core/Terrain.hpp"

using namespace     log4cpp;

namespace   Engine
{
    SpatialGraph::SpatialGraph(Renderer &renderer, Scene *scene) :
        m_scene(scene),
        m_renderer(renderer),
        m_cameras(),
        m_objects(),
        m_lights(),
        m_terrains()
    {

    }

    SpatialGraph::~SpatialGraph(void)
    {

    }



    void
    SpatialGraph::add(Object *object)
    {
        this->m_objects.push_back(object);
    }

    void
    SpatialGraph::add(Light *light)
    {
        this->m_lights.push_back(light);
    }

	void
		SpatialGraph::add(Camera *camera)
	{
		this->m_cameras.push_back(camera);
	}

	void
		SpatialGraph::add(Terrain *terrain)
	{
		this->m_terrains.push_back(terrain);
	}

    void
    SpatialGraph::cull(void)
    {
        for (Camera *camera : this->m_cameras)
        {
            this->m_renderer.add(camera);
        }
        for (Object *object : this->m_objects)
        {
            this->m_renderer.add(object);
        }
		for (Light *light : this->m_lights)
		{
			this->m_renderer.add(light);
		}
		for (Terrain *terrain : this->m_terrains)
		{
			this->m_renderer.add(terrain);
		}
	}

}

