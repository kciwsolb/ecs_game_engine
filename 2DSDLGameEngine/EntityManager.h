#pragma once

#include <string>
#include <vector>
#include <memory>
#include "Entity.h"

class EntityManager {
public:
	static EntityManager &SharedInstance() { static EntityManager entityManager; return entityManager; }
	void Update();
	void LateUpdate();
	Entity* AddEntity(std::string tag);
	void RemoveEntity(Entity* entity);
	unsigned int GetEntityCount();
	Entity* GetEntity(unsigned int id);

private:
	EntityManager();
	unsigned int entityCount;
	std::vector<std::unique_ptr<Entity>> entities;

	void Init();
};
