#pragma once

#include "GameObject.h"
#include "SDL.h"
#include "InputManager.h"
#include "EntityManager.h"
#include "PhysicsManager.h"
#include "RenderManager.h"
#include "Direction.h"

class Tank : public GameObject {
public:
	Tank(float xPos, float yPos, int playerNumber);
	void Update();
private:
	int playerNumber;
	float fireRate;
	const char* spriteUp;
	const char* spriteDown;
	const char* spriteRight;
	const char* spriteLeft;
	std::string upButton;
	std::string downButton;
	std::string rightButton;
	std::string leftButton;
	std::string fireButton;
	Uint32 nextFire;
	Direction direction;
	PositionComponent* position;
	ColliderComponent* collider;
	SpriteComponent* sprite;

	void Init(float xPos, float yPos, int playerNumber);
	void Move();
	void Fire();
	void CheckCollision();
};