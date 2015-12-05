#include    "SkyboxRenderer.hpp"

#include    "glwindow.h"

#include    <glm/gtc/type_ptr.hpp>
#include    <QOpenGLShaderProgram>
#include    <IL/il.h>
#include    <IL/ilu.h>
#include    <IL/ilut.h>

#include <iostream>

namespace WorldParticles
{
    namespace Engine
    {

	SkyboxRenderer::SkyboxRenderer(void)
	{
	    ilInit();
	    iluInit();
	    std::vector<const GLchar*> faces;
	    faces.push_back(RESOURCES_PATH "/ely_cloudtop/cloudtop_rt.jpg");
	    faces.push_back(RESOURCES_PATH "/ely_cloudtop/cloudtop_lf.jpg");
	    faces.push_back(RESOURCES_PATH "/ely_cloudtop/cloudtop_up.jpg");
	    faces.push_back(RESOURCES_PATH "/ely_cloudtop/cloudtop_dn.jpg");
	    faces.push_back(RESOURCES_PATH "/ely_cloudtop/cloudtop_bk.jpg");
	    faces.push_back(RESOURCES_PATH "/ely_cloudtop/cloudtop_ft.jpg");
	    _cubemapTexture = LoadCubemap(faces);
	}

	GLuint SkyboxRenderer::LoadCubemap(std::vector<const GLchar*> faces)
	{
	    GLuint textureID;
	    GLWindow::m_funcs->glGenTextures(1, &textureID);
	    GLWindow::m_funcs->glActiveTexture(GL_TEXTURE0);

	    int width,height;

	    GLWindow::m_funcs->glBindTexture(GL_TEXTURE_CUBE_MAP, textureID);
	    for(GLuint i = 0; i < faces.size(); i++)
	    {
		std::cout << "name=" << faces[i] << std::endl;
		ILuint imgId;
		ilGenImages(1, &imgId);
	        ilBindImage(imgId);
		if (!ilLoadImage(faces[i])) {
		    ILenum err = ilGetError();
		    if (err == ILUT_NOT_SUPPORTED || err == IL_FORMAT_NOT_SUPPORTED) {
			std::cout << "format not supported" << std::endl;
		    } else if (err == IL_OUT_OF_MEMORY || err == ILU_OUT_OF_MEMORY || err == ILUT_OUT_OF_MEMORY) {
			std::cout << "memory error" << std::endl;
		    } else if (err == IL_INVALID_VALUE || err == ILU_INVALID_VALUE || err == ILUT_INVALID_VALUE) {
			std::cout << "invalid parameter" << std::endl;
		    } else if (err == IL_LIB_JPEG_ERROR || err == IL_LIB_PNG_ERROR) {
			std::cout << "lib error" << std::endl;
		    } else if (err == IL_INVALID_FILE_HEADER) {
			std::cout << "file header incorrect" << std::endl;
		    } else if (err == IL_COULD_NOT_OPEN_FILE || err == ILUT_COULD_NOT_OPEN_FILE) {
			std::cout << "could not open file" << std::endl;
		    } else if (err == IL_INVALID_EXTENSION) {
			std::cout << "invalid extension" << std::endl;
		    } else if (err == IL_INTERNAL_ERROR || err == ILU_INTERNAL_ERROR) {
			std::cout << "internal error" << std::endl;
		    } else if (err == IL_ILLEGAL_OPERATION || err == ILU_ILLEGAL_OPERATION || err == ILUT_ILLEGAL_OPERATION) {
			std::cout << "illegal operation" << std::endl;
		    } else if (err == IL_ILLEGAL_FILE_VALUE) {
			std::cout << "illegal file value" << std::endl;
		    } else {
			std::cout << "problems" << std::endl;
		    }
		}
		width = ilGetInteger(IL_IMAGE_WIDTH);
		height = ilGetInteger(IL_IMAGE_HEIGHT);
		GLWindow::m_funcs->glTexImage2D(
			GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0,
			GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, ilGetData()
			);
		ilDeleteImage(imgId);
	    }
	    GLWindow::m_funcs->glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	    GLWindow::m_funcs->glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	    GLWindow::m_funcs->glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	    GLWindow::m_funcs->glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	    GLWindow::m_funcs->glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
	    GLWindow::m_funcs->glBindTexture(GL_TEXTURE_CUBE_MAP, 0);

	    return textureID;
	}

	SkyboxRenderer::~SkyboxRenderer(void)
	{
	}

	void    SkyboxRenderer::Draw(const Mesh &mesh,
		Material &material,
		const glm::mat4 &projection,
		const glm::mat4 &view,
		const glm::mat4 &model)
	{
	    GLWindow::m_funcs->glDepthMask (GL_FALSE);
	    const std::vector<glm::vec3> &vertices = mesh.GetVertices();
	    QOpenGLShaderProgram shaderProgram;


	    shaderProgram.addShaderFromSourceFile(QOpenGLShader::Vertex, RESOURCES_PATH "/shaders/skybox.vert");
	    shaderProgram.addShaderFromSourceFile(QOpenGLShader::Fragment, RESOURCES_PATH "/shaders/skybox.frag");
	    shaderProgram.link();
	    shaderProgram.create();

	    shaderProgram.bind();

	    glm::mat4 MVP = projection * view * model;

	    int location = shaderProgram.uniformLocation("V");
	    shaderProgram.setUniformValue(location, QMatrix4x4(&view[0][0]).transposed());
	    location = shaderProgram.uniformLocation("P");
	    shaderProgram.setUniformValue(location, QMatrix4x4(&projection[0][0]).transposed());

	    GLuint vbo;
	    GLWindow::m_funcs->glGenBuffers(1, &vbo);
	    GLWindow::m_funcs->glBindBuffer(GL_ARRAY_BUFFER, vbo);
	    GLWindow::m_funcs->glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), vertices.data(), GL_STATIC_DRAW);

	    GLWindow::m_funcs->glEnableVertexAttribArray(0);
	    GLWindow::m_funcs->glBindBuffer(GL_ARRAY_BUFFER, vbo);
	    GLWindow::m_funcs->glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void *)0);
	    GLWindow::m_funcs->glBindTexture(GL_TEXTURE_CUBE_MAP, _cubemapTexture);

	    GLWindow::m_funcs->glDrawArrays(GL_TRIANGLES, 0, 3*vertices.size());
	    GLWindow::m_funcs->glDisableVertexAttribArray(0);
	    GLWindow::m_funcs->glDepthMask (GL_TRUE);
	}
    }
}
