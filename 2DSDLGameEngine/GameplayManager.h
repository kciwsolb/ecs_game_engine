#pragma once
#include "Game.cpp"

class GameplayManager {
public:
	static GameplayManager &SharedInstance() { static GameplayManager gameplayManager; return gameplayManager; }

	void Update();
private:
	Game* game = new Game();

	GameplayManager();
	void Init();

};