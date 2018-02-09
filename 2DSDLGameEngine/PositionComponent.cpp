#include "PositionComponent.h"
#include "PhysicsManager.h"
#include <iostream>

PositionComponent::PositionComponent(Entity* entity) {
	Init(entity, 0.0f, 0.0f);
}

PositionComponent::PositionComponent(Entity* entity, float x, float y) {
	Init(entity, x, y);
}

PositionComponent::~PositionComponent() {}

void PositionComponent::Init(Entity* entity, float x, float y) {
	currentX = x;
	currentY = y;
	previousX = x;
	previousY = y;
	targetX = x;
	targetY = y;
	this->entity = entity;
}

void PositionComponent::Update() {
	previousX = currentX;
	previousY = currentY;
	currentX = targetX;
	currentY = targetY;
}

void PositionComponent::LateUpdate() {
	std::vector<Entity*> entityCollisions = PhysicsManager::SharedInstance().GetColliderCollision(entity);
	if (entityCollisions.size() > 0) {
		currentX = previousX;
		currentY = previousY;
	}
}

void PositionComponent::Set(float x, float y) {
	targetX = x;
	targetY = y;
}

void PositionComponent::SetX(float x) {
	targetX = x;
}

void PositionComponent::SetY(float y) {
	targetY = y;
}

float PositionComponent::GetX() {
	return currentX;
}

float PositionComponent::GetY() {
	return currentY;
}

bool PositionComponent::Equals(PositionComponent other) {
	if ((other.GetX() == currentX) && (other.GetY() == currentY)) {
		return true;
	}
	else {
		return false;
	}
}

void PositionComponent::Add(PositionComponent other) {
	Set((currentX + other.GetX()), (currentY + other.GetY()));
}

void PositionComponent::Subtract(PositionComponent other) {
	Set((currentX - other.GetX()), (currentY - other.GetY()));
}

void PositionComponent::Multiply(PositionComponent other) {
	Set((currentX * other.GetX()), (currentY * other.GetY()));
}

void PositionComponent::Divide(PositionComponent other) {
	Set((currentX / other.GetX()), (currentY / other.GetY()));
}


