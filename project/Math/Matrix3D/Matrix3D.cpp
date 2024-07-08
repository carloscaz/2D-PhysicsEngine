#include "Matrix3D.h"
#include "../../project/Math/Vector3D/Vector3D.h"
#include <cmath>
Matrix3D::Matrix3D()
{
}

Matrix3D::Matrix3D(float _n00, float _n10, float _n20, float _n01, float _n11, float _n21, float _n02, float _n12,
                   float _n22)
{
    n[0][0] = _n00;
    n[0][1] = _n10;
    n[0][2] = _n20;
    n[1][0] = _n01;
    n[1][1] = _n11;
    n[1][2] = _n21;
    n[2][0] = _n02;
    n[2][1] = _n12;
    n[2][2] = _n22;
}

Matrix3D::Matrix3D(Vector3D _vec1, Vector3D _vec2, Vector3D _vec3)
{
    n[0][0] = _vec1.X; n[0][1] = _vec1.Y; n[0][2] = _vec1.Z;
    n[1][0] = _vec2.X; n[1][1] = _vec2.Y; n[1][2] = _vec2.Z;
    n[2][0] = _vec3.X; n[2][1] = _vec3.Y; n[2][2] = _vec2.Z;
}

Vector3D Matrix3D::GetRow(uint8_t _i)
{
    return *reinterpret_cast<Vector3D*>(n[_i]);
}

Matrix3D Matrix3D::operator*(Matrix3D& _other)
{
    float indexes[9] = {0};
    int count = 0;
    for (int i = 0; i < 3; i++) //Iterate thorugh all rows and columns of both matrix to get the multiplication
    {
        for (int j = 0; j < 3; j++)
        {
            int num = 0;
            for (int k = 0; k < 3; k++)
            {
                indexes[count] += n[i][k] * _other.n[k][j];
            }
            count++;
        }
    }

    return Matrix3D(indexes[0], indexes[1], indexes[2],
                    indexes[3], indexes[4], indexes[5],
                    indexes[6], indexes[7], indexes[8]);
}

Vector3D Matrix3D::operator*(Vector3D& _other)
{
    float indexes[3] = {0};
    for (int i = 0; i < 3; i++)
    {
        indexes[i] += n[i][0] * _other.X;
        indexes[i] += n[i][1] * _other.Y;
        indexes[i] += n[i][2] * _other.Z;
    }
    return Vector3D(indexes[0], indexes[1], indexes[2]);
}

Matrix3D Matrix3D::RotateX(float _angle)
{
    //Return the matri rotation around X axis
    return Matrix3D(1,      0,           0,
                    0,      cos(_angle), -sin(_angle),
                    0,      sin(_angle), cos(_angle));
}

Matrix3D Matrix3D::RotateY(float _angle)
{
    //Return the matrix rotation around Y axis
    return Matrix3D(cos(_angle),  0,    sin(_angle),
                    0,            1,    0,
                    -sin(_angle), 0,    cos(_angle));
}

Matrix3D Matrix3D::RotateZ(float _angle)
{
    //Return the matrix rotation around Z axis
    return Matrix3D(cos(_angle), -sin(_angle), 0,
                    sin(_angle), cos(_angle),  0,
                    0,           0,            1);
}

Matrix3D Matrix3D::RotationMatrix(float _angle, Vector3D& _vector)
{
    float c = cos(_angle);
    float s = sin (_angle);
    float d = 1.0f - c;

    float x = _vector.X * d;
    float y = _vector.Y * d;
    float z = _vector.Z * d;

    float axay = x * _vector.Y;
    float axaz = x * _vector.Z;
    float ayaz = y * _vector.Z;

    return Matrix3D(c + x * _vector.X,  axay - s * _vector.Z,   axaz + s * _vector.Y,
                    axay + s * _vector.Z, c + y * _vector.Y,    ayaz - s * _vector.X,
                    axaz - s * _vector.Y, ayaz + s * _vector.X, c + z * _vector.Z);
}

Matrix3D Matrix3D::Reflection(const Vector3D& _vec)
{
    float x = _vec.X * -2.0f;
    float y = _vec.Y * -2.0f;
    float z = _vec.Z * -2.0f;

    float axay = x * _vec.Y;
    float axaz = x * _vec.Z;
    float ayaz = y * _vec.Z;

    return Matrix3D(x * _vec.X + 1.0f, axay, axaz,
                    axay, y*_vec.Y + 1.0f, ayaz,
                    axaz, ayaz, z * _vec.Z + 1.0f);
}

Matrix3D Matrix3D::Scale(float _sx, float _sy, float _sz)
{
    return Matrix3D(_sx, 0, 0,
                    0, _sy, 0,
                    0, 0, _sz);
}

Matrix3D Matrix3D::Scale(float s, const Vector3D& _vec)
{
    s -= 1.0f;

    float x = _vec.X * s;
    float y = _vec.Y * s;
    float z = _vec.Z * s;

    float axay = x * _vec.Y;
    float axaz = x * _vec.Z;
    float ayaz = y * _vec.Z;

    return Matrix3D(x *_vec.X + 1.0f, axay, axaz,
                    axay, y * _vec.Y + 1.0f, ayaz,
                    axaz, ayaz, z * _vec.Z + 1.0f);
}

Matrix3D Matrix3D::Skew(float _angle, const Vector3D& _vec1, const Vector3D& _vec2)
{
    float t = tan(_angle);
    float x = _vec1.X * t;
    float y = _vec1.Y * t;
    float z = _vec1.Z * t;

    return Matrix3D(x * _vec2.X + 1.0f, x * _vec2.Y, x * _vec2.Z,
                    y * _vec2.X, y * _vec2.Y + 1.0f, y * _vec2.Z,
                    z * _vec2.Z, z * _vec2.Y, z * _vec2.Z + 1.0f);
}

float Matrix3D::operator()(int i, int j)
{
    return (n[j][i]);
}

float Matrix3D::Determinant()
{
    return(((0, 0) * (1, 1) * (2, 2)) - ((1, 2) * (2, 1))) +
        (((0, 1) * (1, 2) * (2, 0)) - ((1, 0) * (2, 2))) +
        (((0, 2) * (1, 0) * (2, 1)) - ((1, 1) * (2, 0)));
}

float Matrix3D::Determinant(Matrix3D& _matrix)
{
    return((_matrix(0, 0) * _matrix(1, 1) * _matrix(2, 2)) - (_matrix(1, 2) * _matrix(2, 1))) +
        ((_matrix(0, 1) * _matrix(1, 2) * _matrix(2, 0)) - (_matrix(1, 0) * _matrix(2, 2))) +
        ((_matrix(0, 2) * _matrix(1, 0) * _matrix(2, 1)) - (_matrix(1, 1) * _matrix(2, 0)));
}
