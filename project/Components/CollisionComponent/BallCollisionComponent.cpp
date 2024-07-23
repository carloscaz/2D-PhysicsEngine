#include "BallCollisionComponent.h"
#include "../../Entities/Ball/Ball.h"
#include "../../OpenGL/State/State.h"

BallCollisionComponent::BallCollisionComponent(Ball* _owner)
    :
    m_owner(_owner),
    CollisionComponent(nullptr)
{
}

void BallCollisionComponent::Tick()
{
    if(m_owner)
    {
        //Check collision with the borders of the screen
        if( m_owner->GetPosition().X <= 0)
        {
            Vector3D vr = m_owner->GetVelocity().Normalize(); //Relative velocity normalized of the particle with the ground
            Vector3D vn = Vector3D(1, 0, 0); //Normal vector of the ground
            
            if(Vector3D::DotProduct(vr, vn) <= 0) //Check the direction of the particle
            {
                m_owner->SetVelocity(Vector3D(m_owner->GetVelocity().X  * -m_owner->GetRestitution(), m_owner->GetVelocity().Y, 0));
            }
        }

        if(m_owner->GetPosition().X >= State::Getinstance()->GetWindowSize().X)
        {
            Vector3D vr = m_owner->GetVelocity().Normalize(); //Relative velocity normalized of the particle with the ground
            Vector3D vn = Vector3D(-1, 0, 0); //Normal vector of the ground
            
            if(Vector3D::DotProduct(vr, vn) <= 0) //Check the direction of the particle
            {
                m_owner->SetVelocity(Vector3D(m_owner->GetVelocity().X  * -m_owner->GetRestitution(), m_owner->GetVelocity().Y, 0));
            }
        }

        if((m_owner->GetPosition().Y <= 0))
        {
            Vector3D vr = m_owner->GetVelocity().Normalize(); //Relative velocity normalized of the particle with the ground
            Vector3D vn = Vector3D(0, -1, 0); //Normal vector of the ground
            
            if(Vector3D::DotProduct(vr, vn) >= 0) //Check the direction of the particle
            {
                m_owner->SetVelocity(Vector3D(m_owner->GetVelocity().X, -m_owner->GetVelocity().Y  * m_owner->GetRestitution(), 0));
            }
        }

        if((m_owner->GetPosition().Y >= State::Getinstance()->GetWindowSize().Y))
        {
            Vector3D vr = m_owner->GetVelocity(); //Relative velocity normalized of the particle with the ground
            Vector3D vn = Vector3D(0, 1, 0); //Normal vector of the ground
            
            if(Vector3D::DotProduct(vr.Normalize(), vn) >= 0) //Check the direction of the particle
            {
                m_owner->SetVelocity(Vector3D(vr.X, vr.Y * -m_owner->GetRestitution(), 0));
            }
        }
    }
}
