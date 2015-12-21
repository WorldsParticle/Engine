#ifndef     __ARRAY_OBJECT_HPP__
# define    __ARRAY_OBJECT_HPP__

namespace   WorldParticles
{
    namespace   Engine
    {
        class       ArrayObject
        {
            public:
                ArrayObject(void);
                ~ArrayObject(void);

            public:
                void    bind(void) const;
                void    unbind(void) const;

            private:
                unsigned int    id;
        };
    }
}

#endif /* !__ARRAY_OBJECT_HPP__ */
