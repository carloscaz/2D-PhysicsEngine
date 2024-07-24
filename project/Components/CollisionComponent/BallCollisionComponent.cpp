#include "BallCollisionComponent.h"

#include <__msvc_filebuf.hpp>

#include "../../Entities/Ball/Ball.h"
#include "../../OpenGL/State/State.h"
#include "../../Entities/World.h"

BallCollisionComponent::BallCollisionComponent(Ball* _owner)
    :
    m_owner(_owner),
    CollisionComponent(nullptr)
{
}

void BallCollisionComponent::CheckWallCollisions()
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

        if(m_owner->GetPosition().X + m_owner->GetRadius() >= State::Getinstance()->GetWindowSize().X)
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

        if((m_owner->GetPosition().Y + m_owner->GetRadius() >= State::Getinstance()->GetWindowSize().Y))
        {
            Vector3D vr = m_owner->GetVelocity(); //Relative velocity normalized of the particle with the ground
            Vector3D vn = Vector3D(0, 1, 0); //Normal vector of the ground
            
            if(Vector3D::DotProduct(vr.Normalize(), vn) >= 0) //Check the direction of the particle
            {
                m_owner->SetVelocity(Vector3D(vr.X, vr.Y * -m_owner->GetRestitution(), 0));
            }
        }
}

void BallCollisionComponent::CheckBallCollision(Ball* _ball1, Ball* _ball2)
{
    Vector3D distance = _ball2->GetPosition() - _ball1->GetPosition();

    Vector3D vr = _ball1->GetVelocity() - _ball2->GetVelocity(); //1. Get relative velocity of the objects
    Vector3D n = Vector3D::Normalize(_ball1->GetPosition() - _ball2->GetPosition()); //2. Get the line of action
    
    if(distance.Size() <= (_ball2->GetRadius() + _ball1->GetRadius()) && Vector3D::DotProduct(vr, n) <= 0)
    {
        //3. Get relatives velocities in the X axis
        float vrn1X = Vector3D::DotProduct(_ball1->GetVelocity(), n);
        float vrn2X = Vector3D::DotProduct(_ball2->GetVelocity(), n);

        float v2nX = ((vrn1X + vrn2X) + (_ball1->GetRestitution() * (vrn1X - vrn2X)))/2;
        float v1nX = (vrn1X + vrn2X) + v2nX * -1;

        //4. Get perpendicular vector of n
        Vector3D np = Vector3D(-n.Y, n.X, 0);

        //5. Get velocities in the Y axis
        float vrn1Y = Vector3D::DotProduct(_ball1->GetVelocity(), np);
        float vrn2Y = Vector3D::DotProduct(_ball2->GetVelocity(), np);
        
        Vector3D v1 = (Vector3D(n) * v1nX) + Vector3D(np) * vrn1Y;
        Vector3D v2 = (Vector3D(n) * v2nX) + Vector3D(np) * vrn2Y;

        //5. Set velocities in balls
        _ball1->SetVelocity(v1);
        _ball2->SetVelocity(Vector3D(v2));
    }
}

void BallCollisionComponent::Tick()
{
    if(m_owner)
    {
        CheckWallCollisions();
        for (int i = 0; i < World::GetInstance()->GetEntities().size(); ++i)
        {
            if(World::GetInstance()->GetEntities()[i] != nullptr)
            {
                Ball* otherBall = static_cast<Ball*>(World::GetInstance()->GetEntities()[i]);
                if(otherBall && otherBall != m_owner)
                {
                    CheckBallCollision(m_owner, otherBall);
                }
            }
        }
    }
}
