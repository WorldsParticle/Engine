
#ifndef     __BUFFER_OBJECT_HPP__
# define    __BUFFER_OBJECT_HPP__

#include    <vector>
#include    <glm/glm.hpp>

namespace   WorldParticles
{
    namespace   Engine
    {
        class       BufferObject
        {
            public:
                ///
                /// \brief This enum is used to define all type of buffer object.
                ///
                enum    Type
                {
                    ARRAY_BUFFER,
                    ELEMENT_ARRAY_BUFFER
                };

                enum    Usage
                {
                    STATIC_DRAW,
                    DYNAMIC_DRAW,
                    STREAM_DRAW
                };

            public:
                ///
                /// \brief Create an empty buffer object.
                ///
                BufferObject(const Type &type, const Usage &usage);

                ///
                /// \brief Destructor.
                ///
                ~BufferObject(void);

            public:
                ///
                /// \brief This method is used to bind the buffer object to the graphic API.
                ///
                void    bind(void);

                ///
                /// \brief This method is used to unbind the buffer object from the graphic API.
                ///
                void    unbind(void);

                ///
                /// \brief replace the previous data with the new data in the graphic api.
                ///
                /// If the new data is greater than the size of the buffer, the buffer will be reallocated.
                ///
                void    update(void *data, unsigned int length);

            public:
                ///
                /// \brief Setter for the type attribute.
                ///
                void            setType(const Type &type);

                ///
                /// \brief Setter for the usage attribute.
                ///
                void            setUsage(const Usage &usage);

            public:
                ///
                /// \brief Getter for the type attribute.
                ///
                const Type      &getType(void) const;

                ///
                /// \brief Getter for the usage attribute.
                ///
                const Usage     &getUsage(void) const;

            private:

                unsigned int    convert(const Type &type) const;
                unsigned int    convert(const Usage &usage) const;

            private:
                ///
                /// \brief This attribute is used to contains the graphic id of the buffer object.
                ///
                unsigned int    id;

                ///
                /// \brief This attribute is used to contains the type of the buffer object.
                ///
                Type            type;

                ///
                /// \brief This attribute is used to know if the buffer object will be updated frequently or not.
                ///
                Usage           usage;

                ///
                /// \brief the buffer size.
                ///
                unsigned int    size;
        };
    }
}

#endif /* !__BUFFER_OBJECT_HPP__ */
