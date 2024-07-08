#pragma once
#include "../Component.h"

class CollisionComponent : public Component
{
public:
    void Tick() override;
};
