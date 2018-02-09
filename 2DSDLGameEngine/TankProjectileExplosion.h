#pragma once

#include "GameObject.h"
#include "SDL.h"
#include "RenderManager.h"

class TankProjectileExplosion : public GameObject {
public:
	TankProjectileExplosion(float xPos, float yPos);
	void Update();
private:
	int counter;
	float speed;
	Uint32 nextTime;
	const char* projectile_explosion_1;
	const char* projectile_explosion_2;
	const char* projectile_explosion_3;
	PositionComponent* position;
	SpriteComponent* sprite;

	void Init(float xPos, float yPos);
	void UpdateSprite();
};
