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
        particles[i]->setAcceleration(Vector3D(0, 980.0f, 0));
        particles[i]->checkCollisions(true);
    }
}
