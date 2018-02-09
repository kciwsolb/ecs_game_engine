#pragma once

#include "GameObject.h"
#include "SDL.h"
#include "RenderManager.h"

class TankExplosion : public GameObject {
public:
	TankExplosion(float xPos, float yPos);
	void Update();
private:
	int counter;
	float speed;
	Uint32 nextTime;
	const char* tank_explosion_1;
	const char* tank_explosion_2;
	const char* tank_explosion_3;
	PositionComponent* position;
	SpriteComponent* sprite;
	void Init(float xPos, float yPos);
	void UpdateSprite();
};