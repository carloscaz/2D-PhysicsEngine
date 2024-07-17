#include "GravitySparkEmitter.h"

#include "../../Particle/Particle.h"

GravitySparkEmitter::GravitySparkEmitter(const Vector3D& _position)
{
        m_position = _position;
        Init();
}

void GravitySparkEmitter::Init()
{
    SparkEmitter::Init();
    for (int i = 0; i < numParticles; ++i)
    {
        m_particles[i]->SetForce(Vector3D(0, 980.0f, 0));
        m_particles[i]->checkCollisions(true);
    }
}
