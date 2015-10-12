#pragma once

#include <vector>
#include <string>
#include <array>
#include <QOpenGLContext>
#include <QOpenGLShaderProgram>
#include <QOpenGLShader>
//#include <uniform.hh>
#include "texture.hh"

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
	void addShader(QOpenGLShader::ShaderType, const QString&) noexcept;
	void link() noexcept;
	void use() noexcept;
	void compileAll()noexcept;
	decltype(_textures)::const_iterator addTexture(Texture*);
	void excludeTexture(decltype(_textures)::iterator);
	inline decltype(_textures)& getTextureList();
	Material& operator=(const Material&);
};