#pragma once
#include <vector>

#include "../../project/OpenGL/Utils/GL_Utils.h"
class Shader;
class Vertex;

class Buffer
{
private:
    unsigned int VBO, EBO, VAO;
    unsigned int sizeIndices = 0;
    unsigned int sizeVertices = 0;
public:
    Buffer(Vertex _vertices[], unsigned int _elements[], unsigned int _verticesSize, unsigned int _indicesSize);
    Buffer(std::vector<Vertex> vertices, std::vector<unsigned int> _indices);
    void Draw(Shader* _shader);
    void Draw(Shader* _shader, DrawModes _mode);

    unsigned int GetBufferVAO();
};
