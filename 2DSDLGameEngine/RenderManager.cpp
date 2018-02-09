#include "RenderManager.h"

RenderManager::RenderManager(int windowY, int windowX) {
	Init(windowY, windowX);
}

void RenderManager::Init(int windowY, int windowX) {
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		SDL_Quit();
	}
	window = SDL_CreateWindow("Tanks!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowX, windowY, NULL);
	if (window == nullptr) {
		SDL_Quit();
	}
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
	if (renderer == nullptr) {
		SDL_DestroyWindow(window);
		SDL_Quit();
	}
	for (int i = 0; i < RenderLayer::EnumLast; i++) {
		spriteComponents.insert(std::make_pair(i, std::vector<SpriteComponent*>()));
	}
}

void RenderManager::Update() {
	SDL_RenderClear(renderer);
	for (std::pair<int, std::vector<SpriteComponent*>> p : spriteComponents) {
		for (SpriteComponent* s : p.second) {
			s->Draw();
		}
	}
	SDL_RenderPresent(renderer);
}

void RenderManager::Draw(SDL_Texture* texture, SDL_Rect srcRect, SDL_Rect destRect) {
	SDL_RenderCopy(renderer, texture, &srcRect, &destRect);
}

void RenderManager::AddSpriteComponent(SpriteComponent* spriteComponent) {
	spriteComponents[spriteComponent->renderLayer].push_back(spriteComponent);
}

void RenderManager::RemoveSpriteComponent(SpriteComponent* spriteComponent) {
	if (spriteComponents.size() > 0) {
		for (auto it1 = spriteComponents.begin(); it1 != spriteComponents.end(); it1++) {
			for (auto it2 = it1->second.begin(); it2 != it1->second.end();) {
				if (*it2 == spriteComponent) {
					it2 = it1->second.erase(it2);
				}
				else {
					it2++;
				}
			}
		}
	}
}

SDL_Window* RenderManager::GetWindow() {
	return window;
}

SDL_Renderer* RenderManager::GetRenderer() {
	return renderer;
}

SDL_Texture* RenderManager::LoadTexture(const char* filePath) {
	SDL_Surface* surface = IMG_Load(filePath);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
	return texture;
}

RenderManager::~RenderManager() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
}