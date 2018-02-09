#include "SpriteComponent.h"
#include "RenderManager.h"
#include <iostream>

SpriteComponent::SpriteComponent(Entity* entity, RenderLayer renderLayer, const char* filePath, int imageWidth, int imageHeight) {
	Init(entity, renderLayer, filePath, imageWidth, imageHeight);
}

SpriteComponent::~SpriteComponent() {
	RenderManager::SharedInstance().RemoveSpriteComponent(this);
	SDL_DestroyTexture(texture);
	for (SDL_Texture* t : textures) {
		SDL_DestroyTexture(t);
	}
}

void SpriteComponent::Init(Entity* entity, RenderLayer renderLayer, const char* filePath, int imageWidth, int imageHeight) {
	multiplier = 2;
	this->entity = entity;
	this->renderLayer = renderLayer;
	position = entity->GetComponent<PositionComponent>();
	texture = RenderManager::SharedInstance().LoadTexture(filePath);
	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = (int)imageWidth * multiplier;
	srcRect.h = (int)imageHeight * multiplier;
	destRect.w = srcRect.w;
	destRect.h = srcRect.h;
	RenderManager::SharedInstance().AddSpriteComponent(this);
}

void SpriteComponent::Update() {
	destRect.x = (int)position->GetX() - srcRect.w / 2;
	destRect.y = (int)position->GetY() - srcRect.h / 2;
}

void SpriteComponent::Draw() {
	RenderManager::SharedInstance().Draw(texture, srcRect, destRect);
}

void SpriteComponent::AddTexture(const char* filePath) {
	textures.push_back(RenderManager::SharedInstance().LoadTexture(filePath));
}

void SpriteComponent::SetTexture(int index) {
	texture = textures[index];
}