#include "Ball.h"

#include "../../Components/CollisionComponent/CollisionComponent.h"

Ball::Ball()
{
    CollisionComponent* collider = new CollisionComponent();
    m_components.push_back(collider);
    collider->SetOwner(this);
}

Vector3D Ball::GetVelocity()
{
    return m_velocity;
}

float Ball::GetRadius()
{
    return m_radius;
}

void Ball::SetVelocity(const Vector3D& _velocity)
{
    m_velocity = _velocity;
}

void Ball::SetRadius(float _radius)
{
    m_radius = _radius;
}

void Ball::Tick(float _deltaTime)
{
    for (Component* component : m_components)
    {
        component->Tick();
    }
    Vector3D newPos = m_position + (m_velocity * _deltaTime);
    m_position = newPos;
    
}
