#include    "GameEngine.hpp"

#include    "AssimpImporter.hpp"
#include    "glwindow.h" /// TODO replace the glwindow.h with proper opengl context.

namespace   WorldParticles
{
    namespace   Engine
    {

        GameEngine::GameEngine(void)
        {
            // nothing to do ?
        }

        GameEngine::~GameEngine(void)
        {
            for (Scene *scene : this->scenes)
            {
                delete scene;
            }
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

            this->_scenes.push_back(test);
        }

    }
}
