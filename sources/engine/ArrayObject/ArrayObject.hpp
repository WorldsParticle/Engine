#ifndef     __ARRAY_OBJECT_HPP__
# define    __ARRAY_OBJECT_HPP__

namespace   WorldParticles
{
    namespace   Engine
    {
        ///
        /// \brief This class is an abstraction of the Vertex Array Object of the OpenGL API.
        ///
        class       ArrayObject
        {
            public:
                ///
                /// \brief Default constructor.
                ///
                ArrayObject(void);

                ///
                /// \brief Destructor.
                ///
                ~ArrayObject(void);

            public:
                ///
                /// \brief Bind the array object in the graphic pipeline.
                ///
                void    bind(void) const;

                ///
                /// \brief Unbind the array object from the graphic pipeline.
                ///
                void    unbind(void) const;

            private:
                ///
                /// \brief The id of the vertex array object.
                ///
                unsigned int    id;
        };
    }
}

#endif /* !__ARRAY_OBJECT_HPP__ */
