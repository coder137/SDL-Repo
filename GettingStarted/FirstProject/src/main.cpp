#include <iostream>

#define SAL_ENABLE 0

#include "IncludeNamespace.h"
#include "Game.h"

// using namespace std;

int main(int argc, char * argv[])
{
    Game* game = new Game();
    
    game->Init("Random");
    game->Clean();

    // Delete the game    
    delete game;
    while(1);

    return 0;
}
