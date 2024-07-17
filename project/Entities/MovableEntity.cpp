#include "MovableEntity.h"

MovableEntity::MovableEntity()
{
    m_velocity = Vector3D(0,0,0);
    m_acceleration = Vector3D(0,0,0);
}

void MovableEntity::Init()
{
}

void MovableEntity::Tick(float _deltaTime)
{
}

float MovableEntity::GetLifetime() const
{
    return m_lifetime;
}

Vector3D MovableEntity::GetVelocity() const
{
    return m_velocity;
}

void MovableEntity::SetVelocity(const Vector3D& _vel)
{
    m_velocity = _vel;
}

void MovableEntity::SetAcceleration(const Vector3D& _acceleration)
{
    m_acceleration = _acceleration;
}

void MovableEntity::SetLifetime(float _lifetime)
{
    m_lifetime = _lifetime;
}
