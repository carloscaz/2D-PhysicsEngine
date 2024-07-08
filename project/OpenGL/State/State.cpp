#include "State.h"

State* State::m_instance = nullptr;

State::State()
{

}
GLFWwindow* State::GetWindow()
{
	return m_window;
}

State* State::Getinstance()
{
	if (!m_instance)
	{
		m_instance = new State();
	}

	return m_instance;
}

void State::SetWindow(GLFWwindow* _win)
{
	if (_win)
	{
		m_window = _win;
	}
}
