#pragma once

#include "SDL.h"

struct Time {
public:
	static Uint64 NOW;
	static Uint64 LAST;
	static Uint32 time;
	static float deltaTime;

	static void Update();
private:
	static void UpdateDeltaTime();
};