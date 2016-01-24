///
/// \file Core.cpp
///
/// \author Martin-Pierrat Louis (mart_p)
///
/// \date Sun, 17 Jan 2016 14:25:12
///
/// \version 1.0.34
///

#include    <GL/glew.h>
#include    <log4cpp/Category.hh>
#include    <log4cpp/PropertyConfigurator.hh>

#include    "Engine/Version.hpp"
#include    "Engine/Configuration.hpp"
#include    "Engine/Core.hpp"

using namespace     log4cpp;

namespace   Engine
{

    Core::Core(void)
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
        importer(other.importer)
    {
        for (Scene *scene : other.scenes)
        {
            this->scenes.push_back(new Scene(*scene));
        }
    }

    Core::Core(Core &&other) noexcept :
        scenes(std::move(other.scenes)),
        importer(std::move(other.importer))
    {
        // nothing to do.
    }

    Core::~Core(void)
    {
        for (Scene *scene : this->scenes)
        {
            delete scene;
        }
    }



    Core &
    Core::operator=(const Core &other)
    {
        for (Scene *scene : other.scenes)
        {
            this->scenes.push_back(new Scene(*scene));
        }
        return *this;
    }

    Core &
    Core::operator=(Core &&other) noexcept
    {
        this->scenes = std::move(other.scenes);
        this->importer = std::move(other.importer);
        return *this;
    }



    void
    Core::update(void)
    {
        for (Scene *scene : this->scenes)
        {
            scene->update();
        }
    }

    void
    Core::render(void)
    {
        for (Scene *scene : this->scenes)
        {
            scene->render();
        }
    }



    void
    Core::load(const std::string &filename)
    {
        // TODO GSL OWNER && NOT NULL
        Scene *test = this->importer.import(filename);

        this->scenes.push_back(test);
    }

}
