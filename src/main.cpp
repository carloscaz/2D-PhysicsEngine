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
#include "../project/Entities/ForceField.h"
#include "../project/Entities/Emitter/SparkEmitter/GravitySparkEmitter.h"
#include "../project/Entities/Emitter/SparkEmitter/SparkJetEmitter.h"
#include "../project/Entities/Ball/Ball.h"
#include "../project/Entities/Particle/Particle.h"
#include "../project/OpenGL/Shaders/Shader.h"
#include "../project/OpenGL/Textures/Texture.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

ForceField* forceField;

void SparkEmitterDemo(float mouseX, float mouseY)
{
    SparkEmitter* myEmitter = new SparkEmitter(Vector3D(mouseX, mouseY, 0));
    World::GetInstance()->AddEntity(myEmitter);
}

void GravitySparkDemo(float mouseX, float mouseY)
{
    GravitySparkEmitter* myGravitySparkEmitter = new GravitySparkEmitter(Vector3D(mouseX, mouseY, 0));
    World::GetInstance()->AddEntity(myGravitySparkEmitter);
}

void ForceFieldEmitterDemo(float mouseX, float mouseY)
{
    SparkJetEmitter* myJetEmitter = new SparkJetEmitter(Vector3D(mouseX, mouseY, 0));
    World::GetInstance()->AddEntity(myJetEmitter);

    forceField->SetEmitter(myJetEmitter);
}
void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
    {
        double mousePositionX;
        double mousePositionY;
        glfwGetCursorPos(window, &mousePositionX, &mousePositionY);

        // //Spark emitter of particles without gravity. Uncomment to add to the program
        // SparkEmitterDemo(mousePositionX, mousePositionY);
        //
        // //Spark emitter of particles with gravity. Uncomment to add to the program
        GravitySparkDemo(mousePositionX, mousePositionY);

        //Particle emitter affected by a force field. Uncomment to add to the program
        // ForceFieldEmitterDemo(mousePositionX, mousePositionY);

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
    
    // forceField = new ForceField();
    // forceField->SetVelocity(Vector3D(0,0,0));
    // forceField->SetShader(basicShader);
    // forceField->SetTexture("data/Textures/ForceField2.png");
    // forceField->SetPosition(Vector3D(400 , 300, 0));
    // forceField->SetScale(Vector3D(forceField->GetTexture()->GetTextureData().texWidth,forceField->GetTexture()->GetTextureData().texHeight,0));
    // World::GetInstance()->AddEntity(forceField);


    // Ball* ball = new Ball();
    // ball->SetVelocity(Vector3D(0,0,0));
    // ball->SetShader(basicShader);
    // ball->SetTexture("data/Textures/Ball.png");
    // ball->SetPosition(Vector3D(100, 300, 0));
    // ball->SetScale(Vector3D(ball->GetTexture()->GetTextureData().texWidth,ball->GetTexture()->GetTextureData().texHeight,0));
    // World::GetInstance()->AddEntity(ball);

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


        double mousePositionX;
        double mousePositionY;
        glfwGetCursorPos(win, &mousePositionX, &mousePositionY);
        
        //forceField->SetPosition(Vector3D(mousePositionX, mousePositionY, 0));
        
        //Vector3D distance = ball->GetPosition() - forceField->GetPosition();
        // ball->SetVelocity(direction * -1);

        // printf("Field position: (%f, %f)\n", ball->GetPosition().X, ball->GetPosition().Y);
        // printf("Distance: %f\n", distance.Size());
        //
        // if(distance.Size() <= ball->GetTexture()->GetTextureData().texWidth/4 + forceField->GetTexture()->GetTextureData().texWidth/4)
        // {
        //     printf("COLLIDES\n");
        // }
        
        
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