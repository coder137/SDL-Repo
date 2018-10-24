#include <iostream>

#include "IncludeNamespace.h"
#include "Game.h"

// using namespace std;

int main(int argc, char * argv[])
{
    Game* game = new Game();
    
    game->init("Random", 
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            640, 480,
            SDL_WINDOW_RESIZABLE);

    game->clean();
    delete game;
    while(1);

    return 0;
}
