#include "CollisionComponent.h"

#include "../../Entities/World.h"
#include "../../Entities/Ball/Ball.h"
#include "../../OpenGL/Textures/Texture.h"

void CollisionComponent::Tick()
{
    Entity* owner = GetOwner();
    Ball* ball = dynamic_cast<Ball*>(owner);
    
    std::vector<Entity*> otherEntities = World::GetInstance()->GetEntities();
    for(Entity* entity : otherEntities)
    {
        if(entity != owner)
        {
            Ball* otherBall = dynamic_cast<Ball*>(entity);
            //checkBallCollision(ball, otherBall);
        }
    }
    if(owner)
    {
        //Check collision with the borders of the screen
        if( ball->GetPosition().X <= 0)
        {
            Vector3D vr = ball->GetVelocity().Normalize(); //Relative velocity normalized of the ball with the ground
            Vector3D vn = Vector3D(1, 0, 0); //Normal vector of the ground
            
            if(Vector3D::DotProduct(vr, vn) <= 0) //Check the direction of the ball
            {
                ball->SetVelocity(Vector3D(ball->GetVelocity().X  * -ball->GetRestitution(), ball->GetVelocity().Y, 0));
            }
        }

        if(ball->GetPosition().X + ball->GetRadius() * 2 >= 800)
        {
            Vector3D vr = ball->GetVelocity().Normalize(); //Relative velocity normalized of the ball with the ground
            Vector3D vn = Vector3D(-1, 0, 0); //Normal vector of the ground
            
            if(Vector3D::DotProduct(vr, vn) <= 0) //Check the direction of the ball
            {
                ball->SetVelocity(Vector3D(ball->GetVelocity().X  * -ball->GetRestitution(), ball->GetVelocity().Y, 0));
            }
        }

        if((ball->GetPosition().Y <= 0))
        {
            Vector3D vr = ball->GetVelocity().Normalize(); //Relative velocity normalized of the ball with the ground
            Vector3D vn = Vector3D(0, -1, 0); //Normal vector of the ground
            
            if(Vector3D::DotProduct(vr, vn) >= 0) //Check the direction of the ball
            {
                ball->SetVelocity(Vector3D(ball->GetVelocity().X, ball->GetVelocity().Y  * -ball->GetRestitution(), 0));
            }
        }

        if((ball->GetPosition().Y + ball->GetRadius() * 2 >= 600))
        {
            Vector3D vr = ball->GetVelocity(); //Relative velocity normalized of the ball with the ground
            Vector3D vn = Vector3D(0, 1, 0); //Normal vector of the ground
            
            if(Vector3D::DotProduct(vr.Normalize(), vn) >= 0) //Check the direction of the ball
            {
                ball->SetVelocity(Vector3D(vr.X, vr.Y  * -ball->GetRestitution(), 0));
            }
        }
    }
}

bool CollisionComponent::checkBallCollision(Ball* _entity, Ball* _otherEntity)
{
    Vector3D d = _entity->GetPosition() - _otherEntity->GetPosition();
    float r = _entity->GetRadius() * 2 + _otherEntity->GetRadius() * 2;
    if((d.Size() - r) <= 0.0f)
    {
        Vector3D vr1 = Vector3D(_entity->GetVelocity() - _otherEntity->GetVelocity());
        Vector3D vr2 = Vector3D(_otherEntity->GetVelocity() - _entity->GetVelocity());
        Vector3D vn = d.Normalize();
        if(Vector3D::DotProduct(vr1.Normalize(), vn) <= 0.0f)
        {
            _entity->SetVelocity(Vector3D(vr1.X , vr1.Y , 0) * -_entity->GetRestitution());
            //_otherEntity->SetVelocity(Vector3D(vr1.X, vr1.Y, 0) * _otherEntity->GetRestitution());
        }
        return true;
    }
    return false;

}
