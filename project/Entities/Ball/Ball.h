#pragma once
#include "../Entity.h"

class Ball : public Entity
{
private:
    Vector3D m_velocity;
    Vector3D m_acceleration = Vector3D(0,980.0f,0);
    float m_radius;
    const float m_restitutionCoefficient = 0.85f;

    bool m_gravity = false;
public:
    Ball();

    Vector3D GetVelocity();
    float GetRadius();
    float GetRestitution();
    
    void SetVelocity(const Vector3D& _velocity);
    void SetRadius(float _radius);
    void SetGravity(bool _value);
    
    void Tick(float _deltaTime) override;
    void Draw() override;
    
};
