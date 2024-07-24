#pragma once
#include "Entity.h"

class MovableEntity : public Entity
{
protected:
    float m_lifetime;
    
    Vector3D m_velocity;
    Vector3D m_acceleration = Vector3D(0,0,0);
    Vector3D m_force = Vector3D(0,0,0);

    float m_mass = 1.0f;
public:
    MovableEntity();

    virtual void Init() override;
    virtual void Tick(float _deltaTime) override;
    
    float GetLifetime() const;
    Vector3D GetVelocity() const;
    Vector3D GetAcceleration() const;
    Vector3D GetForce() const;
    float GetMass() const;

    
    void SetVelocity(const Vector3D& _vel);
    void SetAcceleration(const Vector3D& _acceleration);
    void AddForce(const Vector3D& _force);
    void SetLifetime(float _lifetime);
    
    
};
