#include "Buffer.h"

#include <cstddef>

#include "../../../src/Vertex/Vertex.h"
#include "../../project/OpenGL/Shaders/Shader.h"
#include "GL/glew.h"
#include "../glm/gtc/type_ptr.hpp"


Buffer::Buffer(Vertex _vertices[], unsigned int _elements[], unsigned int _verticesSize, unsigned int _indicesSize)
    :
    sizeIndices(_indicesSize),
    sizeVertices(_verticesSize)
{
    //Generation of the buffers
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    glGenVertexArrays(1, &VAO);

    //Bind buffers
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

    //Update Buffers with data
    glBufferData(GL_ARRAY_BUFFER, sizeVertices, _vertices, GL_STATIC_DRAW);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeIndices, _elements, GL_STATIC_DRAW);

    //Configure AttribPointers
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*) offsetof(Vertex, m_pos));
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*) offsetof(Vertex, m_color));
    glEnableVertexAttribArray(1);
    
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*) offsetof(Vertex, m_tex));
    glEnableVertexAttribArray(2);
}

void Buffer::Draw(Shader* _shader)
{
    glUseProgram(_shader->GetId());
    glDrawElements(GL_TRIANGLES, sizeIndices, GL_UNSIGNED_INT, 0);
}

void Buffer::Draw(Shader* _shader, DrawModes _mode)
{
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    switch(_mode)
    {
    case DrawModes::TRIANGLES:
        
        glDrawElements(GL_TRIANGLES, sizeIndices, GL_UNSIGNED_INT, 0);
        break;

    case DrawModes::LINES:
        glDrawElements(GL_LINES, sizeIndices, GL_UNSIGNED_INT, 0);
        break;

    case DrawModes::POINTS:
        glDrawElements(GL_POINTS, sizeIndices, GL_UNSIGNED_INT, 0);
        break;
        
    default:
        break;
    }
}

unsigned int Buffer::GetBufferVAO()
{
    return VAO;
}
