
#include <string>
#include <fstream>
#include <streambuf>

#include    "worldparticles.hpp"
#include    "ShaderManager.hpp"
#include    "internal/ShaderMapping.hpp"

namespace WorldParticles
{
    namespace Engine
    {

        std::map<ShaderName, std::shared_ptr<Shader>>   ShaderManager::_shaders = std::map<ShaderName, std::shared_ptr<Shader>>();

        const std::shared_ptr<Shader> &
        ShaderManager::Get(const ShaderName &name)
        {
            std::map<ShaderName, std::shared_ptr<Shader>>::iterator     it;

            if ((it = ShaderManager::_shaders.find(name)) != ShaderManager::_shaders.end())
                return it->second;
            return ShaderManager::_shaders[name] = ShaderManager::CreateShader(name);
        }

        std::shared_ptr<Shader>
        ShaderManager::CreateShader(const ShaderName &name)
        {
            std::map<ShaderName, ShaderProperty>::const_iterator    it;
            std::shared_ptr<Shader>     result;

            if ((it = MappedShaders.find(name)) != MappedShaders.end())
            {
                const ShaderProperty &property = it->second;
                std::ifstream stream(RESOURCES_PATH "/shaders/" + property.filename);
                std::string data((std::istreambuf_iterator<char>(stream)), std::istreambuf_iterator<char>());
                result = std::make_shared<Shader>(property.shaderType, data);
                result->Compile();
            }
            return result;
        }

    }
}
