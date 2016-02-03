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

#ifndef     __ENGINE_ASSIMP_IMPORTER_HPP__
# define    __ENGINE_ASSIMP_IMPORTER_HPP__

#include    <string>
#include    <list>
#include    <assimp/Importer.hpp>
#include    <assimp/mesh.h>

namespace   Engine
{

    class   Scene;

    ///
    /// \brief This class is used to import a scene with the assimp library.
    ///
    class       AssimpImporter
    {
        public:
            ///
            /// \brief Default constructor
            ///
            AssimpImporter(void);

            ///
            /// \brief Copy constructor.
            ///
            AssimpImporter(const AssimpImporter &other) = default;

            ///
            /// \brief Move constructor.
            ///
            AssimpImporter(AssimpImporter &&other) noexcept = default;

            ///
            /// \brief Destructor
            ///
            virtual ~AssimpImporter(void) noexcept;

        public:
            ///
            /// \brief Copy assignment operator.
            ///
            AssimpImporter  &operator=(const AssimpImporter &other) = default;

            ///
            /// \brief Move assignment importer.
            ///
            AssimpImporter  &operator=(AssimpImporter &&other) noexcept = default;

        public:
            ///
            /// \brief This method is used to load a scene from a filename.
            ///
            Scene   *import(const std::string &filename);

        private:
            ///
            /// \brief This method use the ReadFile method with appropriate assimp flags.
            ///
            const aiScene   *load(const std::string &filename);

        private:
            ///
            /// \brief the assimp importer that wil be used to load the file in a new scene.
            ///
            Assimp::Importer    m_importer;
    };
}

#endif /* !__ENGINE_ASSIMP_IMPORTER_HPP__ */
