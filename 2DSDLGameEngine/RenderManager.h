#pragma once

#include <vector>
#include <map>
#include "SDL.h"
#include "SDL_image.h"
#include "SpriteComponent.h"

class RenderManager {
public:
	static RenderManager &SharedInstance() { static RenderManager renderManager(640, 640); return renderManager; }

	void Init(int windowY, int windowX);
	void Update();
	void Draw(SDL_Texture* texture, SDL_Rect srcRect, SDL_Rect destRect);
	void AddSpriteComponent(SpriteComponent* spriteComponent);
	void RemoveSpriteComponent(SpriteComponent* spriteComponent);
	SDL_Window* GetWindow();
	SDL_Renderer* GetRenderer();
	SDL_Texture* LoadTexture(const char* filePath);
	~RenderManager();
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	std::map<int, std::vector<SpriteComponent*>> spriteComponents;

	RenderManager(int windowY, int windowX);
	
};
