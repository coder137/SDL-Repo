#include "Game.h"

Game::Game() {}

Game::~Game() {}

bool Game::init(const char * title, int xpos, int ypos, int width, int height, bool fullscreen) {

    isRunning = false;
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return false;
    }

    int flags = 0;
    if (fullscreen) {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
    if (window == NULL) {
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, 0);
    if (renderer == NULL) {
        return false;
    }

    SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);

    isRunning = true;
    std::cout << "Game->init" << std::endl;

    // * Loading BMP Image here
    SDL_Surface * tempSurface = SDL_LoadBMP("assets/VENUS.BMP");
    texture =  SDL_CreateTextureFromSurface(renderer, tempSurface);
    SDL_FreeSurface(tempSurface);

    SDL_QueryTexture(texture, NULL, NULL, &srcRect.w, &srcRect.h);
    std::cout << srcRect.w << "::" << srcRect.h << std::endl;

    destRect.x = srcRect.x = 0;
    destRect.y = srcRect.y = 0;
    destRect.w = srcRect.w;
    destRect.h = srcRect.h;

    return true;
}

void Game::handleEvent() {

    SDL_Event event;

    if(SDL_PollEvent(&event)) {
        switch(event.type) {
            case SDL_QUIT:
                isRunning = false;
                break;
            default:
                break;
        }
    }
}

void Game::update(){}

void Game::render() {
    SDL_RenderClear(renderer);

    SDL_RenderCopy(renderer, texture, &srcRect, &destRect);

    SDL_RenderPresent(renderer);
}

void Game::close() {
    std::cout << "Game->close" << std::endl;
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}
