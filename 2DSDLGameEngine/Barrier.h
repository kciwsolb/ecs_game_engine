#pragma once

#include "GameObject.h"
#include "SDL.h"
#include "PhysicsManager.h"
#include "RenderManager.h"

class Barrier : public GameObject {
public:
	Barrier(float xPos, float yPos);
	void Update();
private:
	const char* barrier;
	PositionComponent* position;
	ColliderComponent* collider;
	SpriteComponent* sprite;

	void Init(float xPos, float yPos);
};