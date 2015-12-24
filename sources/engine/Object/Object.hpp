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
                Object(void);
                ~Object(void);

            public:

                void    update(void);

            protected:

                std::list<Mesh>     meshes;
        };
    }
}

#endif /* !__OBJECT_HPP__ */
