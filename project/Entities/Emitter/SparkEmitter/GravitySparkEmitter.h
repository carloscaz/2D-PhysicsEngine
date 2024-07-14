#pragma once
#include "SparkEmitter.h"

class GravitySparkEmitter : public SparkEmitter
{
public:
    GravitySparkEmitter(const Vector3D& _position);
    void Init() override;
    
};
