#include "Game.h"

bool BuzzRPG::Game::Init()
{
    auto isInitialized = SDL_Init(SDL_INIT_VIDEO) >= 0;

    if (!isInitialized) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return false;
    }


    window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        512, 512, SDL_WINDOW_SHOWN);

    if (window == NULL) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        SDL_Quit();
        return false;
    }

    screenSurface = SDL_GetWindowSurface(window);

    if (screenSurface == nullptr) {
        printf("Surface could not be created! SDL_Error: %s\n", SDL_GetError());
        SDL_Quit();
        return false;
    }

    SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
    SDL_UpdateWindowSurface(window);

    return true;
}

void BuzzRPG::Game::Update()
{
    bool mustQuit = false;
    SDL_Event e;
    while (!mustQuit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                mustQuit = true;
            }
        }
    }
}

void BuzzRPG::Game::Quit()
{

    SDL_FreeSurface(screenSurface);
    screenSurface = NULL;

    SDL_DestroyWindow(window);

    SDL_Quit();
}
