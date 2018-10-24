#include "Game.h"

Game::Game()
{
    cout << "Game class `Created`" << endl;
}

Game::~Game()
{
    cout << "Game class `Destroyed`" << endl;
}

init_response_t Game::init(const char * title, int x, int y, int w, int h, uint32_t flags)
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

void Game::clean()
{
    cout << "Cleaning resources" << endl;
    SDL_DestroyWindow(m_pWindow);
    SDL_Quit();
}
