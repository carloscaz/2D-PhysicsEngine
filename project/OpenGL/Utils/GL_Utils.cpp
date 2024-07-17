#include "GL_Utils.h"

#include <iostream>

#include "../../project/Math/Vector3D/Vector3D.h"
#include "../../../src/Vertex/Vertex.h"
#include "../Buffer/Buffer.h"
#include "../Shaders/Shader.h"
#include "../../OpenGL/State/State.h"
#include "GL/glew.h"
#include "../glfw/glfw3.h"
//Set up 2D env
void SetUp2D(float _screenWidht, float _screenHeight)
{
    //Set up 2D enviroment
    glDisable(GL_ALPHA_TEST);
    glEnable(GL_BLEND);
    glDisable(GL_DEPTH_TEST);
    glEnable(GL_SCISSOR_TEST);
    glEnable(GL_TEXTURE_2D);
    // glEnableClientState(GL_VERTEX_ARRAY);
    // glDisableClientState(GL_NORMAL_ARRAY);
    // glEnableClientState(GL_TEXTURE_COORD_ARRAY);

    // glViewport(0, 0, _screenWidht, _screenHeight);
    // glScissor(0, 0, _screenWidht, _screenHeight);
    // glMatrixMode(GL_PROJECTION);
    // glLoadIdentity();
    // glOrtho(0, _screenWidht, _screenHeight, 0, 0, 1000);
    // glMatrixMode(GL_MODELVIEW);
    //
    // glLoadIdentity();
    // glTranslatef(-0, -0, 0);
    //
    // glMatrixMode(GL_PROJECTION);
    // glLoadIdentity();
    // glOrtho(0, _screenWidht, _screenHeight, 0, 0, 1000);
    // glMatrixMode(GL_MODELVIEW);
    //
    // glBlendFunc(GL_ONE, GL_ZERO);
    //
    // glColor4f(1, 1, 1, 1);
    //
    // glDisableClientState(GL_COLOR_ARRAY);
    //
    // glEnable(GL_CULL_FACE);
    //
    // glDepthMask(1);
    //
    // glDisable(GL_LIGHTING);
    //
    // float color[] = {0, 0, 0, 1};
    // glDisable(GL_FOG);
    // glFogfv(GL_FOG_COLOR, color);
    // glFogf(GL_FOG_START, 0);
    // glFogf(GL_FOG_END, 0);
    //
    // glBindTexture(GL_TEXTURE_2D, 0);
}

bool Init(GLFWwindow*& _win, float _width, float _height)
{
    //Innit glfw
    if (!glfwInit())
    {
        std::cout << "could not initialize glfw" << std::endl;
        return false;
    }

    // create window
    //glfwWindowHint(GLFW_RESIZABLE, false);
    glfwWindowHint(GLFW_SAMPLES, 8);
    _win = glfwCreateWindow(_width, _height, "PixelGL-Next", nullptr, nullptr);
    if (!_win)
    {
        std::cout << "could not create opengl window" << std::endl;
        glfwTerminate();
        return false;
    }
    glfwMakeContextCurrent(_win);

    //INit Glew
    glewInit();

    State::Getinstance()->SetWindow(_win);
    return true;
}


//Draw rectangle in OpenGl
void DrawRect(const Vector3D& _pos, float _width, float _height)
{
    Vertex vertices[] =
    {
        Vertex(Vector3D(0.5f + _width, 0.5f + _height, 0.0f), Vector2D(1.0f, 1.0f)),
        Vertex(Vector3D(0.5f + _width, 0.0f, 0.0f), Vector2D(1.0f, 0.0f)),
        Vertex(Vector3D(0.0f, 0.0f, 0.0f), Vector2D(0.0f, 0.0f)),
        Vertex(Vector3D(0.0f, 0.5f + _height, 0.0f), Vector2D(0.0f, 1.0f))
    };

    unsigned int indices[]
    {
        0, 1, 3,
        1, 2, 3
    };
}

//Draw a line in OpenGl
void DrawLine(const Vector3D& _pos1, const Vector3D& _pos2)
{
    Vertex vertices[] =
    {
        Vertex(_pos1),
        Vertex(_pos2)
    };

    unsigned int indices[] =
    {
        0, 1
    };

    Shader* myShader = Shader::Load("data/SpriteShader/vertex.glsl", "data/SpriteShader/fragment.glsl");
    Buffer* myBuffer = new Buffer(vertices, indices, sizeof(vertices), sizeof(indices));
    myBuffer->Draw(myShader, DrawModes::LINES);
}

//Draw a point in OpenGl
void DrawPoint(const Vector3D& _pos)
{
    Vertex vertices[] =
    {
        Vertex(_pos)
    };

    unsigned int indices[] =
    {
        0
    };

    Shader* myShader = Shader::Load("data/SpriteShader/vertex.glsl", "data/SpriteShader/fragment.glsl");
    Buffer* myBuffer = new Buffer(vertices, indices, sizeof(vertices), sizeof(indices));
    myBuffer->Draw(myShader, DrawModes::POINTS);
}

//Draw a triangle in OpenGl
void DrawTriangle(const Vector3D& _pos)
{
    Vertex vertices[] =
    {
        Vertex(Vector3D(-0.1f, 0.0f, 0)),
        Vertex(Vector3D(0.0f, 0.4f, 0)),
        Vertex(Vector3D(0.1f, 0.0f, 0))
    };

    unsigned int indices[] =
    {
        0, 1, 2
    };

    Shader* myShader = Shader::Load("data/SpriteShader/vertex.glsl", "data/SpriteShader/fragment.glsl");
    Buffer* myBuffer = new Buffer(vertices, indices, sizeof(vertices), sizeof(indices));
    myBuffer->Draw(myShader, DrawModes::TRIANGLES);
}
