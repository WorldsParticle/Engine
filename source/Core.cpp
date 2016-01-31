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
#include    <log4cpp/PropertyConfigurator.hh>

#include    "Engine/Version.hpp"
#include    "Engine/Configuration.hpp"
#include    "Engine/Core.hpp"

using namespace     log4cpp;

namespace   Engine
{

    Core::Core(void) :
        m_scenes(),
        m_importer()
    {

        PropertyConfigurator::configure(RESOURCES_PATH "/log4cpp.conf");
        Category& root = Category::getRoot();
        root << Priority::INFO << "Lancement engine :";
        root << Priority::INFO << "\t version : " PROJECT_VERSION_FULL;

        GLenum err = glewInit();
        if (GLEW_OK != err)
        {
            std::cerr << "Glew Init failure" << std::endl;
        }

        // nothing to do
    }

    Core::Core(const Core &other) :
        m_scenes(),
        m_importer(other.m_importer)
    {
        for (Scene *scene : other.m_scenes)
        {
            this->m_scenes.push_back(new Scene(*scene));
        }
    }

    Core::Core(Core &&other) noexcept :
        m_scenes(std::move(other.m_scenes)),
        m_importer(std::move(other.m_importer))
    {
        // nothing to do.
    }

    Core::~Core(void)
    {
        for (Scene *scene : this->m_scenes)
        {
            delete scene;
        }
    }



    Core &
    Core::operator=(const Core &other)
    {
        for (Scene *scene : other.m_scenes)
        {
            this->m_scenes.push_back(new Scene(*scene));
        }
        return *this;
    }

    Core &
    Core::operator=(Core &&other) noexcept
    {
        this->m_scenes = std::move(other.m_scenes);
        this->m_importer = std::move(other.m_importer);
        return *this;
    }



    void
    Core::update(void)
    {
        for (Scene *scene : this->m_scenes)
        {
            scene->update();
        }
    }

    void
    Core::render(void)
    {
        for (Scene *scene : this->m_scenes)
        {
            scene->render();
        }
    }



    void
    Core::load(const std::string &filename)
    {
        // TODO GSL OWNER && NOT NULL
        Scene *test = this->m_importer.import(filename);

        this->m_scenes.push_back(test);
    }

}
