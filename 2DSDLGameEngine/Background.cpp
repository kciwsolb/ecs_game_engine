#include "Background.h"

Background::Background(float xPos, float yPos) {
	Init(xPos, yPos);
}

void Background::Update() {}

void Background::Init(float xPos, float yPos) {
	entity = EntityManager::SharedInstance().AddEntity("Barrier");
	backgroundFile = "Assets/background.png";
	position = entity->AddComponent<PositionComponent>(entity, xPos, yPos);
	sprite = entity->AddComponent<SpriteComponent>(entity, RenderLayer::Back, backgroundFile, 512, 512);
}
