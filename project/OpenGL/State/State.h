#pragma once
#include "../glfw/glfw3.h"
#include "../../Math/Vector2D/Vector2D.h"

//State class with a singleton pattern
class State
{
private:
	GLFWwindow* m_window;
	static State* m_instance;
	Vector2D m_windowSize;
	State(){};
public:
	GLFWwindow* GetWindow() const;
	Vector2D GetWindowSize() const;
	static State* Getinstance();

	void SetWindow(GLFWwindow* _win);
	void SetWindowsSize(const Vector2D& _value);
};