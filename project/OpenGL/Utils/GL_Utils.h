#pragma once
#include "../../lib/glew/GL/glew.h"
#include "../../../lib/glfw/glfw3.h"
#include "../../Math/Vector3D/Vector3D.h"
class Vector3D;

enum class DrawModes
{
    TRIANGLES,
    LINES,
    POINTS
};
//Set up 2D env
void SetUp2D(float _screenWidth, float _screenHeight);

//Set up OpenGl & GLFW
bool Init(GLFWwindow*& _win, float _width, float _height);

//Draw primitives
void DrawRect(const Vector3D& _pos, float _width, float _height);
void DrawLine(const Vector3D& _pos1, const Vector3D& _pos2);
void DrawPoint(const Vector3D& _pos);
void DrawTriangle(const Vector3D& _pos);
