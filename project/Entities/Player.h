#pragma once
#include "Entity.h"
#include "../glew/GL/glew.h"
#include "../glfw/glfw3.h"


class Player : public Entity
{
private:
	float m_fps = 1;
	float m_elapsedTime = 0.0f;
	int m_currentFrame = 0;
	int m_numFrames = 1;

	Vector3D m_velocity;

public:
	Player();
	const Vector3D& GetPosition() const;
	const Vector3D& GetVelocity() const;
	
	void SetVelocity(const Vector3D& _vel);

	void SetFPS(float _fps);
	void SetNumFrames(float _numFrames);

	void Tick(float _deltaTime) override;
	void Draw();

	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
};