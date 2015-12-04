#ifndef     __SHADER_PROGRAM_HPP__
# define    __SHADER_PROGRAM_HPP__

namespace   WorldParticles
{
    namespace   Engine
    {
        ///
        /// \brief This class is used to abstract a program shader.
        ///
        class       ShaderProgram
        {
            public:
                ///
                /// \brief Default constructor
                ///
                ShaderProgram(void);

                ///
                /// \brief Destructor
                ///
                ~ShaderProgram(void);

            public:

                void    Bind(void);

            private:


        };
    }
}

#endif /* !__SHADER_PROGRAM_HPP__ */
