#pragma once

#include <vector>
#include <memory>
#include "GameObject.h"

class GameObjectManager {
public:
	static GameObjectManager &SharedInstance() { static GameObjectManager gameObject; return gameObject; }
	void Update();

	template<typename T, typename... Args> T* AddGameObject(Args &&... args) {
		if (std::is_base_of<GameObject, T>()) {
			std::unique_ptr<T> t = std::make_unique<T>(args...);
			gameObjects.push_back(std::move(t));
			T* tPtr = static_cast<T*>(gameObjects.back().get());
			return tPtr;
		}
		else {
			return nullptr;
		}
	}

	template<typename T> T* RemoveGameObject(GameObject* gameObject) {
		for (auto it = gameObjects.begin(); it != gameObjects.end();) {
			if (T* tPtr = static_cast<T*>(it.get())) {
				if (&*it->get() == gameObject) {
					it = gameObjects.erase(it);
				}
				else {
					it++;
				}
			}
			else {
				it++;
			}
		}		
	}

	void UpdateGameObjects();
private:
	GameObjectManager();
	std::vector<std::unique_ptr<GameObject>> gameObjects;
	void Init();
};
