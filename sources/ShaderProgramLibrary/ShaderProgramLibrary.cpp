///
/// \file ShaderProgramLibrary.cpp
///
/// \author Martin-Pierrat Louis (mart_p)
///
/// \date Fri, 15 Jan 2016 13:34:39
///
/// \version 1.0.1
///

#include    <log4cpp/Category.hh>

#include    "ShaderLibrary.hpp"
#include    "ShaderProgramLibrary.hpp"
#include    "internal/ShaderProgramMapping.hpp"

using namespace     log4cpp;

namespace   WorldParticles
{
    namespace   Engine
    {

        ShaderProgramLibrary::ShaderProgramLibrary(void) :
            shaders()
        {
            Category &root = Category::getRoot();
            root << Priority::DEBUG << "Initialisation des shaderprograms.";
            for (const auto &it : MappedShaderProgram)
            {
                const ShaderProgramProperty &property = it.second;
                root << Priority::DEBUG << "Création du ShaderProgram " << it.first;
                auto result = std::make_shared<ShaderProgram>();
                for (const auto &shadername : property.associatedShaders)
                {
                    result->add(this->shaders.get(shadername));
                }
                result->link();
                this->resources.push_back(result);
            }
            // TODO initialisation.
        }

        ShaderProgramLibrary::~ShaderProgramLibrary(void)
        {
            // nothing to do atm.
        }
    }
}