#include "TankProjectile.h"
#include "Time.h"
#include "TankProjectileExplosion.h"
#include "TankExplosion.h"

TankProjectile::TankProjectile(float xPos, float yPos, Direction direction) {
	Init(xPos, yPos, direction);
}

void TankProjectile::Init(float xPos, float yPos, Direction direction) {
	speed = 0.4f;
	entity = EntityManager::SharedInstance().AddEntity("Projectile");
	maxLife = Time::time + 5000;
	this->direction = direction;
	switch (direction) {
	case UP:
		position = entity->AddComponent<PositionComponent>(entity, xPos, yPos - 32.0f);
		break;
	case DOWN:
		position = entity->AddComponent<PositionComponent>(entity, xPos, yPos + 32.0f);
		break;
	case RIGHT:
		position = entity->AddComponent<PositionComponent>(entity, xPos + 32.0f, yPos);
		break;
	case LEFT:
		position = entity->AddComponent<PositionComponent>(entity, xPos - 32.0f, yPos);
		break;
	}
	collider = entity->AddComponent<ColliderComponent>(entity, true, false, 2, 2);
	sprite = entity->AddComponent<SpriteComponent>(entity, RenderLayer::Projectile, "Assets/projectile.png", 2, 2);
}
	
void TankProjectile::Update() {
	Move();
	CheckCollision();
}

void TankProjectile::Move() {
	if (Time::time > maxLife) {
		isDead = true;
	}

	if (!isDead) {
		switch (direction) {
		case UP:
			position->Set(position->GetX(), position->GetY() - speed * Time::deltaTime);
			break;
		case DOWN:
			position->Set(position->GetX(), position->GetY() + speed * Time::deltaTime);
			break;
		case RIGHT:
			position->Set(position->GetX() + speed * Time::deltaTime, position->GetY());
			break;
		case LEFT:
			position->Set(position->GetX() - speed * Time::deltaTime, position->GetY());
			break;
		}
	}
}

void TankProjectile::CheckCollision() {
	std::vector<Entity*> entityCollisions = PhysicsManager::SharedInstance().GetTriggerCollision(entity);
	if (entityCollisions.size() > 0) {
		for (Entity* e : entityCollisions) {
			if (e->GetTag() == "Player 1" || e->GetTag() == "Player 2") {
				isDead = true;	
				GameObjectManager::SharedInstance().AddGameObject<TankExplosion>(position->GetX(), position->GetY());
				break;
			}
			else if (e->GetTag() != "Projectile") {
				isDead = true;
				GameObjectManager::SharedInstance().AddGameObject<TankProjectileExplosion>(position->GetX(), position->GetY());
				break;
			}
		}
	}
}



