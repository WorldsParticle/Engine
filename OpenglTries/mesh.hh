#ifndef MESH_H_
# define MESH_H_

#include "GPUBuffer.hh"
#include "material.hh"

class Mesh {
    private:
	Material& _material;
	GPUBuffer _gb;
	GLuint _vertexArray;

	void _getAllFaces(const struct aiScene *sc, const struct aiNode*);
    public:
	explicit Mesh(Material&);
	void set(const GPUBuffer&)noexcept;
	void fromFile(const std::string&);
	void setMaterial(Material& m_) { _material = m_; }
	void render() const noexcept;
	void uploadBuffer() noexcept;
	~Mesh();
};

#endif /* !MESH_H_ */
