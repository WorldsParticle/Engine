#ifndef     __MATERIAL_HPP__
# define    __MATERIAL_HPP__

#include    <glm/glm.hpp>
#include    <QOpenGLShaderProgram>

class   Material
{
public:
    Material(void)
    {

    }

    ~Material(void)
    {

    }

public:

    ///
    /// \brief GetColor
    /// \return
    ///
    const glm::vec3 &GetColor(void) const
    {
        return this->color;
    }

    QOpenGLShaderProgram    &GetShaderProgram(void)
    {
        return this->shaderProgram;
    }

private:
    glm::vec3   color;
    QOpenGLShaderProgram    shaderProgram;
    // program shader
    // Texture
};

#endif /* !__MATERIAL_HPP__ */
