#include "Game.h"

Game::Game()
{
    cout << "Game class `Created`" << endl;
}

Game::~Game()
{
    cout << "Game class `Destroyed`" << endl;
}

init_response_t Game::Init(const char * title, int x, int y, int w, int h, uint32_t flags)
{
    int init = SDL_Init(SDL_INIT_EVERYTHING);

    if (init != 0)
    {
        cout << "Error: " << SDL_GetError() << endl;
        return SDL_INIT_FAILED;
    }

    m_pWindow = SDL_CreateWindow(title, x, y, w, h, flags);

    SDL_Delay(5000);
}

init_response_t Game::Init(const char * title)
{
    return Init(title, 
                SDL_WINDOWPOS_UNDEFINED,
                SDL_WINDOWPOS_UNDEFINED,
                640, 480,
                SDL_WINDOW_RESIZABLE);
}

void Game::Clean()
{
    cout << "Cleaning resources" << endl;
    SDL_DestroyWindow(m_pWindow);
    SDL_Quit();
}
