#include "Vector3D.h"
#include "math.h"
#include "../Matrix3D/Matrix3D.h"

Vector3D::Vector3D()
{}

Vector3D::Vector3D(float _X, float _Y, float _Z)
    :
    X(_X),
    Y(_Y),
    Z(_Z)
{}

Vector3D Vector3D::operator+(const Vector3D& _other)
{
    return Vector3D(X + _other.X, Y + _other.Y, Z + _other.Z);
}

Vector3D Vector3D::operator+=(const Vector3D& _other)
{
    this->X += _other.X;
    this->Y += _other.Y;
    this->Z += _other.Z;
    return (*this);
}

Vector3D Vector3D::operator-(const Vector3D& _other)
{
    return Vector3D(X - _other.X, Y - _other.Y, Z - _other.Z);
}

Vector3D Vector3D::operator-=(Vector3D& _other)
{
    this->X -= _other.X;
    this->Y -= _other.Y;
    this->Z -= _other.Z;
    return (*this);
}

Vector3D Vector3D::operator*(const Vector3D& _other)
{
    return Vector3D(X * _other.X, Y * _other.Y, Z * _other.Z);
}

Vector3D Vector3D::operator*(Matrix3D& _other)
{
    float indexes[3] = {0};
    for (int i = 0; i < 3; i++)
    {
        indexes[i] += _other(0, i) * X;
        indexes[i] += _other(1, i) * Y;
        indexes[i] += _other(2, i) * Z;
    }
    return Vector3D(indexes[0], indexes[1], indexes[2]);
}

Vector3D Vector3D::operator*=(Vector3D& _other)
{
    this->X *= _other.X;
    this->Y *= _other.Y;
    this->Z *= _other.Z;
    return (*this);
}

Vector3D Vector3D::operator*(float _s)
{
    return Vector3D(X * _s, Y * _s, Z * _s);
}

Vector3D Vector3D::operator/(float _s)
{
    return Vector3D(X / _s, Y / _s, Z / _s);
}

float Vector3D::Size()
{
    return sqrt(X * X + Y * Y + Z * Z);
}

float Vector3D::Size(Vector3D& _other)
{
    return _other.Size();
}

Vector3D Vector3D::Normalize()
{
    return *this / Size();
}

Vector3D Vector3D::Normalize(Vector3D _other)
{
    return _other.Normalize();
}

float Vector3D::DotProduct(Vector3D& _other)
{
    return (X * _other.X + Y * _other.Y + Z * _other.Z);
}

float Vector3D::DotProduct(const Vector3D& _other)
{
    return (X * _other.X + Y * _other.Y + Z * _other.Z);
}

float Vector3D::DotProduct(Vector3D& _vec1, Vector3D& _vec2)
{
    float dot = (_vec1.X * _vec2.X) + (_vec1.Y * _vec2.Y) + (_vec1.Z * _vec2.Z);
    return dot;
}

float Vector3D::DotProduct(const Vector3D& _vec1, const Vector3D& _vec2)
{
    return (_vec1.X * _vec2.X + _vec1.Y * _vec2.Y + _vec1.Z * _vec2.Z);
}

Vector3D Vector3D::CrossProduct(Vector3D& _other)
{
    return Vector3D(Y * _other.Z - Z * _other.Y, Z * _other.X - X * _other.Z, X * _other.Y - Y * _other.X);
}

Vector3D Vector3D::CrossProduct(const Vector3D& _other)
{
    return Vector3D(Y * _other.Z - Z * _other.Y, Z * _other.X - X * _other.Z, X * _other.Y - Y * _other.X);
}

Vector3D Vector3D::CrossProduct(Vector3D& _vec1, Vector3D& _vec2)
{
    return Vector3D(_vec1.Y * _vec2.Z - _vec1.Z * _vec2.Y, _vec1.Z * _vec2.X - _vec1.X * _vec2.Z, _vec1.X * _vec2.Y - _vec1.Y * _vec2.X);
}

Vector3D Vector3D::CrossProduct(const Vector3D& _vec1, const Vector3D& _vec2)
{
    return Vector3D(_vec1.Y * _vec2.Z - _vec1.Z * _vec2.Y, _vec1.Z * _vec2.X - _vec1.X * _vec2.Z, _vec1.X * _vec2.Y - _vec1.Y * _vec2.X);
}

Vector3D Vector3D::Projection(Vector3D& _vec1, Vector3D& _vec2)
{
    float dot = (DotProduct(_vec1, _vec2) / (_vec2.Size() * _vec2.Size()));
    return _vec2  * dot;
}

