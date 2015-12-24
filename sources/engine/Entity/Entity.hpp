#ifndef     __ENTITY_HPP__
# define    __ENTITY_HPP__

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
                Entity(SceneGraphNode *node);

                // TODO : check for copy / move

                virtual ~Entity(void) noexcept;

            public:
                ///
                /// \brief method used to update the entity.
                ///
                void    update(void) = 0;

            private:
                ///
                /// \brief The node which the entity is attached.
                ///
                SceneGraphNode  *node;
        };
    }
}

#endif /* !__ENTITY_HPP__ */
