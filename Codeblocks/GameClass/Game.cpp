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

    SDL_RenderPresent(renderer);
}

void Game::close() {
    std::cout << "Game->close" << std::endl;
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}
