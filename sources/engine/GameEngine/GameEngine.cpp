#include    "GameEngine.hpp"
#include    "AssimpImporter.hpp"
#include    "Cube.hpp"
#include    "glwindow.h"

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
            for (Scene *scene : this->_scenes)
            {
                delete scene;
            }
        }


        bool    GameEngine::initialise(void)
        {
            bool    result = true;

            for (Scene *scene : this->_scenes)
            {
                if (scene == nullptr) continue;
                result = scene->initialise() && result;
            }
            return result;
        }

        void    GameEngine::update(void)
        {
            for (Scene *scene : this->_scenes)
            {
                if (scene == nullptr) continue;
                scene->update();
            }
        }

        void    GameEngine::draw(void)
        {
            GLWindow::m_funcs->glEnable(GL_DEPTH_TEST);
            for (Scene *scene : this->_scenes)
            {
                if (scene == nullptr) continue;
                scene->draw();
            }
        }


        bool    GameEngine::load(const std::string &filename)
        {
            AssimpImporter  importer;
            Camera          *cam = new Camera(glm::vec3(5.0));

            Scene   *test = importer.importScene(filename);
            *test << cam;
            this->_scenes.push_back(test);
            return true;
        }

        /// TODO should be tested
        void    GameEngine::add(Scene *scene)
        {
            this->_scenes.push_back(scene);
            this->_scenes.sort([](const auto &a, const auto &b) {
                    return a->getLayerNumber() > b->getLayerNumber();
            });
        }

    }
}
