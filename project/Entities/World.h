#pragma once
#include <iostream>
#include "Entity.h"
#include <vector>

class World
{
private:
	World();
	static World* m_instance;
	std::vector<Entity*> m_entities;
	float deltaTime;
public:
	static World* GetInstance();

	const std::vector<Entity*>& GetEntities() const;
	const float GetDeltaTime();

	void AddEntity(Entity* _entity);
	void SetDeltaTime(float _deltaTime);

	std::vector<Entity*>& GetEntities();

	void Tick(float _deltaTime);
	void Draw();
};