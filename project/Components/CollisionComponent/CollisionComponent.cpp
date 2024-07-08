#include "CollisionComponent.h"

#include "../../Entities/Ball/Ball.h"
#include "../../OpenGL/Textures/Texture.h"

void CollisionComponent::Tick()
{
    Entity* owner = GetOwner();
    if(owner)
    {
        Ball* ball = dynamic_cast<Ball*>(owner);
        Vector3D fixedPos = Vector3D(ball->GetPosition().X + ball->GetTexture()->GetTextureData().texWidth / 2, ball->GetPosition().Y + ball->GetTexture()->GetTextureData().texHeight / 2, 0);
        if(fixedPos.X + ball->GetRadius() < 0 || fixedPos.X + ball->GetRadius() > 800)
        {
            ball->SetVelocity(Vector3D(ball->GetVelocity().X * -1.0f, ball->GetVelocity().Y, 0));
        }

        if(fixedPos.Y + ball->GetRadius() < 0 || fixedPos.Y + ball->GetRadius()> 600)
        {
            ball->SetVelocity(Vector3D(ball->GetVelocity().X, ball->GetVelocity().Y  * -1.0f, 0));
        }
    }
}
