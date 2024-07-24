#include "Ball.h"

#include "../../Components/CollisionComponent/CollisionComponent.h"

Ball::Ball()
{
}

float Ball::GetRadius()
{
    return m_radius;
}

float Ball::GetRestitution()
{
    return m_restitutionCoefficient;
}

void Ball::SetRadius(float _radius)
{
    m_radius = _radius;
}

void Ball::SetGravity(bool _value)
{
    m_gravity = _value;
}

void Ball::Tick(float _deltaTime)
{
    m_force = Vector3D(0,0,0);
    for (Component* component : m_components)
    {
        component->Tick();
    }
    
    m_acceleration = m_force / m_mass;
    m_velocity += m_acceleration * _deltaTime;
    Vector3D newPos = m_position + (m_velocity * _deltaTime);
    m_position = newPos;

    // if(m_active)
    // {

        // if(m_gravity)
        // {
        //     m_velocity += m_acceleration * _deltaTime;
        // }
        // Vector3D newPos = m_position + (m_velocity * _deltaTime);
        // m_position = newPos;
        //
        //
        // m_lifetime -= 1.0f * _deltaTime;
        // if(m_lifetime <= 0.0f)
        // {
        //     m_active = false;
        // }
    //}
}

void Ball::Draw()
{
    if(m_active)
    {
        Entity::Draw();
    }
}
