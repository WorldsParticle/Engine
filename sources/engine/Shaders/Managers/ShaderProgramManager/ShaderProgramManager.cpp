
#include    "ShaderManager.hpp"
#include    "ShaderProgramManager.hpp"
#include    "internal/ShaderProgramMapping.hpp"

namespace   WorldParticles
{
    namespace   Engine
    {

        std::map<ShaderProgramName, std::shared_ptr<ShaderProgram>>     ShaderProgramManager::_shaderPrograms = std::map<ShaderProgramName, std::shared_ptr<ShaderProgram>>();

        const std::shared_ptr<ShaderProgram> &
        ShaderProgramManager::Get(const ShaderProgramName &name)
        {
            std::map<ShaderProgramName, std::shared_ptr<ShaderProgram>>::iterator   it;

            if ((it = ShaderProgramManager::_shaderPrograms.find(name)) != ShaderProgramManager::_shaderPrograms.end())
                return it->second;
            return ShaderProgramManager::_shaderPrograms[name] = CreateShaderProgram(name);
        }

        std::shared_ptr<ShaderProgram>
        ShaderProgramManager::CreateShaderProgram(const ShaderProgramName &name)
        {
            std::map<ShaderProgramName, ShaderProgramProperty>::const_iterator it;
            std::shared_ptr<ShaderProgram>  result;

            if ((it = MappedShaderProgram.find(name)) != MappedShaderProgram.end())
            {
                const ShaderProgramProperty   &property = it->second;
                for (const ShaderName &shaderName : property.associatedShaders)
                {
                    result->AddShader(ShaderManager::Get(shaderName));
                }
                result->Link();
            }
            return result;
        }
    }
}
