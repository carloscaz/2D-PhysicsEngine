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

    //Entity vertex creation
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
}

void Entity::SetTexture(const char* _filename)
{
    m_texture = Texture::Load(_filename);

    unsigned int texSamplerLoc = glGetUniformLocation(m_shader->GetId(), "tex");
    if(texSamplerLoc != -1)
    {
        glUniform1i(texSamplerLoc, 0);
    }
    
    SetScale(Vector3D(m_texture->GetTextureData().texWidth * 4, m_texture->GetTextureData().texHeight  * 4, 1));

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

Vector3D Entity::GetPosition()
{
    return m_position;
}

Vector3D Entity::GetScale()
{
    return m_scale;
}

bool Entity::GetActive()
{
    return m_active;
}

void Entity::AddComponent(Component* _component)
{
    m_components.push_back(_component);
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

Texture* Entity::GetTexture() const
{
    return m_texture;
}

Buffer* Entity::GetBuffer() const
{
    return m_buffer;
}

void Entity::Tick(float _deltaTime)
{
}

void Entity::Draw()
{
    //Configure OpenGl with texture
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glBindTexture(GL_TEXTURE_2D, m_texture->tex);

    //Set MVP matrix
    m_shader->SetMatrix(m_position, m_scale);

    //Draw entity
    m_buffer->Draw(m_shader, DrawModes::TRIANGLES);
}



