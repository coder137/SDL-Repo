#define SAL_ENABLE 0

#include "IncludeNamespace.h"
#include "Game.h"

// using namespace std;

int main(int argc, char * argv[])
{
    Game* game = new Game();

    cout << game->IsRunning() << endl;

    if ( game->Init("This is the Title") != SDL_INIT_SUCCESS )
    {
        return -1;
    }

    while(game->IsRunning())
    {
        game->HandleEvents();
        game->Update();
        game->Render();
    }

    game->Clean();

    // Delete the game    
    delete game;

    return 0;
}
