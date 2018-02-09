#pragma once

#include <string>
#include <map>
#include "SDL.h"

class InputManager {
public:
	static InputManager &SharedInstance() { static InputManager inputManager; return inputManager; }
	bool quit;
	void Update();
	static bool GetButton(std::string buttonName);
	static bool GetButtonDown(std::string buttonName);

private:
	static std::map<std::string, bool> buttons;
	static std::map<std::string, bool> buttonsDown;

	InputManager();
	void Init();
	void PollEvents();
	void ResetButtonsDown();
};
