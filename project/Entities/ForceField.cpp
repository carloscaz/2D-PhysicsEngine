#include "ForceField.h"

#include "../OpenGL/Textures/Texture.h"
#include "Particle/Particle.h"

void ForceField::Tick(float _deltaTime)
{
    //MovableEntity::Tick(_deltaTime);

    if(m_emitter.size() > 0)
    {
        for(Emitter* emitter : m_emitter)
        {
            for (int i = 0; i < emitter->GetNunParticles(); ++i)
            {
                Vector3D direction = Vector3D(emitter->GetParticle(i)->GetPosition() - GetPosition());
                float force = m_gravityConstant * (m_mass / (direction.Size() * direction.Size()));

                if(direction.Size() <= GetTexture()->GetTextureData().texWidth/4)
                {
                    Vector3D direction = GetPosition() -  emitter->GetParticle(i)->GetPosition();
                    emitter->GetParticle(i)->AddForce(Vector3D(emitter->GetParticle(i)->GetPosition() - GetPosition()) * -force);
                }

            }
        }
        
    }
}

void ForceField::SetEmitter(Emitter* _emitter)
{
    m_emitter.push_back(_emitter);
}
