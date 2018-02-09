#include "PhysicsManager.h"
#include "SDL.h"

#include <string>
#include <iostream>
PhysicsManager::PhysicsManager() {
	Init();
}

void  PhysicsManager::Init() {

}

void  PhysicsManager::Update() {
	ClearCollisions();
	CheckCollisions();
}

void PhysicsManager::AddDynamicColliderComponent(ColliderComponent* colliderComponent) {
	dynamicColliders.push_back(colliderComponent);
}

void PhysicsManager::AddStaticColliderComponent(ColliderComponent* colliderComponent) {
	staticColliders.push_back(colliderComponent);
}

void PhysicsManager::RemoveDynamicColliderComponent(ColliderComponent* colliderComponent) {
	for (auto it = dynamicColliders.begin(); it != dynamicColliders.end();) {
		if (*it == colliderComponent) {
			it = dynamicColliders.erase(it);
		}
		else {
			it++;
		}
	}
}

void PhysicsManager::RemoveStaticColliderComponent(ColliderComponent* colliderComponent) {
	for (auto it = staticColliders.begin(); it != staticColliders.end();) {
		if (*it == colliderComponent) {
			it = staticColliders.erase(it);
		}
		else {
			it++;
		}
	}
}

void PhysicsManager::ClearCollisions() {
	colliderCollisions.clear();
	triggerCollisions.clear();
}

void PhysicsManager::CheckCollisions() {
	/*Checking dynamic against dynamic*/
	for (ColliderComponent* c1 : dynamicColliders) {
		for (ColliderComponent* c2 : dynamicColliders) {
			if (&*c1 != &*c2) {
				if (CheckRectCollision(c1->GetCollisionRect(), c2->GetCollisionRect())) {
					if (c1->GetIsTrigger() || c2->GetIsTrigger()) {
						triggerCollisions.push_back(std::pair<Entity*, Entity*>(c1->GetEntity(), c2->GetEntity()));
					}
					else {
						colliderCollisions.push_back(std::pair<Entity*, Entity*>(c1->GetEntity(), c2->GetEntity()));
					}
				}
			}
		}
	}
	/*Checking dynamic against static*/
	for (ColliderComponent* c1 : dynamicColliders) {
		for (ColliderComponent* c2 : staticColliders) {
			if (CheckRectCollision(c1->GetCollisionRect(), c2->GetCollisionRect())) {
				if (c1->GetIsTrigger() || c2->GetIsTrigger()) {
					triggerCollisions.push_back(std::pair<Entity*, Entity*>(c1->GetEntity(), c2->GetEntity()));
				}
				else {
					colliderCollisions.push_back(std::pair<Entity*, Entity*>(c1->GetEntity(), c2->GetEntity()));
				}
			}
		}
	}
}

bool PhysicsManager::CheckRectCollision(SDL_Rect a, SDL_Rect b) {
	SDL_Rect result;
	if (SDL_IntersectRect(&a, &b, &result) == SDL_TRUE) {
		return true;
	}
	return false;
}

std::vector<Entity*> PhysicsManager::GetColliderCollision(Entity* entity) {
	std::vector<Entity*> entities;
	for (std::pair<Entity*, Entity*> p : colliderCollisions) {
		if (p.first == entity) {
			entities.push_back(p.second);;
		}
		else if (p.second == entity) {
			entities.push_back(p.first);
		}
	}
	return entities;
};

std::vector<Entity*> PhysicsManager::GetTriggerCollision(Entity* entity) {
	std::vector<Entity*> entities;
	for (std::pair<Entity*, Entity*> p : triggerCollisions) {
		if (p.first == entity) {
			entities.push_back(p.second);
		}
		else if (p.second == entity) {
			entities.push_back(p.first);
		}
	}
	return entities;
};
