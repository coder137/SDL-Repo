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

    SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);

    // SDL_RenderClear(m_pRenderer);
    // SDL_RenderPresent(m_pRenderer);

    // * Load the SDL_Surface and convert it to Texture
    // SDL_Surface * pTempSurface = SDL_LoadBMP("assets/VENUS.BMP");
    SDL_Surface * pTempSurface = IMG_Load("assets/vamp-256_256.png");
    m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
    SDL_FreeSurface(pTempSurface);

    if (m_pTexture == NULL)
    {
        // TODO, Do something
    }

    // * Query the texture
    SDL_QueryTexture(m_pTexture, NULL, NULL, &m_sourceRectangle.w, &m_sourceRectangle.h);

    // ! Setting this explicitly
    // m_sourceRectangle.w = 256; //32, 64, 96
    // // m_sourceRectangle.h = 81-44;

    // // * Set the destination and source
    // m_destinationRectangle.x = m_sourceRectangle.x = 0;
    // m_destinationRectangle.y = m_sourceRectangle.y = 0;
    // m_destinationRectangle.w = m_sourceRectangle.w;
    // m_destinationRectangle.h = m_sourceRectangle.h;

    // // ! Rendered at position (x, y)
    // m_destinationRectangle.x = 100;
    // m_destinationRectangle.y = 100;

    // m_textureManager.load("assets/vamp-256_256.png", "animate", m_pRenderer);
    bool isLoaded = TextureManager::Instance()->load("assets/vamp-256_256.png", "animate", m_pRenderer);

    if(!isLoaded)
    {
        return SDL_TEXTURE_MANAGER_FAILED;
    }

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

    // * Render the image here
    // SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle);
    // SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRectangle, NULL);

    // m_textureManager.draw("animate", 0, 0, 256, 256, m_pRenderer);

    // m_textureManager.drawFrame("animate", 200, 200, 256, 256, 1, m_currentFrame, m_pRenderer);

    TextureManager::Instance()->draw("animate", 0, 0, 256, 256, m_pRenderer);

    TextureManager::Instance()->drawFrame("animate", 200, 200, 256, 256, 1, m_currentFrame, m_pRenderer);

    SDL_RenderPresent(m_pRenderer);
}

void Game::Update()
{
    int no = ( SDL_GetTicks()/500 ) % 4; 
    m_currentFrame = no;
    cout << m_currentFrame << endl;
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
