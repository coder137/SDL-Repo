#include "Game.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

int main(int argc, char * argv[]) {

	Game * game = new Game();

	bool start = game->init("GameClass", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
				SCREEN_WIDTH, SCREEN_HEIGHT, false);

	if (!start) { return -1; }

	while (game->running()) {
		game->handleEvent();
		game->update();
		game->render();
	}

	game->close();

	return 0;
}
