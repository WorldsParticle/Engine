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

#include    <iostream>
#include    <chrono>
#include    "Engine/Nuages/NuagesMaterial.hpp"
#include    "Engine/Core/ShaderProgram.hpp"
#include    "Engine/Core/Texture.hpp"
#include    "Engine/Core/TextureLibrary.hpp"

namespace   Engine
{

    NuagesMaterial::NuagesMaterial(const std::shared_ptr<ShaderProgram> &shaderprogram) :
        Material(shaderprogram),
        m_name("Default"),
        m_shaderprogram(shaderprogram),
        m_texture(nullptr)
    {
        // nothing to do
    }


    NuagesMaterial::~NuagesMaterial(void) noexcept
    {
        // nothind to do.
    }




    void
    NuagesMaterial::bind(void) const
    {
        static auto  initial_time = std::chrono::high_resolution_clock::now();

        auto diff = std::chrono::high_resolution_clock::now() - initial_time;

        unsigned int elapsed = static_cast<int>(std::chrono::duration_cast<std::chrono::milliseconds>(diff).count());

        this->m_shaderprogram->bind();
        this->m_shaderprogram->setUniform("elapsed", elapsed);
    }


}
