#pragma once
#include "../glfw/glfw3.h"

//State class with a singleton pattern
class State
{
private:
	GLFWwindow* m_window;
	static State* m_instance;
	State(){};
public:
	GLFWwindow* GetWindow();
	static State* Getinstance();

	void SetWindow(GLFWwindow* _win);
};