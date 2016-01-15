///
/// \file Object.hpp
///
/// \author Martin-Pierrat Louis (mart_p)
///
/// \date Fri, 15 Jan 2016 13:31:55
///
/// \version 1.0.2
///

#ifndef     __OBJECT_HPP__
# define    __OBJECT_HPP__

#include    <list>
#include    <assimp/scene.h>

#include    "Entity.hpp"

namespace   WorldParticles
{
    namespace   Engine
    {

        class   Mesh;

        ///
        /// \brief This class is used to represent a physical entity.
        ///
        class       Object : public Entity
        {
            public:
                ///
                /// \brief Default constructor.
                /// \param node the node related to the object.
                ///
                Object(SceneGraphNode *node); // TODO GSL NOT NULL

                ///
                /// \brief Construct an object from an assimp node.
                ///
                Object(const aiNode *assimpNode, SceneGraphNode *node); // TODO GSL NOT NULL

                ///
                /// \brief Copy constructor.
                ///
                Object(const Object &other) = default;

                ///
                /// \brief Move constructor.
                ///
                Object(Object &&other) noexcept = default;

                ///
                /// \brief Destructor.
                ///
                virtual ~Object(void) noexcept;

            public:
                ///
                /// \brief Copy assignment operator.
                ///
                Object  &operator=(const Object &other) = default;

                ///
                /// \brief Move assigment operator.
                ///
                Object  &operator=(Object &&other) noexcept = default;

            public:
                ///
                /// \brief This method is used to clone the object.
                ///
                Object  *clone(void) const;

                ///
                /// \brief Update the object.
                ///
                void    update(void);

            public:
                ///
                /// \brief Getter for the mesh list.
                ///
                const std::list<Mesh *>     &getMeshes(void) const;

            protected:
                ///
                /// \brief The meshes associated with the object.
                ///
                std::list<Mesh *>     meshes; // TODO GSL NOT NULL
        };
    }
}

#endif /* !__OBJECT_HPP__ */
