///
/// \file Core.cpp
///
/// \author Martin-Pierrat Louis (mart_p)
///
/// \date Sat, 16 Jan 2016 22:31:41
///
/// \version 1.0.14
///

#include    <log4cpp/Category.hh>

#include    "Engine/Core.hpp"

using namespace     log4cpp;

namespace   Engine
{

    Core::Core(void)
    {
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
        Category    &root = Category::getRoot();
        // TODO GSL OWNER && NOT NULL
        //
        root << Priority::DEBUG << "Core - Load()";
        Scene *test = this->importer.import(filename);

        this->scenes.push_back(test);
    }

}
