#ifdef _MSC_VER
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
#endif

#include "../lib/glew/GL/glew.h"
#include "../lib/glfw/glfw3.h"
#include <iostream>
#include <random>
#include <vector>
#include <GL/wglew.h>

#include "../project/Entities/Entity.h"
#include "../project/Entities/Player.h"
#include "../project/OpenGL/Textures/Texture.h"
#include "../project/OpenGL/Utils/GL_Utils.h"
#include "../project//Entities/World.h"
#include "../project/Entities/Ball/Ball.h"
#include "../project/Entities/Emitter/Emitter.h"
#include "../project/Entities/Emitter/SparkEmitter/GravitySparkEmitter.h"
#include "../project/Entities/Emitter/SparkEmitter/SparkEmitter.h"
#include "../project/OpenGL/State/State.h"
#include "../project/Math/Matrix3D/Matrix3D.h"
#include "../project/OpenGL/Shaders/Shader.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
    {
        double mousePositionX;
        double mousePositionY;
        glfwGetCursorPos(window, &mousePositionX, &mousePositionY);
        
        // SparkEmitter* myEmitter = new SparkEmitter(Vector3D(mousePositionX, mousePositionY, 0));
        // World::GetInstance()->AddEntity(myEmitter);

        GravitySparkEmitter* myGravitySparkEmitter = new GravitySparkEmitter(Vector3D(mousePositionX, mousePositionY, 0));
        World::GetInstance()->AddEntity(myGravitySparkEmitter);
    }
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

    //World Creation
    World* myWorld = World::GetInstance();

    //Entity creation && add to the world
    // for (int i = 0; i < 10; ++i)
    // {
    // 	Ball* ball = new Ball();
    // 	ball->SetShader(basicShader);
    // 	ball->SetTexture("data/Textures/Ball.png");
    // 	ball->SetPosition(Vector3D(0 + (rand() % 800), 0 + (rand() % 600), 0));
    // 	ball->SetVelocity(Vector3D(distr(gen), distr(gen), 0.0f));
    // 	ball->SetRadius(ball->GetTexture()->GetTextureData().texWidth / 2);
    // 	myWorld->AddEntity(ball);
    // }


    // Ball* ball = new Ball();
    // ball->SetShader(basicShader);
    // ball->SetTexture("data/Textures/Spark.png");
    // ball->SetPosition(Vector3D(100, 500, 0));
    // ball->SetVelocity(Vector3D(0.70f, -0.70f, 0.0f) * 1000);
    // ball->SetGravity(true);
    // ball->SetRadius(ball->GetTexture()->GetTextureData().texWidth / 2);
    // myWorld->AddEntity(ball);
    

    // Ball* ball2 = new Ball();
    // ball2->SetShader(basicShader);
    // ball2->SetTexture("data/Textures/Ball.png");
    // ball2->SetPosition(Vector3D(700, 300, 0));
    // ball2->SetVelocity(Vector3D(-100, 0, 0.0f));
    // ball2->SetRadius(ball->GetTexture()->GetTextureData().texWidth / 2);
    // myWorld->AddEntity(ball2);

    //Set up env
    SetUp2D(SCREEN_WIDTH, SCREEN_HEIGHT);
    
    //glfwSetInputMode(win, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);

    //glfwSetInputMode(win, GLFW_STICKY_MOUSE_BUTTONS, GLFW_TRUE);
    // main loop
    double lastTime = glfwGetTime();
    glfwSetMouseButtonCallback(win, mouse_button_callback);
    while (!glfwWindowShouldClose(win) && !glfwGetKey(win, GLFW_KEY_ESCAPE))
    {
        // get delta time
        float deltaTime = static_cast<float>(glfwGetTime() - lastTime);
        lastTime = glfwGetTime();
        myWorld->SetDeltaTime(deltaTime);

        printf("DeltaTime: %f\n", deltaTime);

        
        //ball2->SetPosition(Vector3D(mousePositionX - ball2->GetRadius() * 2, mousePositionY - ball2->GetRadius() * 2, 0));
        // get window size
        int screenWidth, screenHeight;
        glfwGetWindowSize(win, &screenWidth, &screenHeight);

        glClear(GL_COLOR_BUFFER_BIT);
        glClear(GL_DEPTH_BUFFER_BIT);

        myWorld->Tick(deltaTime);
        myWorld->Draw();

        // refresh screen
        glfwSwapBuffers(win);
        glfwPollEvents();
    }

    // shutdown
    glfwTerminate();
}
