 #include "Vector2D.h"
#include "math.h"

Vector2D::Vector2D()
{}

Vector2D::Vector2D(float _X, float _Y)
    :
    X(_X),
    Y(_Y)
{
}

Vector2D Vector2D::operator+(Vector2D& _other)
{
    return Vector2D(X + _other.X, Y + _other.Y);
}

Vector2D Vector2D::operator+=(Vector2D& _other)
{
    this->X += _other.X;
    this->Y += _other.Y;
    return (*this);
}

Vector2D Vector2D::operator-(Vector2D& _other)
{
    return Vector2D(X - _other.X, Y - _other.Y);
}

Vector2D Vector2D::operator-=(Vector2D& _other)
{
    this->X -= _other.X;
    this->Y -= _other.Y;
    return (*this);
}

Vector2D Vector2D::operator*(Vector2D& _other)
{
    return Vector2D(X * _other.X, Y * _other.Y);
}

Vector2D Vector2D::operator*=(Vector2D& _other)
{
    this->X *= _other.X;
    this->Y *= _other.Y;
    return (*this);
}

Vector2D Vector2D::operator*(float _s)
{
    return Vector2D(X * _s, Y * _s);
}

Vector2D Vector2D::operator/(float _s)
{
    return Vector2D(X / _s, Y / _s);
}

float Vector2D::Size()
{
    return sqrt(X * X + Y * Y);
}

Vector2D Vector2D::Normalize()
{
    return *this / Size();
}

Vector2D Vector2D::Normalize(Vector2D& _other)
{
    return _other.Normalize();
}

float Vector2D::DotProduct(Vector2D& _other)
{
    return (X * _other.X + Y * _other.Y);
}

float Vector2D::DotProduct(const Vector2D& _other)
{
    return (X * _other.X + Y * _other.Y);
}

float Vector2D::DotProduct(Vector2D& _vec1, Vector2D& _vec2)
{
    return (_vec1.X * _vec2.X + _vec1.Y * _vec2.Y);
}

float Vector2D::DotProduct(const Vector2D& _vec1, const Vector2D& _vec2)
{
    return (_vec1.X * _vec2.X + _vec1.Y * _vec2.Y);
}

 Vector2D Vector2D::Projection(Vector2D& _vec1, Vector2D& _vec2)
 {
    float dot = (DotProduct(_vec1, _vec2) / (_vec2.Size() * _vec2.Size()));
    return _vec2  * dot;
 }

 float Vector2D::Size(Vector2D& _other)
{
    return _other.Size();
}
