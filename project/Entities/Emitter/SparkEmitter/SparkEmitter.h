#pragma once
#include "../Emitter.h"

class SparkEmitter : public Emitter
{
public:
    SparkEmitter() {};
    SparkEmitter(const Vector3D& _position);

    void Init() override;
    void Tick(float _deltaTime) override;
    void Draw() override;
    
};
