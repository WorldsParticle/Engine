#include <GL/glew.h>
#include <GL/gl.h>
#include "material.hh"

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

Material::Material() : _shaderProgram(0) {
    std::cout << "------------> created Material:" << this << std::endl;
    _uTextureAmount.get() = 0;
}

void Material::addShader(GLenum type_, const std::string& filename_) noexcept {
    _shaders.emplace_back(type_, filename_);
}

void Material::link() noexcept {
    if (!_shaderProgram) {
	glDeleteProgram(_shaderProgram);
    }
    _shaderProgram = glCreateProgram();
    for (Shader& s : _shaders) {
	if (!s.getCompileStatus()) {
	    std::cout << "\033[33m warning: not compiled shader found\033[0m" << std::endl;
	}
	glAttachShader(_shaderProgram, s.getId());
    }
    glLinkProgram(_shaderProgram);

    GLint linkStatus;
    glGetProgramiv(_shaderProgram, GL_LINK_STATUS, &linkStatus);
    if (linkStatus != GL_TRUE) {
	GLint InfoLogLength;
	glGetProgramiv(_shaderProgram, GL_INFO_LOG_LENGTH, &InfoLogLength);
	char ErrorMessage[InfoLogLength];
	glGetProgramInfoLog(_shaderProgram, InfoLogLength, NULL, ErrorMessage);
	std::cout << "\033[0;31mfailed to link error log: " << std::endl << ErrorMessage << std::endl << "-------------------\033[0m" << std::endl;
    } else {
	std::cout << "\033[32msuccessfully linked\033[0m" << std::endl;
    }

    _uTextureAmount.__manual_Location_setting__(8);
    _samplerArrayLocation = glGetUniformLocation(_shaderProgram, "tex");
    std::cout << "-----------> created program: " << _shaderProgram << std::endl;
}

void Material::use() const noexcept {
    if (!_shaderProgram) {
	std::cout << "shader not compiled" << std::endl;
	return;
    }
    glUseProgram(_shaderProgram);
    _uTextureAmount.upload();
    if (_textures.size() != _uTextureAmount.get()) {
	std::cout << "program id: " << _shaderProgram << std::endl;
	std::cout << "\033[31;1m_texture.size() = " << _textures.size() << " != uniform TextureAmount = " << _uTextureAmount.get() << "\e[0m" << std::endl;
	return;
    }
    unsigned int i = 0;
    for (decltype(_textures)::value_type t : _textures) {
	t->bind(GL_TEXTURE0 + i);
        glUniform1i(glGetUniformLocation(_shaderProgram, _StexStringArray_[i]), i);
	++i;
    }
}

decltype(Material::_textures)::const_iterator Material::addTexture(Texture* t_) {
    GLint maxTex;
    glGetIntegerv(GL_MAX_TEXTURE_UNITS, &maxTex);
    if ((int)_textures.size() > maxTex) {
	std::cout << "\e[33myou are exeeding the maximum amout of textures:" << maxTex << "\e[0m" << std::endl;
    }
    _textures.push_back(t_);
    _uTextureAmount.get() = _textures.size();
    return _textures.end()--;
}

void Material::excludeTexture(decltype(_textures)::iterator iterator_) {
    _textures.erase(iterator_);
}

decltype(Material::_textures)& Material::getTextureList() {
    return _textures;
}

Material::~Material() {
    for (Shader& s: _shaders) {
	glDeleteShader(s.getId());
    }
}
