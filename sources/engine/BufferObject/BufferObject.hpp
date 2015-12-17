
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
                    UNDEFINED,
                    ELEMENT_ARRAY,
                    ARRAY
                };

            public:
                ///
                /// \brief Create an empty buffer object.
                ///
                BufferObject(void);

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

            public:
                ///
                /// \brief Setter for the Type attribute of the BufferObject.
                ///
                void            setType(const Type &type);

                ///
                ///
                ///
                void            setData(const std::vector<glm::vec4> &data);

                ///
                ///
                ///
                void            setData(const std::vector<glm::vec3> &data);

                ///
                ///
                ///
                void            setData(const std::vector<glm::vec2> &data);

                ///
                ///
                ///
                void            setData(const std::vector<float> &data);

            public:
                ///
                /// \brief Getter for the Type attribute of the BufferObject.
                ///
                Type            getType(void) const;

            private:
                ///
                /// \brief This attribute is used to contains the graphic id of the buffer object.
                ///
                unsigned int    id;

                ///
                /// \brief This attribute is used to contains the type of the buffer object.
                ///
                unsigned int    type;

                ///
                /// \brief This attribute is used to know if the BufferObject is dynamic.
                ///
                unsigned int    dynamic;
        };
    }
}

#endif /* !__BUFFER_OBJECT_HPP__ */
