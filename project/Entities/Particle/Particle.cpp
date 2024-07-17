#include "Particle.h"

#include <random>

#include "../../OpenGL/Shaders/Shader.h"
#include "GL/glew.h"
#include "../glm/glm.hpp"
#include "../glm/gtc/type_ptr.hpp"
#include "../../src/Vertex/Vertex.h"
#include "../../OpenGL/Buffer/Buffer.h"

Particle::Particle(float _minVelocityX, float _maxVelocityX, float _minVelocityY, float _maxVelocityY)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> colorValue(0.0f, 1.0f);
    float cRed = colorValue(gen);
    float cGreen = colorValue(gen);
    float cBlue = colorValue(gen);
    Vertex vertices[] =
    {
        Vertex(Vector3D(0.5f, 0.5f, 0.0f), Vector2D(1.0f, 1.0f), Vector3D(cRed,cGreen,cBlue)),
        Vertex(Vector3D(0.5f, 0.0f, 0.0f), Vector2D(1.0f, 0.0f), Vector3D(cRed,cGreen,cBlue)),
        Vertex(Vector3D(0.0f, 0.0f, 0.0f), Vector2D(0.0f, 0.0f), Vector3D(cRed,cGreen,cBlue)),
        Vertex(Vector3D(0.0f, 0.5f, 0.0f), Vector2D(0.0f, 1.0f), Vector3D(cRed,cGreen,cBlue))
    };
    
    unsigned int indices[]
    {
        0, 1, 3,
        1, 2, 3
    };
    
    m_buffer = new Buffer(vertices, indices, sizeof(vertices), sizeof(indices));
    AddComponent(new CollisionComponent(this));

    m_minVelocityX = _minVelocityX;
    m_maxVelocityX = _maxVelocityX;
    m_minVelocityY = _minVelocityY;
    m_maxVelocityY = _maxVelocityY;
    
    Init();
    
}

void Particle::Init()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> lifetimeValue(1.0f, 5.0f);
    std::uniform_real_distribution<> velocityValueX(m_minVelocityX, m_maxVelocityX);
    std::uniform_real_distribution<> velocityValueY(m_minVelocityY, m_maxVelocityY);

    float value = velocityValueX(gen);
    
    m_lifetime = lifetimeValue(gen);
    m_position = m_initPos;
    m_velocity = Vector3D(velocityValueX(gen) * 300, velocityValueY(gen) * 300, 0);
    m_force = Vector3D(0,980,0);
}

void Particle::Tick(float _deltaTime)
{
    m_acceleration = m_force;
    m_velocity += m_acceleration * _deltaTime;
    Vector3D newPos = m_position + (m_velocity * _deltaTime);
    m_position = newPos;
    
    m_lifetime -= 1 * _deltaTime;
    if(m_lifetime <= 0)
    {
        Init(); //Reset particle properties
        
    }

    if(m_collisions)
    {
        for (Component* comp : m_components)
        {
            comp->Tick();
        }
    }

    m_force = Vector3D(0,980,0);

}

void Particle::Draw()
{
    if(m_active)
    {
        glBindVertexArray(GetBuffer()->GetBufferVAO());
        Entity::Draw();
    }
}



void Particle::SetInitPos(const Vector3D& _initPos)
{
    m_initPos = _initPos;
}

void Particle::SetInitVelocity(const Vector3D& _initVelocity)
{
    m_initVelocity = _initVelocity;
}

void Particle::AddForce(const Vector3D& _force)
{
    m_force += _force;
}

void Particle::SetForce(const Vector3D& _force)
{
    m_force = _force;
}


void Particle::checkCollisions(bool _value)
{
    m_collisions = _value;
}
