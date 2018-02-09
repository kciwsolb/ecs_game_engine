#include "TankExplosion.h"
#include "Time.h"

TankExplosion::TankExplosion(float xPos, float yPos) {
	Init(xPos, yPos);
}

void TankExplosion::Update() {
	UpdateSprite();
}

void TankExplosion::Init(float xPos, float yPos) {
	counter = 0;
	speed = 0.1f;
	nextTime = (Uint32)(Time::time + speed * 1000.0f);
	entity = EntityManager::SharedInstance().AddEntity("Barrier");
	tank_explosion_1 = "Assets/tank_explosion_1.png";
	tank_explosion_2 = "Assets/tank_explosion_2.png";
	tank_explosion_3 = "Assets/tank_explosion_3.png";
	position = entity->AddComponent<PositionComponent>(entity, xPos, yPos);
	sprite = entity->AddComponent<SpriteComponent>(entity, RenderLayer::Effect, tank_explosion_1, 32, 32);
	sprite->AddTexture(tank_explosion_2);
	sprite->AddTexture(tank_explosion_3);
}

void TankExplosion::UpdateSprite() {
	if (nextTime <= Time::time) {
		if (counter >= 2) {
			isDead = true;
		}
		else {
			nextTime = (Uint32)(Time::time + speed * 1000.0f);
			sprite->SetTexture(counter);
			counter++;
		}
	}
}