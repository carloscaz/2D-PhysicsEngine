#pragma once
#include "../Component.h"

class Ball;

class CollisionComponent : public Component
{
public:
    CollisionComponent(Entity* _owner);
    void Tick() override;
};
