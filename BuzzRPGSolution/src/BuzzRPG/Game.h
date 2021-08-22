#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include "ErrorHandling/SDL_Exception.h"

namespace BuzzRPG {
	class Game
	{
	private:
		bool m_isRunning{ false };
		SDL_Window* m_window{ nullptr };
		SDL_Renderer* m_renderer{ nullptr };
		SDL_Event m_event;
		SDL_Texture* m_logoTexture{ nullptr };
		SDL_Rect m_sourceTextureRect;
		SDL_Rect m_destinyTextureRect;
		SDL_Texture* m_explosionTexture{ nullptr };
		SDL_Rect m_explosionSourceTextureRect;
		SDL_Rect m_explosionDestinyTextureRect;
		int m_frameIndex;
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


