#include "Tank.h"
#include "Time.h"
#include "TankProjectile.h"

Tank::Tank(float posX, float posY, int playerNumber) {
	Init(posX, posY, playerNumber);
}

void Tank::Update() {
	Move();
	Fire();
	CheckCollision();
}

	
void Tank::Init(float xPos, float yPos, int playerNumber) {
	std::string num = std::to_string(playerNumber);
	std::string partialTag = "Player ";
	std::string tag = partialTag + num;
	entity = EntityManager::SharedInstance().AddEntity(tag);
	this->playerNumber = playerNumber;
	fireRate = 0.5f;
	nextFire = 0;
	if (playerNumber == 1) {
		spriteUp = "Assets/tank_red_up.png";
		spriteDown = "Assets/tank_red_down.png";
		spriteRight = "Assets/tank_red_right.png";
		spriteLeft = "Assets/tank_red_left.png";
		upButton = "P1 UP";
		downButton = "P1 DOWN";
		rightButton = "P1 RIGHT";
		leftButton = "P1 LEFT";
		fireButton = "P1 FIRE";
		direction = LEFT;
		position = entity->AddComponent<PositionComponent>(entity, xPos, yPos);
		collider = entity->AddComponent<ColliderComponent>(entity, false, false, 22, 22);
		sprite = entity->AddComponent<SpriteComponent>(entity, RenderLayer::Player, spriteLeft, 32, 32);
	}
	else if (playerNumber == 2) {
		spriteUp = "Assets/tank_blue_up.png";
		spriteDown = "Assets/tank_blue_down.png";
		spriteRight = "Assets/tank_blue_right.png";
		spriteLeft = "Assets/tank_blue_left.png";
		upButton = "P2 UP";
		downButton = "P2 DOWN";
		rightButton = "P2 RIGHT";
		leftButton = "P2 LEFT";
		fireButton = "P2 FIRE";
		direction = RIGHT;
		position = entity->AddComponent<PositionComponent>(entity, xPos, yPos);
		collider = entity->AddComponent<ColliderComponent>(entity, false, false, 22, 22);
		sprite = entity->AddComponent<SpriteComponent>(entity, RenderLayer::Player, spriteRight, 32, 32);
	}
	sprite->AddTexture(spriteUp);
	sprite->AddTexture(spriteDown);
	sprite->AddTexture(spriteRight);
	sprite->AddTexture(spriteLeft);
}

void Tank::Move() {
	if (InputManager::GetButton(rightButton)) {
		position->SetX(position->GetX() + 0.1f * Time::deltaTime);
		sprite->SetTexture(2);
		direction = RIGHT;
	}
	else if (InputManager::GetButton(leftButton)) {
		position->SetX(position->GetX() - 0.1f * Time::deltaTime);
		sprite->SetTexture(3);
		direction = LEFT;
	}
	else if (InputManager::GetButton(upButton)) {
		position->SetY(position->GetY() - 0.1f * Time::deltaTime);
		sprite->SetTexture(0);
		direction = UP;
	}
	else if (InputManager::GetButton(downButton)) {
		position->SetY(position->GetY() + 0.1f * Time::deltaTime);
		sprite->SetTexture(1);
		direction = DOWN;
	}
}

void Tank::Fire() {
	if (InputManager::GetButton(fireButton)) {
		if (nextFire <= Time::time) {
			nextFire = (Uint32)(Time::time + fireRate * 1000.0f);
			GameObjectManager::SharedInstance().AddGameObject<TankProjectile>(position->GetX(), position->GetY(), direction);
		}
	}
}

void Tank::CheckCollision() {
	std::vector<Entity*> entityCollisions = PhysicsManager::SharedInstance().GetTriggerCollision(entity);
	if (entityCollisions.size() > 0) {
		for (Entity* e : entityCollisions) {
			if (e->GetTag() == "Projectile") {
				isDead = true;
				break;
			}
		}
	}
}
