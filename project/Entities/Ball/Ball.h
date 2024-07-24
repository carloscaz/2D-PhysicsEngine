#pragma once
#include "../MovableEntity.h"

class Ball : public MovableEntity
{
private:
    float m_radius;
    const float m_restitutionCoefficient = 1.0f;

    bool m_gravity = false;
public:
    Ball();
    
    float GetRadius();
    float GetRestitution();
    
    void SetRadius(float _radius);
    void SetGravity(bool _value);
    
    void Tick(float _deltaTime) override;
    void Draw() override;
    
};
