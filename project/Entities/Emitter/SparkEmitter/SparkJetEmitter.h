#pragma once
#include "SparkEmitter.h"
#include "../Emitter.h"

class SparkJetEmitter : public SparkEmitter
{
public:
    SparkJetEmitter(const Vector3D& _position);
    void Init() override;
};
