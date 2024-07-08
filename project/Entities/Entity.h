#pragma once
#include <vector>

#include "../../project/Math/Vector3D/Vector3D.h"
#include "../Components/Component.h"

class Buffer;
class Shader;
class Texture;
class Vector3D;
class State;
class GLFWwindow;

class Entity
{
protected:
    Vector3D m_position;
    Vector3D m_rotation;
    Vector3D m_scale;

    GLFWwindow* m_window;

    Texture* m_texture = nullptr;

    Buffer* m_buffer;
    Shader* m_shader;

    std::vector<Component*> m_components;


public:
    Entity();

    void SetTexture(const char* _filename);
    
    void SetPosition(const Vector3D& _pos);
    void SetRotation(const Vector3D& _rotation);
    void SetScale(const Vector3D& _scale);

    Vector3D GetPosition();
    Vector3D GetRotation();
    Vector3D GetScale();

    void AddComponent(Component* _component);

    void SetWindow(GLFWwindow* _win);
    void SetShader(Shader* _shader);

    Texture* GetTexture();
    
    virtual void Tick(float _deltaTime);
    virtual void Draw();


};
