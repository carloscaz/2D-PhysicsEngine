#include "Player.h"
#include "../../project/OpenGL/Buffer/Buffer.h"
#include "../../project/OpenGL/Shaders/Shader.h"
#include "../../project/OpenGL/Textures/Texture.h"
#include "../../src/Vertex/Vertex.h"
#include "../../project/Entities/World.h"
#include "../glm/glm.hpp"
#include "../glm/gtc/matrix_transform.hpp"
#include "../glm/gtc/type_ptr.hpp"
#include <iostream>

Player::Player()
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
}

const Vector3D& Player::GetPosition() const
{
    return m_position;
}

const Vector3D& Player::GetVelocity() const
{
    return m_velocity;
}

void Player::SetPosition(const Vector3D& _pos)
{
    m_position = _pos;
}

void Player::SetVelocity(const Vector3D& _vel)
{
    m_velocity = _vel;
}

void Player::SetWindow(GLFWwindow* _win)
{
    m_window = _win;
    glfwSetWindowUserPointer(_win, this);
    //glfwSetKeyCallback(_win, key_callback);
}

void Player::Tick(float _deltaTime)
{
    int test = m_texture->GetTextureData().texWidth / 2;
    if (glfwGetKey(m_window, GLFW_KEY_D) && (m_position.X < 800))
    {
        m_position.X += m_velocity.X * World::GetInstance()->GetDeltaTime();
    }
    
    else if (glfwGetKey(m_window, GLFW_KEY_A) && m_position.X > 0)
    {
        m_position.X -= m_velocity.X * World::GetInstance()->GetDeltaTime();
    }

    else if (glfwGetKey(m_window, GLFW_KEY_W) && ((m_position.Y) > 0))
    {
        m_position.Y -= m_velocity.Y * World::GetInstance()->GetDeltaTime();
    }

    else if (glfwGetKey(m_window, GLFW_KEY_S) && (m_position.Y < 600))
    {
        m_position.Y += m_velocity.Y * World::GetInstance()->GetDeltaTime();
    }


    m_elapsedTime += _deltaTime;
    float frameStep = 1 / m_fps;
    if(m_elapsedTime > frameStep)
    {
        ++m_currentFrame;
        if(m_currentFrame >= m_numFrames)
        {
            m_currentFrame = 0;
        }
    
        m_elapsedTime -= frameStep;
    }
}

void Player::Draw()
{
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glBindTexture(GL_TEXTURE_2D, m_texture->tex);

    m_shader->SetMatrix(m_position, m_scale);
    glUniform1i(glGetUniformLocation(m_shader->GetId(), "frameIndex"), m_currentFrame);
    glUniform2f(glGetUniformLocation(m_shader->GetId(), "frameSize"), 0.25f, 1.0f);
    m_buffer->Draw(m_shader, DrawModes::TRIANGLES);
}

void Player::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    Player* player = static_cast<Player*>(glfwGetWindowUserPointer(window));
    if (player)
    {
        if (key == GLFW_KEY_A && action == GLFW_REPEAT)
        {
            player->m_position.X--;
        };
    }
}
