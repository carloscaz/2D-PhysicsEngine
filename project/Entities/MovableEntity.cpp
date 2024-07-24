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

Vector3D MovableEntity::GetAcceleration() const
{
    return m_acceleration;
}

float MovableEntity::GetMass() const
{
    return m_mass;
}

void MovableEntity::SetVelocity(const Vector3D& _vel)
{
    m_velocity = _vel;
}

void MovableEntity::SetAcceleration(const Vector3D& _acceleration)
{
    m_acceleration = _acceleration;
}

void MovableEntity::AddForce(const Vector3D& _force)
{
    m_force += _force;
}

void MovableEntity::SetLifetime(float _lifetime)
{
    m_lifetime = _lifetime;
}
