#pragma once
#include "Entity.h"
#include <vector>

//World created with a singleton pattern
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
	float GetDeltaTime();

	void AddEntity(Entity* _entity);
	void SetDeltaTime(float _deltaTime);

	void Tick(float _deltaTime);
	void Draw();
};