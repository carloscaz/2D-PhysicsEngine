#include "Vertex.h"


Vertex::Vertex()
{
    m_pos = Vector3D(0.0f, 0.0f, 0.0f);
}

Vertex::Vertex(const Vector3D& _pos)
    : 
    m_pos(_pos)
{}

Vertex::Vertex(const Vector3D& _pos, const Vector2D& _tex)
: 
m_pos(_pos),
m_tex(_tex)
{}

Vertex::Vertex(const Vector3D& _pos, const Vector2D& _tex, const Vector3D& _color)
: 
m_pos(_pos),
m_tex(_tex),
m_color(_color)
{}

const Vector3D& Vertex::GetPosition() const
{
    return m_pos;
}



const Vector3D& Vertex::GetNormal() const
{
    return m_norm;
}


const Vector2D& Vertex::GetTexture() const
{
    return m_tex;
}
