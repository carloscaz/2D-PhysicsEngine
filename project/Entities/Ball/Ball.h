#pragma once
#include "../MovableEntity.h"

class Ball : public MovableEntity
{
private:
    Vector3D m_velocity;
    Vector3D m_acceleration = Vector3D(0,0,0);
    float m_radius;
    const float m_restitutionCoefficient = 0.85f;

    bool m_gravity = false;
public:
    Ball();
    
    float GetRadius();
    float GetRestitution();
    
    void SetVelocity(const Vector3D& _velocity);
    void SetRadius(float _radius);
    void SetGravity(bool _value);
    
    void Tick(float _deltaTime) override;
    void Draw() override;
    
};
