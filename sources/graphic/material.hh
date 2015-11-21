#pragma once

#include <vector>
#include <string>
#include <array>
#include <QOpenGLContext>
#include <QOpenGLShaderProgram>
#include <QOpenGLShader>
#include "texture.hh"
#include "camera.h"

class Material {
    private:
	static const char* const _StexStringArray_[16];
	//Uniform<unsigned int> _uTextureAmount;
	unsigned int _uTextureAmount;
	unsigned int _uTextureAmountValue;
	QOpenGLShaderProgram _sProgram;
	std::vector<QOpenGLShader*> _shaders;
	std::vector<const Texture*> _textures;
    public:
	Material();
	~Material();
	void addShader(QOpenGLShader::ShaderType, const QString&);
	void uploadMVP(Camera const &cam);
	void link();
	void use();
	void compileAll();
	std::vector<const Texture*>::const_iterator addTexture(Texture*);
	void excludeTexture(std::vector<const Texture*>::iterator);
	inline decltype(_textures)& getTextureList();
	Material& operator=(const Material&);
};
