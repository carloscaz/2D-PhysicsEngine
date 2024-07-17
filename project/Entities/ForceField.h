#pragma once
#include "MovableEntity.h"
#include "Emitter/Emitter.h"

class ForceField : public MovableEntity
{
private:
    std::vector<Emitter*> m_emitter;

    float m_mass = 5.972e14;
    float m_radius;
    float m_gravityConstant = 6.67e-11;
public:
    void Tick(float _deltaTime) override;

    void SetEmitter(Emitter* _emitter);
};
