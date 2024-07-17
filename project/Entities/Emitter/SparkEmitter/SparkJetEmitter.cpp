#include "SparkJetEmitter.h"

#include <random>

#include "../../../../lib/glfw/glfw3.h"
#include "../../../OpenGL/Shaders/Shader.h"
#include "../../../OpenGL/Textures/Texture.h"
#include "../../Particle/Particle.h"

SparkJetEmitter::SparkJetEmitter(const Vector3D& _position)
{
    m_position = _position;
    Init();
}

void SparkJetEmitter::Init()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> velocityX(0.2f, 1.0f);
    std::uniform_real_distribution<> velocityY(-0.2, 0.2);
    Shader* particleShader = Shader::Load("data/ParticleShader/vertex.glsl", "data/ParticleShader/fragment.glsl");
    for (int i = 0; i < numParticles; ++i)
    {
        if(m_particles[i] == nullptr)
        {
            m_particles[i] = new Particle(0.2f, 1.0f, -0.2f, 0.2f);
            m_particles[i]->SetShader(particleShader);
            m_particles[i]->SetPosition(m_position);
            m_particles[i]->SetInitPos(m_position);
            m_particles[i]->SetTexture("data/Textures/Spark.png");
            m_particles[i]->SetScale(Vector3D(m_particles[i]->GetTexture()->GetTextureData().texWidth,m_particles[i]->GetTexture()->GetTextureData().texHeight,0));
            Vector3D initVelocity = Vector3D(velocityX(gen), velocityY(gen), 0.0f) * 100;
            m_particles[i]->SetVelocity(initVelocity);
            m_particles[i]->SetInitVelocity(initVelocity);
        }
    }
}
