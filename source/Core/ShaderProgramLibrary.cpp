///
/// \file ShaderProgramLibrary.cpp
///
/// \author Martin-Pierrat Louis (mart_p)
///
/// \date Sun, 17 Jan 2016 08:12:35
///
/// \version 1.0.6
///

#include    <log4cpp/Category.hh>

#include    "Engine/Core/ShaderLibrary.hpp"
#include    "Engine/Core/ShaderProgramLibrary.hpp"
#include    "Engine/Core/ShaderProgramMapping.hpp"

using namespace     log4cpp;

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
