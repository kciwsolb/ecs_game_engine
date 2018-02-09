#include "TankProjectileExplosion.h"
#include "Time.h"

TankProjectileExplosion::TankProjectileExplosion(float xPos, float yPos) {
	Init(xPos, yPos);
}

void TankProjectileExplosion::Update() {
	UpdateSprite();
}

void TankProjectileExplosion::Init(float xPos, float yPos) {
	counter = 0;
	speed = 0.1f;
	nextTime = (Uint32)(Time::time + speed * 1000.0f);
	entity = EntityManager::SharedInstance().AddEntity("Barrier");
	projectile_explosion_1 = "Assets/projectile_explosion_1.png";
	projectile_explosion_2 = "Assets/projectile_explosion_2.png";
	projectile_explosion_3 = "Assets/projectile_explosion_3.png";
	position = entity->AddComponent<PositionComponent>(entity, xPos, yPos);
	sprite = entity->AddComponent<SpriteComponent>(entity, RenderLayer::Effect, projectile_explosion_1, 8, 8);
	sprite->AddTexture(projectile_explosion_2);
	sprite->AddTexture(projectile_explosion_3);
}

void TankProjectileExplosion::UpdateSprite() {
	if (nextTime <= Time::time) {
		if (counter >= 2) {
			isDead = true;
		}
		else {
			nextTime = (Uint32)Time::time + speed * 1000.0f;
			sprite->SetTexture(counter);
			counter++;
		}
	}
}