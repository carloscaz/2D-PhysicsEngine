#include "Component.h"

Component::Component()
{
}

Entity* Component::GetOwner()
{
    return m_owner;
}

void Component::SetOwner(Entity* _owner)
{
    m_owner = _owner;
}
