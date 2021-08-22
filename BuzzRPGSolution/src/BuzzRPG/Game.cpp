#include "Game.h"

void BuzzRPG::Game::Init()
{
    auto isInitialized = SDL_Init(SDL_INIT_VIDEO) >= 0;

    if (!isInitialized) {
        throw SDL_Exception(SDL_GetError());
    }

    SDL_CreateWindowAndRenderer(800, 800, SDL_WINDOW_SHOWN, &m_window, &m_renderer);
    if (m_window == nullptr || m_renderer == nullptr) {
        throw SDL_Exception(SDL_GetError());
    }

    m_isRunning = true;

    SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);

    SDL_Surface* imageSurface = IMG_Load("../../res/imgs/buzzLogo.png");
    m_logoTexture = SDL_CreateTextureFromSurface(m_renderer, imageSurface);

    SDL_QueryTexture(m_logoTexture, nullptr, nullptr, &m_sourceTextureRect.w, &m_sourceTextureRect.h);
    m_destinyTextureRect = m_sourceTextureRect;
    m_destinyTextureRect.x = 0;
    m_destinyTextureRect.y = 0;
    
    SDL_FreeSurface(imageSurface);

    imageSurface = IMG_Load("../../res/imgs/explosion_ss.png");
    m_explosionTexture = SDL_CreateTextureFromSurface(m_renderer, imageSurface);

    //SDL_QueryTexture(m_explosionTexture, nullptr, nullptr, &m_heroSourceTextureRect.w, &m_heroSourceTextureRect.h);
    m_explosionSourceTextureRect.w = m_explosionSourceTextureRect.h = 96;
    m_explosionSourceTextureRect.x = 0;
    m_explosionSourceTextureRect.y = 0;

    m_explosionDestinyTextureRect.x = 10;
    m_explosionDestinyTextureRect.y = 400;
    m_explosionDestinyTextureRect.w = 96;
    m_explosionDestinyTextureRect.h = 96;

    SDL_FreeSurface(imageSurface);
}

void BuzzRPG::Game::Loop()
{
    try {
        while (m_isRunning) {
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
    if (SDL_PollEvent(&m_event)) {
        if (m_event.type == SDL_QUIT) {
            m_isRunning = false;
        }
    }
}

void BuzzRPG::Game::Update()
{
    m_frameIndex = int(((SDL_GetTicks() / 100) % 12));
    m_explosionSourceTextureRect.x = (m_frameIndex % 12) * 96;
}

void BuzzRPG::Game::Render()
{
    SDL_RenderClear(m_renderer);

    SDL_RenderCopy(m_renderer, m_logoTexture, &m_sourceTextureRect, &m_destinyTextureRect);
    SDL_RenderCopy(m_renderer, m_explosionTexture, &m_explosionSourceTextureRect, &m_explosionDestinyTextureRect);

    SDL_RenderPresent(m_renderer);
}


void BuzzRPG::Game::Quit()
{
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_window);

    SDL_Quit();
}
