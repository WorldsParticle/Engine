
#include    "ShaderProgram.hpp"

namespace   WorldParticles
{
    namespace   Engine
    {

        ShaderProgram::ShaderProgram(void) :
            _isCompiled(false),
            _vertexShaderIsPresent(false),
            _fragmentShaderIsPresent(false),
            _geometryShaderIsPresent(false)
        {

        }

        ShaderProgram::~ShaderProgram(void)
        {

        }


        ShaderProgram &operator<<(const std::shared_ptr<Shader> &shader)
        {
            this->AddShader(shader);
            return *this;
        }



        void AddShader(const std::shared_ptr<Shader> &shader)
        {

        }


    }
}
