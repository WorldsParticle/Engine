///
/// \file ShaderProgram.hpp
///
/// \author Martin-Pierrat Louis (mart_p)
///
/// \date Sun, 17 Jan 2016 07:50:26
///
/// \version 1.0.7
///

#ifndef     __ENGINE_SHADER_PROGRAM_HPP__
# define    __ENGINE_SHADER_PROGRAM_HPP__

#include    <glm/glm.hpp>
#include    <vector>
#include    <memory>

#include    "Engine/Core/Shader.hpp"

namespace   Engine
{
    ///
    /// \brief This class is used to abstract a program shader.
    ///
    class       ShaderProgram
    {
        public:
            ///
            /// \brief Default constructor.
            ///
            ShaderProgram(void);

            ///
            /// \brief Deleted copy constructor.
            ///
            /// We can't copy the opengl state of a shader program.
            ///
            ShaderProgram(const ShaderProgram &other) = delete;

            ///
            /// \brief Move constructor.
            ///
            ShaderProgram(ShaderProgram &&other) noexcept;

            ///
            /// \brief Destructor.
            ///
            virtual ~ShaderProgram(void) noexcept;

        public:
            ///
            /// \brief Copy assignment operator.
            ///
            ShaderProgram   &operator=(const ShaderProgram &other) = delete;

            ///
            /// \brief Move assignment operator.
            ///
            ShaderProgram   &operator=(ShaderProgram &&other) noexcept;

            ///
            /// \brief This operator is used to push a shader into the program shader.
            ///
            ShaderProgram   &operator<<(const std::shared_ptr<Shader> &shader);

        public:
            ///
            /// \brief This method is used to push a shader in the program shader.
            ///
            void    add(const std::shared_ptr<Shader> &shader);

        public:

            ///
            /// \brief This method is used to link the program shader.
            /// \return true if the link succeed, false otherwise.
            ///
            bool    link(void);

            ///
            /// \brief This method is used to bind the program shader on the graphic pipeline.
            ///
            void    bind(void) const;

            ///
            /// \brief This method is used to unbind the program shader on the graphic pipeline.
            ///
            void    unbind(void) const;

        public:
            ///
            /// \brief This method is used to know if the shader program have been already compiled.
            ///
            bool    isLinked(void) const;

        public:

            ///
            /// \brief This method should be used to set a float uniform.
            ///
            void    setUniform(const std::string &name, float value) const;

            ///
            /// \brief This method should be used to modify a vec2 uniform.
            ///
            void    setUniform(const std::string &name, const glm::vec2 &value) const;

            ///
            /// \brief This method should be used to modify a vec3 uniform.
            ///
            void    setUniform(const std::string &name, const glm::vec3 &value) const;

            ///
            /// \brief This method should be used to modify a vec4 uniform.
            ///
            void    setUniform(const std::string &name, const glm::vec4 &value) const;

            ///
            /// \brief This method should be used to modify a int uniform.
            ///
            void    setUniform(const std::string &name, int value) const;

            ///
            /// \brief This method should be used to modify a ivec2 uniform.
            ///
            void    setUniform(const std::string &name, const glm::ivec2 &value) const;

            ///
            /// \brief This method should be used to modify a ivec3 uniform.
            ///
            void    setUniform(const std::string &name, const glm::ivec3 &value) const;

            ///
            /// \brief This method should be used to modify a ivec4 uniform.
            ///
            void    setUniform(const std::string &name, const glm::ivec4 &value) const;

            ///
            /// \brief This method should be used to modify a unsigned int uniform.
            ///
            void    setUniform(const std::string &name, unsigned int value) const;

            ///
            /// \brief This method should be used to modify a uvec2 uniform.
            ///
            void    setUniform(const std::string &name, const glm::uvec2 &value) const;

            ///
            /// \brief This method should be used to modify a uvec4 uniform.
            ///
            void    setUniform(const std::string &name, const glm::uvec3 &value) const;

            ///
            /// \brief This method should be used to modify a uvec4 uniform.
            ///
            void    setUniform(const std::string &name, const glm::uvec4 &value) const;

            ///
            /// \brief This method should be used to set a float uniform array.
            ///
            void    setUniform(const std::string &name, const std::vector<float> &value) const;

            ///
            /// \brief This method should be used to modify a vec2 uniform array.
            ///
            void    setUniform(const std::string &name, const std::vector<glm::vec2> &value) const;

            ///
            /// \brief This method should be used to modify a vec3 uniform array.
            ///
            void    setUniform(const std::string &name, const std::vector<glm::vec3> &value) const;

            ///
            /// \brief This method should be used to modify a vec4 uniform array.
            ///
            void    setUniform(const std::string &name, const std::vector<glm::vec4> &value) const;

            ///
            /// \brief This method should be used to modify a int uniform array.
            ///
            void    setUniform(const std::string &name, const std::vector<int> &value) const;

            ///
            /// \brief This method should be used to modify a ivec2 uniform array.
            ///
            void    setUniform(const std::string &name, const std::vector<glm::ivec2> &value) const;

            ///
            /// \brief This method should be used to modify a ivec3 uniform array.
            ///
            void    setUniform(const std::string &name, const std::vector<glm::ivec3> &value) const;

            ///
            /// \brief This method should be used to modify a ivec4 uniform array.
            ///
            void    setUniform(const std::string &name, const std::vector<glm::ivec4> &value) const;

            ///
            /// \brief This method should be used to modify a unsigned int uniform array.
            ///
            void    setUniform(const std::string &name, const std::vector<unsigned int> &value) const;

            ///
            /// \brief This method should be used to modify a uvec2 uniform array.
            ///
            void    setUniform(const std::string &name, const std::vector<glm::uvec2> &value) const;

            ///
            /// \brief This method should be used to modify a uvec3 uniform array.
            ///
            void    setUniform(const std::string &name, const std::vector<glm::uvec3> &value) const;

            ///
            /// \brief This method should be used to modify a uvec4 uniform array.
            ///
            void    setUniform(const std::string &name, const std::vector<glm::uvec4> &value) const;

            ///
            /// \brief This method should be used to modify a mat2 uniform.
            ///
            void    setUniform(const std::string &name, const glm::mat2 &value) const;

            ///
            /// \brief This method should be used to modify a mat3 uniform.
            ///
            void    setUniform(const std::string &name, const glm::mat3 &value) const;

            ///
            /// \brief This method should be used to modify a mat4 uniform.
            ///
            void    setUniform(const std::string &name, const glm::mat4 &value) const;

            ///
            /// \brief This method should be used to modify a mat2x3 uniform.
            ///
            void    setUniform(const std::string &name, const glm::mat2x3 &value) const;

            ///
            /// \brief This method should be used to modify a mat3x2 uniform.
            ///
            void    setUniform(const std::string &name, const glm::mat3x2 &value) const;

            ///
            /// \brief This method should be used to modify a mat2x4 uniform.
            ///
            void    setUniform(const std::string &name, const glm::mat2x4 &value) const;

            ///
            /// \brief This method should be used to modify a mat4x2 uniform.
            ///
            void    setUniform(const std::string &name, const glm::mat4x2 &value) const;

            ///
            /// \brief This method should be used to modify a mat3x4 uniform.
            ///
            void    setUniform(const std::string &name, const glm::mat3x4 &value) const;

            ///
            /// \brief This method should be used to modify a mat4x3 uniform.
            ///
            void    setUniform(const std::string &name, const glm::mat4x3 &value) const;

            ///
            /// \brief This method should be used to modify a mat2 uniform array.
            ///
            void    setUniform(const std::string &name, const std::vector<glm::mat2> &value) const;

            ///
            /// \brief This method should be used to modify a mat3 uniform array.
            ///
            void    setUniform(const std::string &name, const std::vector<glm::mat3> &value) const;

            ///
            /// \brief This method should be used to modify a mat4 uniform array.
            ///
            void    setUniform(const std::string &name, const std::vector<glm::mat4> &value) const;

            ///
            /// \brief This method should be used to modify a mat2x3 uniform array.
            ///
            void    setUniform(const std::string &name, const std::vector<glm::mat2x3> &value) const;

            ///
            /// \brief This method should be used to modify a mat3x2 uniform.
            ///
            void    setUniform(const std::string &name, const std::vector<glm::mat3x2> &value) const;

            ///
            /// \brief This method should be used to modify a mat4x3 uniform.
            ///
            void    setUniform(const std::string &name, const std::vector<glm::mat2x4> &value) const;

            ///
            /// \brief This method should be used to modify a mat4x3 uniform.
            ///
            void    setUniform(const std::string &name, const std::vector<glm::mat4x2> &value) const;

            ///
            /// \brief This method should be used to modify a mat4x3 uniform.
            ///
            void    setUniform(const std::string &name, const std::vector<glm::mat3x4> &value) const;

            ///
            /// \brief This method should be used to modify a mat4x3 uniform.
            ///
            void    setUniform(const std::string &name, const std::vector<glm::mat4x3> &value) const;

        private:
            ///
            /// \brief This method is used to retrieve a uniform location from the shader program.
            ///
            int     getUniformLocation(const std::string &name);

        protected:
            ///
            /// \brief This attribute is used to store the program id.
            ///
            unsigned int                id;

            ///
            /// \brief This attribute is used to know if the shader program have been compiled.
            ///
            bool                        linked;

    };
}

#endif /* !__ENGINE_SHADER_PROGRAM_HPP__ */
