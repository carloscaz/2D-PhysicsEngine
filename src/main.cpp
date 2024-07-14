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
#include "../project/OpenGL/Utils/GL_Utils.h"
#include "../project//Entities/World.h"
#include "../project/Entities/Emitter/SparkEmitter/GravitySparkEmitter.h"
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

        //Spark emitter of particles without gravity. Uncomment to add to the program
        SparkEmitter* myEmitter = new SparkEmitter(Vector3D(mousePositionX, mousePositionY, 0));
        World::GetInstance()->AddEntity(myEmitter);

        //Spark emitter of particles with gravity. Uncomment to add to the program
        // GravitySparkEmitter* myGravitySparkEmitter = new GravitySparkEmitter(Vector3D(mousePositionX, mousePositionY, 0));
        // World::GetInstance()->AddEntity(myGravitySparkEmitter);
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
    

    //Set up env
    SetUp2D(SCREEN_WIDTH, SCREEN_HEIGHT);

    //Inputs modes of GLFW
    //glfwSetInputMode(win, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
    //glfwSetInputMode(win, GLFW_STICKY_MOUSE_BUTTONS, GLFW_TRUE);

    //Callbacks of GLFW
    glfwSetMouseButtonCallback(win, mouse_button_callback);
    
    // main loop
    double lastTime = glfwGetTime();
    while (!glfwWindowShouldClose(win) && !glfwGetKey(win, GLFW_KEY_ESCAPE))
    {
        //Get delta time
        float deltaTime = static_cast<float>(glfwGetTime() - lastTime);
        lastTime = glfwGetTime();
        myWorld->SetDeltaTime(deltaTime);

        //printf("DeltaTime: %f\n", deltaTime);
        
        //Get window size
        int screenWidth, screenHeight;
        glfwGetWindowSize(win, &screenWidth, &screenHeight);

        glClear(GL_COLOR_BUFFER_BIT);
        glClear(GL_DEPTH_BUFFER_BIT);

        myWorld->Tick(deltaTime);
        myWorld->Draw();

        //Refresh screen
        glfwSwapBuffers(win);
        glfwPollEvents();
    }

    //Shutdown
    glfwTerminate();
}