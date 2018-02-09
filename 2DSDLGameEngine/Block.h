#pragma once

#include "GameObject.h"
#include "SDL.h"
#include "PhysicsManager.h"
#include "RenderManager.h"

class Block : public GameObject {
public:
	Block(float xPos, float yPos);
	void Update();
private:
	int health;
	float damageRate;
	const char* block_normal;
	const char* block_damaged_1;
	const char* block_damaged_2;
	const char* block_damaged_3;
	Uint32 nextDamage;
	PositionComponent* position;
	ColliderComponent* collider;
	SpriteComponent* sprite;

	void Init(float xPos, float yPos);
	void CheckCollision();
	void UpdateSprite();
};
