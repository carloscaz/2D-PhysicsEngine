#pragma once
#include "../Entity.h"
class Particle;

class Emitter : public Entity
{
protected:
    int numParticles = 100;
    Particle* m_particles[100];
public:
    Emitter() {};
    void Init() override {};
    void Tick(float _deltaTime) override {};
    void Draw() override {};

    Particle* GetParticle(int _index);
    int GetNunParticles();
};



