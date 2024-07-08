#pragma once
class Matrix3D;

class Vector3D
{
public:
    float X = 0;
    float Y = 0;
    float Z = 0;

    Vector3D();
    Vector3D(float _X, float _Y, float _Z);

#pragma region Basic vector operations
    Vector3D operator+ (const Vector3D& _other);
    Vector3D operator+= (Vector3D& _other);
    Vector3D operator- (Vector3D& _other);
    Vector3D operator-= (Vector3D& _other);
    Vector3D operator* (Vector3D& _other);
    Vector3D operator* (Matrix3D& _other);
    Vector3D operator*= (Vector3D& _other);
    Vector3D operator* (float _s);
    Vector3D operator/ (float _s);
#pragma endregion

    float Size();
    static float Size(Vector3D& _other);

    Vector3D Normalize();
    static Vector3D Normalize(Vector3D _other);

    float DotProduct(Vector3D& _other);
    float DotProduct(const Vector3D& _other);
    static float DotProduct(Vector3D& _vec1, Vector3D& _vec2);
    static float DotProduct(const Vector3D& _vec1, const Vector3D& _vec2);

    Vector3D CrossProduct(Vector3D& _other);
    Vector3D CrossProduct(const Vector3D& _other);
    static Vector3D CrossProduct(Vector3D& _vec1, Vector3D& _vec2);
    static Vector3D CrossProduct(const Vector3D& _vec1, const Vector3D& _vec2);

    static Vector3D Projection(Vector3D& _vec1, Vector3D& _vec2);
    
};
