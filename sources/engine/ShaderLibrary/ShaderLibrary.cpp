
#include    <string>
#include    <fstream>
#include    <streambuf>

#include    "worldparticles.hpp"
#include    "ShaderLibrary.hpp"
#include    "internal/ShaderMapping.hpp"

namespace WorldParticles
{
    namespace Engine
    {

        ShaderLibrary::ShaderLibrary(void)
        {
            for (const auto &it : MappedShaders)
            {
                const ShaderProperty &property = it.second;
                std::ifstream stream(RESOURCES_PATH "/shaders/" + property.filename);
                std::string data((std::istreambuf_iterator<char>(stream)),
                        std::istreambuf_iterator<char>());
                auto shader = std::make_shared<Shader>(property.shaderType, data);
                shader->compile();
                this->resources[it.first] = shader;
            }
        }

        ShaderLibrary::~ShaderLibrary(void)
        {
            // nothing to do atm.
        }

    }
}
