#include "Game.h"

Game::Game() : m_bRunning(false)
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
        ErrorLog();
        return SDL_INIT_FAILED;
    }

    m_pWindow = SDL_CreateWindow(title, x, y, w, h, flags);

    if (m_pWindow == NULL)
    {
        ErrorLog();
        return SDL_WINDOW_CREATION_FAILED;
    }
    
    m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

    if (m_pRenderer == NULL)
    {
        ErrorLog();
        return SDL_RENDERER_FAILED;
    }

    SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255);

    SDL_RenderClear(m_pRenderer);

    SDL_RenderPresent(m_pRenderer);

    m_bRunning = true;

    return SDL_INIT_SUCCESS;
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
    SDL_DestroyRenderer(m_pRenderer);
    SDL_DestroyWindow(m_pWindow);
    SDL_Quit();
}

void Game::Render()
{
    SDL_RenderClear(m_pRenderer);

    SDL_RenderPresent(m_pRenderer);
}

void Game::HandleEvents()
{
    SDL_Event event;

    if(SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_QUIT:
            {
                m_bRunning = false;
                break;
            }
            default:
            {
                break;
            }
        }
    }
}
