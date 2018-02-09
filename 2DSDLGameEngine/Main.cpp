#include "SDL.h"
#include "SDL_image.h"
#include "Time.h"
#include "InputManager.h"
#include "GameplayManager.h"
#include "GameObjectManager.h"
#include "EntityManager.h"
#include "PhysicsManager.h"
#include "RenderManager.h"


int main(int argc, char* args[]) {
	while (InputManager::SharedInstance().quit == false) {
		Time::Update();
		InputManager::SharedInstance().Update();
		GameplayManager::SharedInstance().Update();
		GameObjectManager::SharedInstance().Update();
		EntityManager::SharedInstance().Update();
		PhysicsManager::SharedInstance().Update();
		EntityManager::SharedInstance().LateUpdate();
		RenderManager::SharedInstance().Update();
	}
	return 0;
}