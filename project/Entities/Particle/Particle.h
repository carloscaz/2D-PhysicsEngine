#pragma once
#include "../MovableEntity.h"
#include "../../Components/CollisionComponent/CollisionComponent.h"

class Particle : public MovableEntity
{
private:

    Vector3D m_force;
    Vector3D m_initPos;
    Vector3D m_initVelocity;

    float m_minVelocityX = -1.0f;
    float m_maxVelocityX = 1.0f;
    float m_minVelocityY = -1.0f;
    float m_maxVelocityY = 1.0f;

    bool m_collisions;

public:
    Particle(float _minVelocityX, float _maxVelocityX, float _minVelocityY, float _maxVelocityY);

    void Init() override;
    
    void Tick(float _deltaTime) override;
    void Draw() override;

    
    void SetInitPos(const Vector3D& _initPos);
    void SetInitVelocity(const Vector3D& _initVelocity);
    void AddForce(const Vector3D& _force);
    void SetForce(const Vector3D& _force);
    
    void checkCollisions(bool _value);
};
