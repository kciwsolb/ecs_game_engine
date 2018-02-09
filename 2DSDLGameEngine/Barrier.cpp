#include "Barrier.h"

Barrier::Barrier(float xPos, float yPos) {
	Init(xPos, yPos);
}

void Barrier::Update() {}

void Barrier::Init(float xPos, float yPos) {
	entity = EntityManager::SharedInstance().AddEntity("Barrier");
	barrier = "Assets/barrier.png";
	position = entity->AddComponent<PositionComponent>(entity, xPos, yPos);
	collider = entity->AddComponent<ColliderComponent>(entity, false, true, 16, 16);
	sprite = entity->AddComponent<SpriteComponent>(entity, RenderLayer::Prop, barrier, 16, 16);
}