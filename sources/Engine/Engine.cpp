///
/// \file Engine.cpp
///
/// \author Martin-Pierrat Louis (mart_p)
///
/// \date Sat, 16 Jan 2016 19:57:28
///
/// \version 1.0.4
///

#include    <log4cpp/Category.hh>

#include    "Engine.hpp"

using namespace     log4cpp;

namespace   WorldParticles
{
    namespace   Engine
    {

        Engine::Engine(void)
        {
            // nothing to do
        }

        Engine::Engine(const Engine &other) :
            importer(other.importer)
        {
            for (Scene *scene : other.scenes)
            {
                this->scenes.push_back(new Scene(*scene));
            }
        }

        Engine::Engine(Engine &&other) noexcept :
            scenes(std::move(other.scenes)),
            importer(std::move(other.importer))
        {
            // nothing to do.
        }

        Engine::~Engine(void)
        {
            for (Scene *scene : this->scenes)
            {
                delete scene;
            }
        }



        Engine &
        Engine::operator=(const Engine &other)
        {
            for (Scene *scene : other.scenes)
            {
                this->scenes.push_back(new Scene(*scene));
            }
            return *this;
        }

        Engine &
        Engine::operator=(Engine &&other) noexcept
        {
            this->scenes = std::move(other.scenes);
            this->importer = std::move(other.importer);
            return *this;
        }



        void
        Engine::update(void)
        {
            for (Scene *scene : this->scenes)
            {
                scene->update();
            }
        }

        void
        Engine::render(void)
        {
            for (Scene *scene : this->scenes)
            {
                scene->render();
            }
        }



        void
        Engine::load(const std::string &filename)
        {
            Category    &root = Category::getRoot();
            // TODO GSL OWNER && NOT NULL
            //
            root << Priority::DEBUG << "Engine - Load()";
            Scene *test = this->importer.import(filename);

            this->scenes.push_back(test);
        }

    }
}
