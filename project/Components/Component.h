#pragma once

class Entity;
class Component
{
protected:
    Entity* m_owner;
public:
    Component();
    
    virtual void Tick() = 0;
    virtual void Activate() {};
    virtual void Deactivate() {};

    Entity* GetOwner();
    void SetOwner(Entity* _owner);
};
