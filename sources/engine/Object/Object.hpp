#ifndef     __OBJECT_HPP__
# define    __OBJECT_HPP__

#include    "Entity.hpp"

namespace   WorldParticles
{
    namespace   Engine
    {
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
                Object(const Object &other);

                ///
                /// \brief Move constructor.
                ///
                Object(Object &&other) noexcept;

                ///
                /// \brief Destructor.
                ///
                virtual ~Object(void) noexcept;

            public:
                ///
                /// \brief Copy assignment operator.
                ///
                Object  &operator=(const Object &other);

                ///
                /// \brief Move assigment operator.
                ///
                Object  &operator=(Object &&other) noexcept;

            public:
                ///
                /// \brief Update the object.
                ///
                void    update(void);

            protected:
                ///
                /// \brief The meshes associated with the object.
                ///
                std::list<Mesh *>     meshes; // TODO GSL NOT NULL
        };
    }
}

#endif /* !__OBJECT_HPP__ */
