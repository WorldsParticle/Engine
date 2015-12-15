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
            Camera  *cam = new Camera(glm::vec3(50.0));
            Camera  *cam2 = new Camera(glm::vec3(500.0));

            basic->add(new Primitives::Cube(glm::vec3(0.0, 0.0, 0.0)));
            basic->add(new Primitives::Cube(glm::vec3(5.0, 0.0, 0.0)));
            basic->add(new Primitives::Cube(glm::vec3(-5.0, 0.0, 0.0)));

            basic->add(cam);

            //Scene   *test = importer.importScene(filename);
            //*test << cam2;
            //this->_scenes.push_back(test);
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
