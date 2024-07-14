#pragma once
#include "../Component.h"

class Ball;

class CollisionComponent : public Component
{
public:
    void Tick() override;
    bool checkBallCollision(Ball* _entity, Ball* _otherEntity);
};
