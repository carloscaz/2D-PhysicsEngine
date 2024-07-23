#ifdef _MSC_VER
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
#endif

#include "../lib/glew/GL/glew.h"
#include "../lib/glfw/glfw3.h"
#include <iostream>
#include <random>
#include <vector>
#include <GL/wglew.h>

#include "../project/Components/CollisionComponent/BallCollisionComponent.h"
#include "../project/Entities/Entity.h"
#include "../project/OpenGL/Utils/GL_Utils.h"
#include "../project//Entities/World.h"
#include "../project/Entities/Ball/Ball.h"
#include "../project/Entities/Particle/Particle.h"
#include "../project/OpenGL/Shaders/Shader.h"
#include "../project/OpenGL/State/State.h"
#include "../project/OpenGL/Textures/Texture.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600


void window_size_callback(GLFWwindow* window, int width, int height)
{
    // glfwGetWindowSize(window, &width, &height);
    glViewport(0, 0, width, height);
    State::Getinstance()->SetWindowsSize(Vector2D(width, height));
}

int main()
{
    //Init GLFW & Glew
    GLFWwindow* win;
    if (!Init(win, SCREEN_WIDTH, SCREEN_HEIGHT))
    {
        return -1;
    }

    //Shader creation
    Shader* basicShader = Shader::Load("data/SpriteShader/vertex.glsl", "data/SpriteShader/fragment.glsl");

    Ball* ball = new Ball();
    ball->SetVelocity(Vector3D(100,0,0));
    ball->SetShader(basicShader);
    ball->SetTexture("data/Textures/Ball.png");
    ball->SetPosition(Vector3D(100, 300, 0));
    ball->SetScale(Vector3D(ball->GetTexture()->GetTextureData().texWidth * 3,ball->GetTexture()->GetTextureData().texHeight * 3,0));
    ball->AddComponent(new BallCollisionComponent(ball));
    World::GetInstance()->AddEntity(ball);

    //World Creation
    World* myWorld = World::GetInstance();
    

    //Set up env
    SetUp2D(SCREEN_WIDTH, SCREEN_HEIGHT);

    //Inputs modes of GLFW
    glfwSetInputMode(win, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);

    //Callbacks of GLFW

    //Get window size
    int screenWidth, screenHeight;
    glfwGetWindowSize(win, &screenWidth, &screenHeight);
    State::Getinstance()->SetWindowsSize(Vector2D(screenWidth, screenHeight));

    glfwSetWindowSizeCallback(win, window_size_callback);

    MovableEntity* test = new MovableEntity();
    Vector3D force = Vector3D(2000,0,0);
    // main loop
    double lastTime = glfwGetTime();
    while (!glfwWindowShouldClose(win) && !glfwGetKey(win, GLFW_KEY_ESCAPE))
    {
        //Get delta time
        float deltaTime = static_cast<float>(glfwGetTime() - lastTime);
        lastTime = glfwGetTime();
        myWorld->SetDeltaTime(deltaTime);

        //printf("DeltaTime: %f\n", deltaTime);

        double mousePositionX;
        double mousePositionY;
        glfwGetCursorPos(win, &mousePositionX, &mousePositionY);
        
        glClear(GL_COLOR_BUFFER_BIT);
        glClear(GL_DEPTH_BUFFER_BIT);
        //glClearColor(1,0,0,0);

        myWorld->Tick(deltaTime);
        myWorld->Draw();

        //Refresh screen
        glfwSwapBuffers(win);
        glfwPollEvents();
    }

    //Shutdown
    glfwTerminate();
}