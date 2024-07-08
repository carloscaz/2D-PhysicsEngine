#pragma once
#include "../glew/GL/glew.h"
#include "../glfw/glfw3.h"

class State
{
private:
	GLFWwindow* m_window;
	static State* m_instance;
	State();
public:
	GLFWwindow* GetWindow();
	static State* Getinstance();

	void SetWindow(GLFWwindow* _win);
};