#include "Ball.h"

#include "../../Components/CollisionComponent/CollisionComponent.h"

Ball::Ball()
{
    CollisionComponent* collider = new CollisionComponent(this);
    m_components.push_back(collider);
    collider->SetOwner(this);

    m_lifetime = 10.0f;
}

Vector3D Ball::GetVelocity()
{
    return m_velocity;
}

float Ball::GetRadius()
{
    return m_radius;
}

float Ball::GetRestitution()
{
    return m_restitutionCoefficient;
}

void Ball::SetVelocity(const Vector3D& _velocity)
{
    m_velocity = _velocity;
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

    m_velocity += m_acceleration * _deltaTime;
    Vector3D newPos = m_position + (m_velocity * _deltaTime);
    m_position = newPos;
    // if(m_active)
    // {
    //     for (Component* component : m_components)
    //     {
    //         component->Tick();
    //     }
    //     if(m_gravity)
    //     {
    //         m_velocity += m_acceleration * _deltaTime;
    //     }
    //     Vector3D newPos = m_position + (m_velocity * _deltaTime);
    //     m_position = newPos;
    //
    //
    //     m_lifetime -= 1.0f * _deltaTime;
    //     if(m_lifetime <= 0.0f)
    //     {
    //         m_active = false;
    //     }
    // }
}

void Ball::Draw()
{
    if(m_active)
    {
        Entity::Draw();
    }
}
