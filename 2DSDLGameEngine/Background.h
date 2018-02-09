#pragma once

#include "GameObject.h"
#include "SDL.h"
#include "RenderManager.h"

class Background : public GameObject {
public:
	Background(float xPos, float yPos);
	void Update();
private:
	const char* backgroundFile;
	PositionComponent* position;
	SpriteComponent* sprite;

	void Init(float xPos, float yPos);
};