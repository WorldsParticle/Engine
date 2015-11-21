#include <iostream>
#include "material.hh"

//TODO clean proprement le _shaders

const char* const Material::_StexStringArray_[16] = {
    "tex[0]",
    "tex[1]",
    "tex[2]",
    "tex[3]",
    "tex[4]",
    "tex[5]",
    "tex[7]",
    "tex[8]",
    "tex[9]",
    "tex[10]",
    "tex[11]",
    "tex[12]",
    "tex[13]",
    "tex[14]",
    "tex[15]",
};

Material::Material() : _uTextureAmount(0), _sProgram(QOpenGLContext::currentContext()) {
    std::cout << "------------> created Material:" << this << std::endl;
    _uTextureAmountValue = 0;
}

void Material::addShader(QOpenGLShader::ShaderType type_, const QString& filename_) {
    _shaders.push_back(new QOpenGLShader(type_));
    _shaders.back()->compileSourceFile(filename_);
}

void Material::uploadMVP(Camera const &cam) {
    QMatrix4x4 matrix;

    matrix.translate(cam.eye.x(), cam.eye.y(), cam.eye.z());
    _sProgram.setUniformValue("camera", cam.eye);
    _sProgram.setUniformValue("model", matrix);
}

void Material::link()
{
    if (_sProgram.isLinked()) {
	std::cout << "previously removed stuff" << std::endl;
	_sProgram.release();
	//QOpenGLContext::currentContext()->functions()->glDeleteProgram(_sProgram.programId());
    }
    _sProgram.create();
    for (QOpenGLShader* s : _shaders) {
        if (!s->isCompiled()) {
            std::cout << "\033[33m warning: not compiled shader found\033[0m" << std::endl;
        }
        _sProgram.addShader(s);
    }
    if (!_sProgram.link()) {
	std::cout << "\033[0;31mfailed to link error log: " << std::endl;
	std::cout << _sProgram.log().toStdString() << std::endl << "-------------------\033[0m" << std::endl;
    } else {
	std::cout << "\033[32msuccessfully linked\033[0m" << std::endl;
	_uTextureAmount = _sProgram.uniformLocation("textureAmount");
        _sProgram.setUniformValue(_uTextureAmount, _uTextureAmountValue);
    }
    std::cout << "-----------> created program: " << _sProgram.programId() << std::endl;
}

Material& Material::operator=(const Material& m) {

	_uTextureAmount = m._uTextureAmount;
    _uTextureAmountValue = m._uTextureAmountValue;
    _sProgram.setUniformValue(_uTextureAmount, _uTextureAmountValue);
    _sProgram.removeAllShaders();
    _shaders.clear();

	for (QOpenGLShader *s : m._shaders) {
		_shaders.push_back(new QOpenGLShader(s->shaderType()));
		_shaders.back()->compileSourceCode(s->sourceCode());
    }
    _textures = m._textures;

    if (!_sProgram.link()) {
		std::cout << "\033[0;31mfailed to link error log: " << std::endl;
		std::cout << _sProgram.log().toStdString() << std::endl << "-------------------\033[0m" << std::endl;
    } else {
		std::cout << "\033[32msuccessfully linked\033[0m" << std::endl;
    }
    std::cout << "-----------> created program: " << _sProgram.programId() << std::endl;

	return *this;
}

void Material::use()
{
    if (!_sProgram.isLinked()) {
	std::cout << "shader not compiled" << std::endl;
	return;
    }
    _sProgram.bind();
    _sProgram.setUniformValue(_uTextureAmount, _uTextureAmountValue);
    if (_textures.size() != _uTextureAmountValue) {
	std::cout << "program id: " << _sProgram.programId() << std::endl;
	std::cout << "\033[31;1m_texture.size() = " << _textures.size() << " != uniform TextureAmount = " << _uTextureAmountValue << "\e[0m" << std::endl;
	return;
    }
    unsigned int i = 0;
	for (std::vector<const Texture*>::value_type t : _textures) {
	t->bind(GL_TEXTURE0 + i);
        _sProgram.setUniformValue(_sProgram.uniformLocation(_StexStringArray_[i]), i);
	++i;
    }
}

std::vector<const Texture*>::const_iterator Material::addTexture(Texture* t_) {
    GLint maxTex = 10;
    QOpenGLContext::currentContext()->functions()->glGetIntegerv(GL_MAX_TEXTURE_UNITS, &maxTex);
    if ((int)_textures.size() > maxTex) {
	std::cout << "\e[33myou are exeeding the maximum amout of textures:" << maxTex << "\e[0m" << std::endl;
    }
    if (!t_->isLoaded()) {
	t_->load();
    }
    _textures.push_back(t_);
    _uTextureAmountValue = _textures.size();
    _sProgram.setUniformValue(_uTextureAmount, _uTextureAmountValue);
    return _textures.end()--;
}

void Material::excludeTexture(std::vector<const Texture*>::iterator iterator_) {
    _textures.erase(iterator_);
}

decltype(Material::_textures)& Material::getTextureList() {
    return _textures;
}

Material::~Material() {
    _sProgram.removeAllShaders();
    /*for (Shader& s: _shaders) {
	QOpenGLContext::currentContext()->functions()->glDeleteShader(s.shaderId());
    }*/
}
