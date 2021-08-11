#include "Game.h"

void BuzzRPG::Game::Init()
{
    auto isInitialized = SDL_Init(SDL_INIT_VIDEO) >= 0;

    if (!isInitialized) {
        throw SDL_Exception(SDL_GetError());
    }

    SDL_CreateWindowAndRenderer(512, 512, SDL_WINDOW_SHOWN, &window, &renderer);
    if (window == nullptr || renderer == nullptr) {
        throw SDL_Exception(SDL_GetError());
    }

    isRunning = true;

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
}

void BuzzRPG::Game::Loop()
{
    try {
        while (isRunning) {
            HandleEvents();

            Update();

            Render();
        }
    }
    catch (std::exception exception) {
        fprintf(stderr, exception.what());
        SDL_Quit();
    }
}

void BuzzRPG::Game::HandleEvents()
{
    if (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            isRunning = false;
        }
    }
}

void BuzzRPG::Game::Update()
{
    
}

void BuzzRPG::Game::Render()
{
    SDL_RenderClear(renderer);

    SDL_RenderPresent(renderer);
}


void BuzzRPG::Game::Quit()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();
}
