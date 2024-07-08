#pragma once

class Vector2D
{
public:
    float X = 0;
    float Y = 0;

    Vector2D();
    Vector2D(float _X, float _Y);

#pragma region Basic operations
    Vector2D operator+ (Vector2D& _other);
    Vector2D operator+= (Vector2D& _other);
    Vector2D operator- (Vector2D& _other);
    Vector2D operator-= (Vector2D& _other);
    Vector2D operator* (Vector2D & _other);
    Vector2D operator*= (Vector2D& _other);
    Vector2D operator* (float _s);
    Vector2D operator / (float _s);
#pragma endregion
    
    float Size();
    static float Size(Vector2D& _other);
    
    Vector2D Normalize();
    static Vector2D Normalize(Vector2D& _other);

    float DotProduct(Vector2D& _other);
    float DotProduct(const Vector2D& _other);
    static float DotProduct(Vector2D& _vec1, Vector2D& _vec2);
    static float DotProduct(const Vector2D& _vec1, const Vector2D& _vec2);
    
    static Vector2D Projection(Vector2D& _vec1, Vector2D& _vec2);
};
