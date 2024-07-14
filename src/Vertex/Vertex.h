#pragma once
#include "../../project/Math/Vector3D/Vector3D.h"
#include "../../project/Math/Vector2D/Vector2D.h"

class Vertex
{
public:
    Vertex();
    Vertex(const Vector3D& _pos);
    Vertex(const Vector3D& _pos, const Vector2D& _tex);
    Vertex(const Vector3D& _pos, const Vector2D& _tex, const Vector3D& _color);

    //Vector3D GetPosition();
    const Vector3D& GetPosition() const;
    //Vector3D GetNormal();
    const Vector3D& GetNormal() const;
    //Vector2D GetTexture();
    const Vector2D& GetTexture() const;

    Vector3D m_pos = Vector3D(0.0f, 0.0f, 0.0f);
    Vector2D m_tex = Vector2D(0.0f, 0.0f);
    Vector3D m_color =  Vector3D(1.0f,1.0f,1.0f);
private:
    Vector3D m_norm = Vector3D(0.0f, 0.0f, -1.0f);

};

