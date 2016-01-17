///
/// \file ShaderLibrary.cpp
///
/// \author Martin-Pierrat Louis (mart_p)
///
/// \date Sun, 17 Jan 2016 07:01:53
///
/// \version 1.0.10
///

#include    <string>
#include    <fstream>
#include    <streambuf>
#include    <log4cpp/Category.hh>

#include    <Engine/Configuration.hpp>
#include    <Engine/ShaderLibrary.hpp>
#include    <Engine/internal/ShaderMapping.hpp>

using namespace     log4cpp;

namespace Engine
{

    ShaderLibrary::ShaderLibrary(void)
    {
        Category &root = Category::getRoot();
        for (const auto &it : MappedShaders)
        {
            const ShaderProperty &property = it.second;
            root << Priority::DEBUG << "Création du shader : " << property.filename;
            std::ifstream stream(RESOURCES_PATH "/shaders/" + property.filename);
            std::string data((std::istreambuf_iterator<char>(stream)),
                    std::istreambuf_iterator<char>());
            root << Priority::DEBUG << "Valeur : " << data;
            std::shared_ptr<Shader> shader = std::make_shared<Shader>(property.shaderType, data);
            shader->compile();
            this->resources.push_back(shader);
        }
    }

    ShaderLibrary::~ShaderLibrary(void)
    {
        // nothing to do atm.
    }

}
