#include "Block.h"
#include "Time.h"

Block::Block(float xPos, float yPos) {
	Init(xPos, yPos);
}

void Block::Update() {
	CheckCollision();
}

void Block::Init(float xPos, float yPos) {
	entity = EntityManager::SharedInstance().AddEntity("Barrier");
	health = 4;
	damageRate = 0.18f;
	nextDamage = 0;
	block_normal = "Assets/block_normal.png";
	block_damaged_1 = "Assets/block_damaged_1.png";
	block_damaged_2 = "Assets/block_damaged_2.png";
	block_damaged_3 = "Assets/block_damaged_3.png";
	position = entity->AddComponent<PositionComponent>(entity, xPos, yPos);
	collider = entity->AddComponent<ColliderComponent>(entity, false, true, 16, 16);
	sprite = entity->AddComponent<SpriteComponent>(entity, RenderLayer::Prop, block_normal, 16, 16);
	sprite->AddTexture(block_normal);
	sprite->AddTexture(block_damaged_1);
	sprite->AddTexture(block_damaged_2);
	sprite->AddTexture(block_damaged_3);
}

void Block::CheckCollision() {
	std::vector<Entity*> entityCollisions = PhysicsManager::SharedInstance().GetTriggerCollision(entity);
	if (entityCollisions.size() > 0) {
		for (Entity* e : entityCollisions) {
			if (e->GetTag() == "Projectile") {
				if (nextDamage <= Time::time) {
					nextDamage = (Uint32)(Time::time + damageRate * 1000.0f);
					health--;
					if (health <= 0) {
						isDead = true;
					}
					else {
						UpdateSprite();
					}
				}
			}
		}
	}
}

void Block::UpdateSprite() {
	switch (health) {
	case 3:
		sprite->SetTexture(1);
		break;
	case 2:
		sprite->SetTexture(2);
		break;
	case 1:
		sprite->SetTexture(3);
		break;
	}
}