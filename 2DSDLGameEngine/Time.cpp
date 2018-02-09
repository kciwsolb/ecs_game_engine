#include "Time.h"

Uint64 Time::NOW = SDL_GetPerformanceCounter();
Uint64 Time::LAST = 0;
Uint32 Time::time = 0;
float Time::deltaTime = 0;

void Time::Update() {
	time = SDL_GetTicks();
	UpdateDeltaTime();
}

void Time::UpdateDeltaTime() {
	 LAST = NOW;
	 NOW = SDL_GetPerformanceCounter();
	 deltaTime = ((NOW - LAST) * 1000 / (float)SDL_GetPerformanceFrequency());
}