#include <iostream>
#include <stdio.h>

#include <SDL.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

void SDL_PrintError();

int main(int argc, char * argv[]) {

	SDL_Window * window = NULL;
    SDL_Renderer * renderer = NULL;

    if( SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		SDL_PrintError();
    	return -1;
    }

    window = SDL_CreateWindow("Hello World", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
							SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    if (window == NULL) {
		SDL_PrintError();
		return -1;
    }

    renderer = SDL_CreateRenderer(window, -1, 0);
	if (renderer == NULL) {
		SDL_PrintError();
		return -1;
	}

	SDL_SetRenderDrawColor(renderer, 155, 100, 0, 255);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
	SDL_Delay(5000);

	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}

void SDL_PrintError() {
	fprintf(stderr, "Error: %s", SDL_GetError());
}
