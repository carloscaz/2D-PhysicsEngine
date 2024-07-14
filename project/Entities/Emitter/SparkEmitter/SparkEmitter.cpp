#include "SparkEmitter.h"

#include <random>
#include "../../../OpenGL/Shaders/Shader.h"
#include "../../Particle/Particle.h"

SparkEmitter::SparkEmitter(const Vector3D& _position)
{
    m_position = _position;
    Init();
}

void SparkEmitter::Init()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> distr(-1.0f, 1.0f);
    Shader* basicShader = Shader::Load("data/SpriteShader/vertex.glsl", "data/SpriteShader/fragment.glsl");
    for (int i = 0; i < numParticles; ++i)
    {
        if(particles[i] == nullptr)
        {
            particles[i] = new Particle;
            particles[i]->SetShader(basicShader);
            particles[i]->SetPosition(m_position);
            particles[i]->SetInitPos(m_position);
            particles[i]->SetTexture("data/Textures/Spark.png");
            particles[i]->SetScale(Vector3D(30,30,30));
            Vector3D initVelocity = Vector3D(distr(gen), distr(gen), 0.0f) * 100;
            particles[i]->SetVelocity(initVelocity);
            particles[i]->SetInitVelocity(initVelocity);
        }
    }
}

void SparkEmitter::Tick(float _deltaTime)
{
    
    for (int i = 0; i < numParticles; ++i)
    {
        if(particles[i] != nullptr && particles[i]->GetActive())
        {
            particles[i]->Tick(_deltaTime);
        }
    }
}

void SparkEmitter::Draw()
{
    for (int i = 0; i < numParticles; ++i)
    {
        if(particles[i] != nullptr)
        {
            particles[i]->Draw();
        }
    }
}
