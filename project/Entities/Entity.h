#pragma once
#include <vector>
#include <iostream>
#include "../../project/Math/Vector3D/Vector3D.h"
#include "../Components/Component.h"

class Vertex;
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
    
    bool m_active = true;

    GLFWwindow* m_window;

    Texture* m_texture = nullptr;

    Buffer* m_buffer;
    Shader* m_shader;

    std::vector<Component*> m_components;


public:
    Entity();
    Entity(std::vector<Vertex> vertices, std::vector<unsigned int> _indices);
    ~Entity();
    
    virtual void Init() = 0;
    
    void SetTexture(const char* _filename);
    void SetPosition(const Vector3D& _pos);
    void SetRotation(const Vector3D& _rotation);
    void SetScale(const Vector3D& _scale);

    Vector3D GetPosition();
    Vector3D GetRotation();
    Vector3D GetScale();
    bool GetActive();

    void AddComponent(Component* _component);

    void SetWindow(GLFWwindow* _win);
    void SetShader(Shader* _shader);

    Texture* GetTexture()const ;
    Buffer* GetBuffer() const;
    
    virtual void Tick(float _deltaTime) = 0;
    virtual void Draw();


};
