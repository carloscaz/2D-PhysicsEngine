#include "Emitter.h"

Particle* Emitter::GetParticle(int _index)
{
    return m_particles[_index];
}

int Emitter::GetNunParticles()
{
    return numParticles;
}
