
#include    "ShaderManager.hpp"
#include    "ShaderProgramManager.hpp"
#include    "internal/ShaderProgramMapping.hpp"

namespace   WorldParticles
{
    namespace   Engine
    {

        ShaderProgramLibrary::ShaderProgramLibrary(void)
        {

            for (const auto &it : MappedShaderProgram)
            {
                const ShaderProgramProperty &property = it->second;
                ShaderProgram *result = new ShaderProgram();
                for (const auto &shadername : property.associatedShaders)
                {
                    result->add(this->shaders.get(shadername));
                }
            }
            // TODO initialisation.
        }

        ShaderProgramLibrary::~ShaderProgramLibrary(void)
        {
            // nothing to do atm.
        }

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
                result = std::make_shared<ShaderProgram>();
                for (const ShaderName &shaderName : property.associatedShaders)
                {
                    result->add(ShaderManager::Get(shaderName));
                }
                result->link();
            }
            return result;
        }
    }
}
