#include "Entity.h"

#include <cstddef>
#include "../OpenGL/Textures/Texture.h"
#include "../../src/Vertex/Vertex.h"
#include "../OpenGL/Buffer/Buffer.h"
#include "../OpenGL/Shaders/Shader.h"
#include "GL/glew.h"
#include "../../lib/glfw/glfw3.h"
#include "../OpenGL/State/State.h"
#include <iostream>

Entity::Entity()
{
    m_position = Vector3D(400.0f, 300.0f, 0.0f);
    m_rotation = Vector3D(0.0f, 0.0f, 0.0f);
    m_scale = Vector3D(50.0f, 50.0f, 50.0f);

    Vertex vertices[] =
    {
        Vertex(Vector3D(0.5f, 0.5f, 0.0f), Vector2D(1.0f, 1.0f)),
        Vertex(Vector3D(0.5f, 0.0f, 0.0f), Vector2D(1.0f, 0.0f)),
        Vertex(Vector3D(0.0f, 0.0f, 0.0f), Vector2D(0.0f, 0.0f)),
        Vertex(Vector3D(0.0f, 0.5f, 0.0f), Vector2D(0.0f, 1.0f))
    };

    unsigned int indices[]
    {
        0, 1, 3,
        1, 2, 3
    };


    m_buffer = new Buffer(vertices, indices, sizeof(vertices), sizeof(indices));
    //m_shader = Shader::Load("data/SpriteShader/vertex.glsl", "data/SpriteShader/fragment.glsl");
}

void Entity::SetTexture(const char* _filename)
{
    m_texture = Texture::Load(_filename);

    unsigned int texSamplerLoc = glGetUniformLocation(m_shader->GetId(), "tex");
    if(texSamplerLoc != -1)
    {
        glUniform1i(texSamplerLoc, 0);
    }
    
    GLuint textureLoc = glGetAttribLocation(m_shader->GetId(), "vTex");
    if (textureLoc != -1)
    {
        glEnableVertexAttribArray(textureLoc);
        glVertexAttribPointer(textureLoc, 2, GL_FLOAT, false, sizeof(Vertex), reinterpret_cast<const void*>(offsetof(Vertex, m_tex)));
    }
    
    SetScale(Vector3D(m_texture->GetTextureData().texWidth * 4, m_texture->GetTextureData().texHeight  * 4, 1));
    //glActiveTexture(GL_TEXTURE0);

}

void Entity::SetPosition(const Vector3D& _pos)
{
    m_position = _pos;
}

void Entity::SetRotation(const Vector3D& _rotation)
{
    m_rotation = _rotation;
}

void Entity::SetScale(const Vector3D& _scale)
{
    m_scale = _scale;
}

void Entity::SetWindow(GLFWwindow* _win)
{
    if(m_window)
    {
        m_window = _win;
    }
}

void Entity::SetShader(Shader* _shader)
{
    m_shader = _shader;
}

Texture* Entity::GetTexture()
{
    return m_texture;
}

void Entity::Tick(float _deltaTime)
{
}

void Entity::Draw()
{
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glBindTexture(GL_TEXTURE_2D, m_texture->tex);

    m_shader->SetMatrix(m_position, m_scale);
    m_buffer->Draw(m_shader, DrawModes::TRIANGLES);
}



