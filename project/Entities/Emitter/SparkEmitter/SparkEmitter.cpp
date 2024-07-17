#include "SparkEmitter.h"

#include <random>

#include "../../../../lib/glfw/glfw3.h"
#include "../../../OpenGL/Shaders/Shader.h"
#include "../../../OpenGL/Textures/Texture.h"
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
    Shader* particleShader = Shader::Load("data/ParticleShader/vertex.glsl", "data/ParticleShader/fragment.glsl");
    for (int i = 0; i < numParticles; ++i)
    {
        if(m_particles[i] == nullptr)
        {
            m_particles[i] = new Particle(-1.0f, 1.0f, -1.0f,1.0f);
            m_particles[i]->SetShader(particleShader);
            m_particles[i]->SetPosition(m_position);
            m_particles[i]->SetInitPos(m_position);
            m_particles[i]->SetTexture("data/Textures/Spark.png");
            m_particles[i]->SetScale(Vector3D(m_particles[i]->GetTexture()->GetTextureData().texWidth,m_particles[i]->GetTexture()->GetTextureData().texWidth,0));
            Vector3D initVelocity = Vector3D(distr(gen), distr(gen), 0.0f) * 100;
            m_particles[i]->SetVelocity(initVelocity);
            m_particles[i]->SetInitVelocity(initVelocity);
        }
    }
}

void SparkEmitter::Tick(float _deltaTime)
{
    float time = glfwGetTime(); //time variable to spawn particles random first time
    for (int i = 0; i < numParticles; ++i)
    {
        if(m_particles[i] != nullptr && m_particles[i]->GetActive()  && time > m_particles[i]->GetLifetime())
        {
            m_particles[i]->Tick(_deltaTime);
        }
    }
}

void SparkEmitter::Draw()
{
    float time = glfwGetTime(); //time variable to spawn particles random first time
    for (int i = 0; i < numParticles; ++i)
    {
        if(m_particles[i] != nullptr && time > m_particles[i]->GetLifetime())
        {
            m_particles[i]->Draw();
        }
    }
}
