#pragma once

#include "GameObject.h"
#include "SDL.h"
#include "InputManager.h"
#include "GameObjectManager.h"
#include "EntityManager.h"
#include "PhysicsManager.h"
#include "RenderManager.h"
#include "Direction.h"

class TankProjectile : public GameObject {
public:
	TankProjectile(float xPos, float yPos, Direction direction);
	void Update();
private:
	float speed;
	Uint32 maxLife;
	Direction direction;
	PositionComponent* position;
	ColliderComponent* collider;
	SpriteComponent* sprite;

	void Init(float xPos, float yPos, Direction direction);
	void CheckCollision();
	void Move();
};
