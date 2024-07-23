#pragma once
#include "CollisionComponent.h"

class Ball;

class BallCollisionComponent : public CollisionComponent
{
private:
    Ball* m_owner;
public:
    BallCollisionComponent(Ball* _owner);
    void Tick() override;
};
