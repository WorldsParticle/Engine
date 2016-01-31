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

#include    <log4cpp/Category.hh>

#include    "Engine/Core/ShaderLibrary.hpp"
#include    "Engine/Core/ShaderProgramLibrary.hpp"
#include    "Engine/Core/ShaderProgramMapping.hpp"

using namespace     log4cpp;

namespace   Engine
{

    ShaderProgramLibrary::ShaderProgramLibrary(void) :
        m_shaders()
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
                result->add(this->m_shaders.get(shadername));
            }
            result->link();
            this->m_resources.push_back(result);
        }
        // TODO initialisation.
    }

    ShaderProgramLibrary::~ShaderProgramLibrary(void)
    {
        // nothing to do atm.
    }
}
