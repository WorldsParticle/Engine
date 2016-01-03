#include    <log4cpp/Category.hh>

#include    "GameEngine.hpp"

using namespace     log4cpp;

namespace   WorldParticles
{
    namespace   Engine
    {

        GameEngine::GameEngine(void)
        {
            // nothing to do
        }

        GameEngine::GameEngine(const GameEngine &other) :
            importer(other.importer)
        {
            for (Scene *scene : other.scenes)
            {
                this->scenes.push_back(new Scene(*scene));
            }
        }

        GameEngine::GameEngine(GameEngine &&other) noexcept :
            scenes(std::move(other.scenes)),
            importer(std::move(other.importer))
        {
            // nothing to do.
        }

        GameEngine::~GameEngine(void)
        {
            for (Scene *scene : this->scenes)
            {
                delete scene;
            }
        }



        GameEngine &
        GameEngine::operator=(const GameEngine &other)
        {
            for (Scene *scene : other.scenes)
            {
                this->scenes.push_back(new Scene(*scene));
            }
            return *this;
        }

        GameEngine &
        GameEngine::operator=(GameEngine &&other) noexcept
        {
            this->scenes = std::move(other.scenes);
            this->importer = std::move(other.importer);
            return *this;
        }



        void
        GameEngine::update(void)
        {
            for (Scene *scene : this->scenes)
            {
                scene->update();
            }
        }

        void
        GameEngine::render(void)
        {
            for (Scene *scene : this->scenes)
            {
                scene->render();
            }
        }



        void
        GameEngine::load(const std::string &filename)
        {
            Category    &root = Category::getRoot();
            // TODO GSL OWNER && NOT NULL
            //
            root << Priority::DEBUG << "GameEngine - Load()";
            Scene *test = this->importer.import(filename);

            this->scenes.push_back(test);
        }

    }
}
