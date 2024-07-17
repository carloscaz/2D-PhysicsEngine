#include "CollisionComponent.h"

#include "../../Entities/World.h"
#include "../../Entities/particle/particle.h"
#include "../../OpenGL/Textures/Texture.h"
#include "../../Entities/MovableEntity.h"

CollisionComponent::CollisionComponent(Entity* _owner)
{
    m_owner = _owner;
}

void CollisionComponent::Tick()
{
    Entity* owner = GetOwner();
    MovableEntity* particle = dynamic_cast<MovableEntity*>(owner);
    
    if(owner)
    {
        //Check collision with the borders of the screen
        if( particle->GetPosition().X <= 0)
        {
            Vector3D vr = particle->GetVelocity().Normalize(); //Relative velocity normalized of the particle with the ground
            Vector3D vn = Vector3D(1, 0, 0); //Normal vector of the ground
            
            if(Vector3D::DotProduct(vr, vn) <= 0) //Check the direction of the particle
            {
                particle->SetVelocity(Vector3D(particle->GetVelocity().X  * -0.5f, particle->GetVelocity().Y, 0));
            }
        }

        if(particle->GetPosition().X >= 800)
        {
            Vector3D vr = particle->GetVelocity().Normalize(); //Relative velocity normalized of the particle with the ground
            Vector3D vn = Vector3D(-1, 0, 0); //Normal vector of the ground
            
            if(Vector3D::DotProduct(vr, vn) <= 0) //Check the direction of the particle
            {
                particle->SetVelocity(Vector3D(particle->GetVelocity().X  * -0.5f, particle->GetVelocity().Y, 0));
            }
        }

        if((particle->GetPosition().Y <= 0))
        {
            Vector3D vr = particle->GetVelocity().Normalize(); //Relative velocity normalized of the particle with the ground
            Vector3D vn = Vector3D(0, -1, 0); //Normal vector of the ground
            
            if(Vector3D::DotProduct(vr, vn) >= 0) //Check the direction of the particle
            {
                particle->SetVelocity(Vector3D(particle->GetVelocity().X, particle->GetVelocity().Y  * -0.5f, 0));
            }
        }

        if((particle->GetPosition().Y >= 600))
        {
            Vector3D vr = particle->GetVelocity(); //Relative velocity normalized of the particle with the ground
            Vector3D vn = Vector3D(0, 1, 0); //Normal vector of the ground
            
            if(Vector3D::DotProduct(vr.Normalize(), vn) >= 0) //Check the direction of the particle
            {
                particle->SetVelocity(Vector3D(vr.X, vr.Y * -0.5f, 0));
            }
        }
    }
}
