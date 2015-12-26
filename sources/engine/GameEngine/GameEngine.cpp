#include    "GameEngine.hpp"

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
        GameEngine::draw(void)
        {
            for (Scene *scene : this->scenes)
            {
                scene->draw();
            }
        }



        void
        GameEngine::load(const std::string &filename)
        {
            // TODO GSL OWNER && NOT NULL
            Scene *test = this->importer.import(filename);

            this->scenes.push_back(test);
        }

    }
}
