
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
                result->link();
            }
            // TODO initialisation.
        }

        ShaderProgramLibrary::~ShaderProgramLibrary(void)
        {
            // nothing to do atm.
        }
    }
}
