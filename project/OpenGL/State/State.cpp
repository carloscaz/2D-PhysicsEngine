#include "State.h"

State* State::m_instance = nullptr;


GLFWwindow* State::GetWindow() const
{
	return m_window;
}

Vector2D State::GetWindowSize() const
{
	return m_windowSize;
}

State* State::Getinstance()
{
	if (!m_instance)
	{
		m_instance = new State();
	}

	return m_instance;
}

//Set GLFW window
void State::SetWindow(GLFWwindow* _win)
{
	if (_win)
	{
		m_window = _win;
	}
}

void State::SetWindowsSize(const Vector2D& _value)
{
	m_windowSize = _value;
}
