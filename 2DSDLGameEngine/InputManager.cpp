#include "InputManager.h"

std::map<std::string, bool> InputManager::buttons = {
	//Set buttons for game here.
	{ "P1 UP", false },
	{ "P1 DOWN", false },
	{ "P1 RIGHT", false },
	{ "P1 LEFT", false },
	{ "P2 UP", false },
	{ "P2 DOWN", false },
	{ "P2 RIGHT", false },
	{ "P2 LEFT", false },
	{ "P1 FIRE", false },
	{ "P2 FIRE", false }
};

std::map<std::string, bool> InputManager::buttonsDown = {
	//Set buttons for game here.
	{ "P1 UP", false },
	{ "P1 DOWN", false },
	{ "P1 RIGHT", false },
	{ "P1 LEFT", false },
	{ "P2 UP", false },
	{ "P2 DOWN", false },
	{ "P2 RIGHT", false },
	{ "P2 LEFT", false },
	{ "P1 FIRE", false },
	{ "P2 FIRE", false }
};

InputManager::InputManager() {
	Init();
}

void InputManager::Init() {
	quit = false;
}

void InputManager::Update() {
	ResetButtonsDown();
	PollEvents();

}

void InputManager::ResetButtonsDown() {
	for (std::pair<std::string, bool> p : buttonsDown) {
		p.second = false;
	}
}

void InputManager::PollEvents() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			quit = true;
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.scancode) {
			case SDL_SCANCODE_UP:
				buttons.at("P1 UP") = true;
				buttonsDown.at("P1 UP") = true;
				break;
			case SDL_SCANCODE_DOWN:
				buttons.at("P1 DOWN") = true;
				buttonsDown.at("P1 DOWN") = true;
				break;
			case SDL_SCANCODE_RIGHT:
				buttons.at("P1 RIGHT") = true;
				buttonsDown.at("P1 RIGHT") = true;
				break;
			case SDL_SCANCODE_LEFT:
				buttons.at("P1 LEFT") = true;
				buttonsDown.at("P1 LEFT") = true;
				break;
			case SDL_SCANCODE_W:
				buttons.at("P2 UP") = true;
				buttonsDown.at("P2 UP") = true;
				break;
			case SDL_SCANCODE_S:
				buttons.at("P2 DOWN") = true;
				buttonsDown.at("P2 DOWN") = true;
				break;
			case SDL_SCANCODE_D:
				buttons.at("P2 RIGHT") = true;
				buttonsDown.at("P2 RIGHT") = true;
				break;
			case SDL_SCANCODE_A:
				buttons.at("P2 LEFT") = true;
				buttonsDown.at("P2 LEFT") = true;
				break;
			case SDL_SCANCODE_RCTRL:
				buttons.at("P1 FIRE") = true;
				buttonsDown.at("P1 FIRE") = true;
				break;
			case SDL_SCANCODE_SPACE:
				buttons.at("P2 FIRE") = true;

				break;
			}
			break;
		case SDL_KEYUP:
			switch (event.key.keysym.scancode) {
			case SDL_SCANCODE_UP:
				buttons.at("P1 UP") = false;
				break;
			case SDL_SCANCODE_DOWN:
				buttons.at("P1 DOWN") = false;
				break;
			case SDL_SCANCODE_RIGHT:
				buttons.at("P1 RIGHT") = false;
				break;
			case SDL_SCANCODE_LEFT:
				buttons.at("P1 LEFT") = false;
				break;
			case SDL_SCANCODE_W:
				buttons.at("P2 UP") = false;
				break;
			case SDL_SCANCODE_S:
				buttons.at("P2 DOWN") = false;
				break;
			case SDL_SCANCODE_D:
				buttons.at("P2 RIGHT") = false;
				break;
			case SDL_SCANCODE_A:
				buttons.at("P2 LEFT") = false;
				break;
			case SDL_SCANCODE_RCTRL:
				buttons.at("P1 FIRE") = false;
				break;
			case SDL_SCANCODE_SPACE:
				buttons.at("P2 FIRE") = false;
				break;
			}
			break;
		}
	}
}

/*Returns true while the specified button is being held down.*/
bool InputManager::GetButton(std::string buttonName) {
	auto button = buttons.find(buttonName);
	if (button != buttons.end()) {
		if (button->second == true)
		return true;
	}
	return false;
}

/*Returns true on the frame that the specified button is pressed.*/
bool InputManager::GetButtonDown(std::string buttonName) {
	auto button = buttonsDown.find(buttonName);
	if (button != buttonsDown.end()) {
		if (button->second == true)
			return true;
	}
	return false;
}