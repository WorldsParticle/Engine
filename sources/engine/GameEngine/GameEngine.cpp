#include    "GameEngine.hpp"
#include    "AssimpImporter.hpp"

#include    "Cube.hpp"

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
            for (Scene *scene : this->_scenes)
            {
                if (scene == nullptr) continue;
                scene->draw();
            }
        }


        bool    GameEngine::load(const std::string &filename)
        {
            AssimpImporter  importer;

            Scene   *basic = new Scene();
            Camera  *cam = new Camera(glm::vec3(5.0));
            GameObject  *cube = new Primitives::Cube();

            basic->add(cam);
            basic->add(cube);

            this->_scenes.push_back(importer.load(filename));
            this->_scenes.push_back(basic);
            return true;
        }

        /// TODO should be tested
        void    GameEngine::add(Scene *scene)
        {
            this->_scenes.push_back(scene);
            this->_scenes.sort([](const auto &a, const auto &b) {
                    return a->GetLayerNumber() > b->GetLayerNumber();
            });
        }

    }
}
