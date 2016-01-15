///
/// \file Light.hpp
///
/// \author Martin-Pierrat Louis (mart_p)
///
/// \date Fri, 15 Jan 2016 13:30:39
///
/// \version 1.0.1
///

#ifndef     __LIGHT_HPP__
# define    __LIGHT_HPP__

#include    <string>
#include    <assimp/light.h>

#include    "Entity.hpp"

namespace WorldParticles
{
    namespace Engine
    {

        ///
        /// \brief This class is used to represent a light in the 3d world.
        ///
        /// TODO : implement the class.
        ///
        class Light : public Entity
        {
            public:
                ///
                /// \brief Default constructor.
                ///
                Light(SceneGraphNode *node);

                ///
                /// \brief Construct a light from an assimp light.
                ///
                Light(const aiLight *assimpLight, SceneGraphNode *node);

                ///
                /// \brief Copy constructor.
                ///
                Light(const Light &other) = default;

                ///
                /// \brief Move constructor.
                ///
                Light(Light &&other) noexcept = default;

                ///
                /// \brief Destructor.
                ///
                virtual ~Light(void) noexcept;

            public:
                ///
                /// \brief Copy assigment operator.
                ///
                Light   &operator=(const Light &other) = default;

                ///
                /// \brief Move assigment operator.
                ///
                Light   &operator=(Light &&other) noexcept = default;

            public:
                ///
                /// \brief This method clone the light.
                ///
                virtual Light   *clone(void) const;

                ///
                /// \brief This method is used to update the light.
                ///
                void            update(void);

            public:
                ///
                /// \brief Getter for the light name.
                ///
                const std::string   &getName(void) const;

            private:
                ///
                /// \brief The name of the light.
                ///
                std::string         name;

        };
    }
}

#endif /* !__LIGHT_HPP__ */
