#pragma once
#include "../Entity.h"
#include "../../Components/CollisionComponent/CollisionComponent.h"

class Particle : public Entity
{
private:
    Vector3D m_velocity;
    Vector3D m_acceleration = Vector3D(0,0,0);
    Vector3D m_initPos;
    Vector3D m_initVelocity;

    bool m_collisions;

public:
    Particle();

    void Init() override;
    
    void Tick(float _deltaTime) override;
    void Draw() override;

    void SetVelocity(const Vector3D& _vel);
    void SetInitPos(const Vector3D& _initPos);
    void SetInitVelocity(const Vector3D& _initVelocity);

    void setAcceleration(const Vector3D& _acceleration);
    void checkCollisions(bool _value);
};
