#pragma once

#include "Component.h"
#include <vector>
#include "SDL.h"
#include "Entity.h"
#include "PositionComponent.h"
#include "RenderLayer.h"

struct SpriteComponent : Component {
public:
	RenderLayer renderLayer;

	SpriteComponent(Entity* entity, RenderLayer renderLayer, const char* filePath, int imageWidth, int imageHeight);
	~SpriteComponent();
	void Init(Entity* entity, RenderLayer renderLayer, const char* filePath, int imageWidth, int imageHeight);
	void Update();
	void Draw();
	void AddTexture(const char* filePath);
	void SpriteComponent::SetTexture(int index);
private:
	int multiplier;
	Entity* entity;
	PositionComponent* position;
	SDL_Texture* texture;
	std::vector<SDL_Texture*> textures;
	SDL_Rect srcRect, destRect;
};