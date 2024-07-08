#ifdef _MSC_VER
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
#endif

#include "../lib/glew/GL/glew.h"
#include "../lib/glfw/glfw3.h"
#include <iostream>
#include <vector>
#include <GL/wglew.h>

#include "../project/Entities/Entity.h"
#include "../project/Entities/Player.h"
#include "../project/OpenGL/Textures/Texture.h"
#include "../project/OpenGL/Utils/GL_Utils.h"
#include "../project//Entities/World.h"
#include "../project/OpenGL/State/State.h"
#include "../project/Math/Matrix3D/Matrix3D.h"
#include "../project/OpenGL/Shaders/Shader.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600




int main() {
	//Init GLFW & Glew
	GLFWwindow* win;
	if(!Init(win, SCREEN_WIDTH, SCREEN_HEIGHT))
	{
		return -1;
	}

	//Shader creation
	Shader* basicShader = Shader::Load("data/SpriteShader/vertex.glsl", "data/SpriteShader/fragment.glsl");
	Shader* animatedShader = Shader::Load("data/AnimatedSprite/vertex.glsl", "data/AnimatedSprite/fragment.glsl");
	
	//Entity creation
	


	//Add entities to world
	World* myWorld = World::GetInstance();


	//Set up env
	SetUp2D(SCREEN_WIDTH, SCREEN_HEIGHT);
	double mousePositionX;
	double mousePositionY;
	glfwSetInputMode(win, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
	
	// main loop
	double lastTime = glfwGetTime();
	while ( !glfwWindowShouldClose(win) && !glfwGetKey(win, GLFW_KEY_ESCAPE) ) {
		// get delta time
		float deltaTime = static_cast<float>(glfwGetTime() - lastTime);
		lastTime = glfwGetTime();
		myWorld->SetDeltaTime(deltaTime);

		glfwGetCursorPos(win, &mousePositionX, &mousePositionY);

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
