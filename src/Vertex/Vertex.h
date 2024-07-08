#pragma once
#include "../../project/Math/Vector3D/Vector3D.h"
#include "../../project/Math/Vector2D/Vector2D.h"
#include "../../project/Math/Vector4D/Vector4D.h"

class Vertex
{
public:
    Vertex();
    Vertex(const Vector3D& _pos);
    Vertex(const Vector3D& _pos, const Vector2D& _tex);

    //Vector3D GetPosition();
    const Vector3D& GetPosition() const;
    //Vector3D GetNormal();
    const Vector3D& GetNormal() const;
    //Vector2D GetTexture();
    const Vector2D& GetTexture() const;

    Vector3D m_pos = Vector3D(0.0f, 0.0f, 0.0f);
    Vector2D m_tex = Vector2D(0.0f, 0.0f);
private:
    Vector3D m_norm = Vector3D(0.0f, 0.0f, -1.0f);

};

