#include "Particle.h"

#include <random>

#include "../../OpenGL/Shaders/Shader.h"
#include "GL/glew.h"
#include "../glm/glm.hpp"
#include "../glm/gtc/type_ptr.hpp"
#include "../../src/Vertex/Vertex.h"
#include "../../OpenGL/Buffer/Buffer.h"

Particle::Particle()
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
    
    Init();
    
}

void Particle::Init()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> lifetimeValue(1.0f, 5.0f);
    std::uniform_real_distribution<> velocityValue(-1.0f, 1.0f);
    
    m_lifetime = lifetimeValue(gen);
    m_position = m_initPos;
    m_velocity = Vector3D(velocityValue(gen) * 300, velocityValue(gen) * 300, 0);
}

void Particle::Tick(float _deltaTime)
{
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
        if((m_position.Y>= 600))
        {
            Vector3D vr = m_velocity; //Relative velocity normalized of the ball with the ground
            Vector3D vn = Vector3D(0, 1, 0); //Normal vector of the ground
            
            if(Vector3D::DotProduct(vr.Normalize(), vn) >= 0) //Check the direction of the ball
            {
                m_velocity = (Vector3D(vr.X,  vr.Y * -0.5f, 0));
            }
        }
    }

}

void Particle::Draw()
{
    if(m_active)
    {
        glBindVertexArray(GetBuffer()->GetBufferVAO());
        Entity::Draw();
    }
}

void Particle::SetVelocity(const Vector3D& _vel)
{
    m_velocity = _vel;
}

void Particle::SetInitPos(const Vector3D& _initPos)
{
    m_initPos = _initPos;
}

void Particle::SetInitVelocity(const Vector3D& _initVelocity)
{
    m_initVelocity = _initVelocity;
}

void Particle::setAcceleration(const Vector3D& _acceleration)
{
    m_acceleration = _acceleration;
}

void Particle::checkCollisions(bool _value)
{
    m_collisions = _value;
}
