#pragma once
#include "../../project/Math/Vector3D/Vector3D.h"

class Buffer;
class Shader;
class Texture;
class Vector3D;
class State;

class Entity
{
protected:
    Vector3D m_position;
    Vector3D m_rotation;
    Vector3D m_scale;

    Texture* m_texture = nullptr;

    Buffer* m_buffer;
    Shader* m_shader;

    float m_fps = 1;
    float m_elapsedTime = 0.0f;
    int m_currentFrame = 0;
    int m_numFrames = 1;
public:
    Entity();

    void SetTexture(const char* _filename);
    void SetPosition(const Vector3D& _pos);
    void SetScale(const Vector3D& _scale);

    void SetFPS(int _fps);
    void SetNumFrames(int _numFrames);

    void SetShader(Shader* _shader);

    Texture* GetTexture();
    
    virtual void Tick(float _deltaTime);
    virtual void Draw();


};
