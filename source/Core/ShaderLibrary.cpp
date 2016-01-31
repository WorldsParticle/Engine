//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 3 of the License, or
// any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this program; If not, see <http://www.gnu.org/licenses/>.
//
// Copyright (C) 2016 Martin-Pierrat Louis (louismartinpierrat@gmail.com)
//

#include    <string>
#include    <fstream>
#include    <streambuf>
#include    <log4cpp/Category.hh>

#include    "Engine/Configuration.hpp"
#include    "Engine/Core/ShaderLibrary.hpp"
#include    "Engine/Core/ShaderMapping.hpp"

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
            this->m_resources.push_back(shader);
        }
    }

    ShaderLibrary::~ShaderLibrary(void)
    {
        // nothing to do atm.
    }

}
