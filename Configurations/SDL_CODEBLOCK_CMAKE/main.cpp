#include <iostream>

#include <SDL.h>

using namespace std;

int main(int argc, char * argv[])
{

    int isInit = SDL_Init(SDL_INIT_EVERYTHING);

    cout << "INIT: " << isInit << endl;

    SDL_Window* m_pWindow = SDL_CreateWindow("Title",
                                            SDL_WINDOWPOS_UNDEFINED,
                                            SDL_WINDOWPOS_UNDEFINED,
                                            640, 480,
                                            SDL_WINDOW_RESIZABLE);

    SDL_Delay(5000);
    SDL_DestroyWindow(m_pWindow);
    SDL_Quit();

    return 0;
}
