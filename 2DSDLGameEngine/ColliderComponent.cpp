#include "ColliderComponent.h"
#include "PhysicsManager.h"
#include <iostream>
ColliderComponent::ColliderComponent(Entity* entity, bool isTrigger, bool isStatic, int sizeX, int sizeY) {
	Init(entity, isTrigger, isStatic, sizeX, sizeY);
}

ColliderComponent::~ColliderComponent() {
	if (isTrigger) {
		PhysicsManager::SharedInstance().RemoveStaticColliderComponent(this);
	}
	else {
		PhysicsManager::SharedInstance().RemoveDynamicColliderComponent(this);
	}
}

void ColliderComponent::Init(Entity* entity, bool isTrigger, bool isStatic, int sizeX, int sizeY) {
	multiplier = 2;
	this->sizeX = sizeX;
	this->sizeY = sizeY;
	this->entity = entity;
	this->isTrigger = isTrigger;
	this->isStatic = isStatic;
	position = entity->GetComponent<PositionComponent>();
	rect.x = (int)position->GetX() - sizeX * multiplier / 2;
	rect.y = (int)position->GetY() - sizeY * multiplier/ 2;
	rect.h = sizeY * multiplier;
	rect.w = sizeX * multiplier;
	if (isStatic) {
		PhysicsManager::SharedInstance().AddStaticColliderComponent(this);
	}
	else {
		PhysicsManager::SharedInstance().AddDynamicColliderComponent(this);
	}
}

void ColliderComponent::Update() {
	rect.x = (int)position->GetX() - sizeX * multiplier / 2;
	rect.y = (int)position->GetY() - sizeY * multiplier / 2;
}

bool ColliderComponent::GetIsTrigger() {
	return isTrigger;
}

bool ColliderComponent::GetIsStatic() {
	return isStatic;
}

Entity* ColliderComponent::GetEntity() {
	return entity;
}

SDL_Rect ColliderComponent::GetCollisionRect() {
	return rect;
}