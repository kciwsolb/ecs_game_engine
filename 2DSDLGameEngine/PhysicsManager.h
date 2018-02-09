#pragma once

#include <vector>
#include <map>
#include "SDL.h"
#include "ColliderComponent.h"

class PhysicsManager {
public:
	static PhysicsManager &SharedInstance() { static PhysicsManager physicsManager; return physicsManager; }
	void Update();
	void AddDynamicColliderComponent(ColliderComponent* colliderComponent);
	void AddStaticColliderComponent(ColliderComponent* colliderComponent);
	void RemoveDynamicColliderComponent(ColliderComponent* colliderComponent);
	void RemoveStaticColliderComponent(ColliderComponent* colliderComponent);
	std::vector<Entity*> GetColliderCollision(Entity* entity);
	std::vector<Entity*> GetTriggerCollision(Entity* entity);

private:
	std::vector<ColliderComponent*> staticColliders;
	std::vector<ColliderComponent*> dynamicColliders;
	std::vector<std::pair<Entity*, Entity*>> colliderCollisions;
	std::vector<std::pair<Entity*, Entity*>> triggerCollisions;

	PhysicsManager();
	void Init();
	void ClearCollisions();
	void CheckCollisions();
	bool CheckRectCollision(SDL_Rect a, SDL_Rect b);
};
