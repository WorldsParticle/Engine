///
/// \file Entity.hpp
///
/// \author Martin-Pierrat Louis (mart_p)
///
/// \date Sat, 16 Jan 2016 21:05:14
///
/// \version 1.0.3
///

#ifndef     __ENGINE_ENTITY_HPP__
# define    __ENGINE_ENTITY_HPP__

#include    <string>

namespace   WorldParticles
{
    namespace   Engine
    {

        class       Scene;
        class       SceneGraphNode;
        class       Transform;

        ///
        /// \brief This class is used to represent something physically or not in the 3D world.
        ///
        class       Entity
        {
            public:
                ///
                /// \brief Default constructor
                /// \param node the node which the entity is attached.
                ///
                Entity(SceneGraphNode *node); // TODO GSL NOT NULL

                ///
                /// \brief Copy constructor.
                ///
                Entity(const Entity &other);

                ///
                /// \brief Move constructor.
                ///
                Entity(Entity &&other);

                ///
                /// \brief Destructor.
                ///
                virtual ~Entity(void) noexcept;

            public:
                ///
                /// \brief Copy assignment operator.
                ///
                Entity  &operator=(const Entity &other);

                ///
                /// \brief Move assignment operator.
                ///
                Entity  &operator=(Entity &&other);

            public:
                ///
                /// \brief clone pattern
                ///
                virtual Entity  *clone(void) const = 0;

            public:
                ///
                /// \brief method used to update the entity.
                ///
                virtual void    update(void) = 0;

            public:
                ///
                /// \brief Getter for the associated node name.
                ///
                virtual const std::string   &getName(void) const;

                ///
                /// \brief Getter for the transformation matrix of the associated node.
                ///
                const Transform             &getTransform(void) const;

            protected:
                ///
                /// \brief The node which the entity is attached.
                ///
                SceneGraphNode  *node; // TODO GSL NOT NULL

                ///
                /// \brief The scene that contains the Entity.
                ///
                Scene           *scene;
        };
    }
}

#endif /* !__ENGINE_ENTITY_HPP__ */
