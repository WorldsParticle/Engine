#include    <log4cpp/Category.hh>

#include    "RenderGraph.hpp"

using namespace     log4cpp;

namespace   WorldParticles
{
    namespace   Engine
    {
        RenderGraph::RenderGraph(Scene *scene) :
            scene(scene)
        {

        }

        RenderGraph::RenderGraph(const RenderGraph &other) :
            scene(other.scene)
        {

        }

        RenderGraph::RenderGraph(RenderGraph &&other) noexcept :
            scene(std::move(other.scene))
        {

        }

        RenderGraph::~RenderGraph(void) noexcept
        {

        }



        RenderGraph &
        RenderGraph::operator=(const RenderGraph &other)
        {
            this->scene = other.scene;
            return *this;
        }

        RenderGraph &
        RenderGraph::operator=(RenderGraph &&other) noexcept
        {
            this->scene = std::move(other.scene);
            return *this;
        }


        void
        RenderGraph::render(void)
        {
            Category    &root = Category::getRoot();

            root << Priority::DEBUG << "RenderGraph - render()";
        }
    }
}
