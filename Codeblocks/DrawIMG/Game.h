#ifndef _Game_H
#define _Game_H

#include <SDL.h>
#include <SDL_image.h>

#include <stdio.h>
#include <iostream>

class Game {

public:
    Game();
    ~Game();

    bool init(const char * title, int xpos, int ypos, int width, int height, bool fullscreen);
    void handleEvent();
    void update();
    void render();
    void close();

    bool running() { return isRunning; }

    void SDL_PrintError() {
	    fprintf(stderr, "Error: %s", SDL_GetError());
    }

private:
    bool isRunning;

    SDL_Window * window = NULL;
    SDL_Renderer * renderer = NULL;

    SDL_Texture * texture = NULL;
    SDL_Rect srcRect, destRect;
};

#endif
