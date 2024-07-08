#pragma once
#include <cstdint>
class Vector3D;

class Matrix3D
{
private:
    float n [3][3] = {0};
public:
    Matrix3D();
    Matrix3D(float _n00, float _n10, float _n20,
             float _n01, float _n11, float _n21,
             float _n02, float _n12, float _n22);

    Matrix3D(Vector3D _vec1, Vector3D _vec2, Vector3D _vec3);
    Vector3D GetRow (uint8_t _i);
    Matrix3D operator* (Matrix3D& _other);
    Vector3D operator* (Vector3D& _other);

    static Matrix3D RotateX(float _angle);
    static Matrix3D RotateY(float _angle);
    static Matrix3D RotateZ(float _angle);

    static Matrix3D RotationMatrix(float _angle, Vector3D& _vector);

    //Reflection Matrix
    static Matrix3D Reflection(const Vector3D& _vec);


    //Scale Matrix
    static Matrix3D Scale(float _sx, float _sy, float _sz);
    static Matrix3D Scale(float s, const Vector3D& _vec);

    //Skew Matrix
    static Matrix3D Skew(float _angle, const Vector3D& _vec1, const Vector3D& _vec2);

    float operator() (int i, int j);

    float Determinant();
    static float Determinant(Matrix3D& _matrix);
    
};
