#pragma once

#include "Component.h"
#include "SDL.h"
#include "Entity.h"
#include "PositionComponent.h"
#include "Vector2.h"

struct ColliderComponent : Component {
public:
	ColliderComponent(Entity* entity, bool isTrigger, bool isStatic, int sizeX, int sizeY);
	~ColliderComponent();
	void Init(Entity* entity, bool isTrigger, bool isStatic, int sizeX, int sizeY);
	void Update();
	bool GetIsTrigger();
	bool GetIsStatic();
	SDL_Rect GetCollisionRect();
	Entity* GetEntity();
private:
	int multiplier;
	int sizeX;
	int sizeY;
	bool isTrigger; /*Colliders that trigger collision but do not impair movement.*/
	bool isStatic; /*Static colliders are colliders that do not move. Static colliders cannot collide with other static colliders.*/
	Entity* entity;
	PositionComponent* position;
	SDL_Rect rect;
};
