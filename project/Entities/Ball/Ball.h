#pragma once
#include "../Entity.h"

class Ball : public Entity
{
private:
    Vector3D m_velocity;
    float m_radius;
public:
    Ball();

    Vector3D GetVelocity();
    float GetRadius();
    
    void SetVelocity(const Vector3D& _velocity);
    void SetRadius(float _radius);
    void Tick(float _deltaTime) override;
    
};
