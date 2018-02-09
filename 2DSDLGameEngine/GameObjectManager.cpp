#include "GameObjectManager.h"
#include "TankExplosion.h"
#include "Block.h"
GameObjectManager::GameObjectManager() {
	Init();
}

void GameObjectManager::Init() {

}

void GameObjectManager::Update() {
	UpdateGameObjects();
}

void GameObjectManager::UpdateGameObjects() {
	for (auto it = gameObjects.begin(); it != gameObjects.end();) {
		if (it->get()->GetIsDead() == true) {
			it = gameObjects.erase(it);
		}
		else {
			int size = gameObjects.size();
			it->get()->Update();
			if (size == gameObjects.size()) {
				it++;
			}
			else {
				it = gameObjects.begin() + (size - 1);
			}
		}
	}
}
