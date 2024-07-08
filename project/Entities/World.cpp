#include "World.h"

World* World::m_instance = nullptr;

World::World()
{

}

World* World::GetInstance()
{
	if (!m_instance)
	{
		m_instance = new World();
	}

	return m_instance;
}

const std::vector<Entity*>& World::GetEntities() const
{
	return m_entities;
}

const float World::GetDeltaTime()
{
	return deltaTime;
}

void World::AddEntity(Entity* _entity)
{
	m_entities.push_back(_entity);
}

void World::SetDeltaTime(float _deltaTime)
{
	if (_deltaTime > 0)
	{
		deltaTime = _deltaTime;
	}
}

void World::Tick(float _deltaTime)
{
	for (int i = 0; i < m_entities.size(); ++i)
	{
		m_entities[i]->Tick(_deltaTime);
	}
}

void World::Draw()
{
	for (int i = 0; i < m_entities.size(); ++i)
	{
		m_entities[i]->Draw();
	}
}
