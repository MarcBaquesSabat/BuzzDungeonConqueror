#pragma once
#include <SDL.h>
#include <stdio.h>

namespace BuzzRPG {
	class Game
	{
	private:
		SDL_Window* window{ nullptr };
		SDL_Surface* screenSurface{ nullptr };
	public:
		bool Init();
		void Update();
		void Quit();
	};
}


