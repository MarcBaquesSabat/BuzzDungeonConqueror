#pragma once
#include <SDL.h>
#include <stdio.h>
#include "ErrorHandling/SDL_Exception.h"

namespace BuzzRPG {
	class Game
	{
	private:
		bool isRunning{ false };
		SDL_Window* window{ nullptr };
		SDL_Renderer* renderer{ nullptr };
		SDL_Event event;
	public:
		void Init();
		void Loop();
		void Quit();
	private:
		void HandleEvents();
		void Update();
		void Render();
	};
}


