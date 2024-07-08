#pragma once
#include "Entity.h"
#include "../glew/GL/glew.h"
#include "../glfw/glfw3.h"


class Player : public Entity
{
private:
	Vector3D m_position;
	Vector3D m_velocity;
	GLFWwindow* m_window;

public:
	Player();
	const Vector3D& GetPosition() const;
	const Vector3D& GetVelocity() const;

	void SetPosition(const Vector3D& _pos);
	void SetVelocity(const Vector3D& _vel);
	void SetWindow(GLFWwindow* _win);

	void Tick(float _deltaTime) override;
	void Draw();

	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
};