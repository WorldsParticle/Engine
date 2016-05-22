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
#include    <IL/il.h>
#include    <stdexcept>
#include    <sstream>

#include    "Engine/Version.hpp"
#include    "Engine/Configuration.hpp"
#include    "Engine/Core.hpp"
#include    "Engine/Event/Event.hpp"
#include    "Engine/Core/Scene.hpp"
#include    "Engine/Core/Terrain.hpp"

using namespace     log4cpp;

namespace   Engine
{

    Core::Core(void) :
        m_scenes(),
        m_importer(),
        m_generator()
    {

        PropertyConfigurator::configure(RESOURCES_PATH "/log4cpp.conf");
        Category& root = Category::getRoot();
        root << Priority::INFO << "Engine launch :";
        root << Priority::INFO << "\t version : " PROJECT_VERSION_FULL;

        glewExperimental = GL_TRUE;
        GLenum err = glewInit();

        if (GLEW_OK != err)
        {
            std::stringstream errMsg;
            errMsg << "Glew Init failure :" << glewGetErrorString(err);
            root << Priority::ERROR << errMsg.str();
            throw std::runtime_error(errMsg.str());
        }

	ilInit(); /* Initialization of DevIL */

        ILenum ilErr = ilGetError();
        if (ilErr != IL_NO_ERROR)
        {
            std::stringstream errMsg;
            errMsg << "Devil Init failure :" << ilGetString(ilErr);
            root << Priority::ERROR << errMsg.str();
            throw std::runtime_error(errMsg.str());
        }
        // nothing to do
    }

    Core::Core(const Core &other) :
        m_scenes(),
        m_importer(other.m_importer),
        m_generator()
    {
        for (Scene *scene : other.m_scenes)
        {
            this->m_scenes.push_back(new Scene(*scene));
        }
    }

    Core::Core(Core &&other) noexcept :
        m_scenes(std::move(other.m_scenes)),
        m_importer(std::move(other.m_importer)),
        m_generator()
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
//        for (Scene *scene : this->m_scenes)
//        {
//            scene->render();
//        }
    }

    void
    Core::push_event(const Event::Event &event)
    {
        for (Scene *scene : this->m_scenes)
        {
            scene->push_event(event);
            if (event.is_consumed())
            {
                break;
            }
        }
    }



    void
    Core::load(const std::string &filename)
    {
        // TODO GSL OWNER
        Scene *test = this->m_importer.import(filename);

        Category& root = Category::getRoot();
        root << Priority::INFO << "Imported " << filename;

//        std::string modelFilename("/home/marie/project/WorldsParticleMaster/Engine/resources/models/monkey.dae");
//        if (!this->m_importer.importModel(modelFilename, test))
//        {
//            root << Priority::WARN << "Could not import " << modelFilename;
//        }
//
//        root << Priority::INFO << "Imported " << modelFilename;


//        Terrain should not be added there
//        std::cout << "ready to add terrain..." << std::endl;
//        test->add(new Terrain(test, test->getShaderPrograms()));
//        std::cout << "added terrain..." << std::endl;

        this->m_scenes.push_back(test);
        root << Priority::INFO << "added scene.. " << filename;
        test->render();
    }

}
