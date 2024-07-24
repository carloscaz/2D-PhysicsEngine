#pragma once
#include "CollisionComponent.h"

class Ball;

class BallCollisionComponent : public CollisionComponent
{
private:
    Ball* m_owner;
public:
    BallCollisionComponent(Ball* _owner);

    void CheckWallCollisions() override;
    void CheckBallCollision(Ball* _ball1, Ball* _ball2);
    void Tick() override;
};
