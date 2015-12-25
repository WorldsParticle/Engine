#ifndef     __ENTITY_HPP__
# define    __ENTITY_HPP__

#include    "SceneGraphNode.hpp"

namespace   WorldParticles
{
    namespace   Engine
    {
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
                /// \brief method used to update the entity.
                ///
                void    update(void) = 0;

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

#endif /* !__ENTITY_HPP__ */
