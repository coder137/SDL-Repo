#ifndef _Game_H
#define _Game_H

#include <SDL.h>
#include "IncludeNamespace.h"

typedef enum {
    SDL_INIT_FAILED,
    SDL_WINDOW_CREATION_FAILED,
    SDL_RENDERER_FAILED,

    SDL_INIT_SUCCESS
} init_response_t;

class Game 
{
public:
    Game();
    ~Game();

    init_response_t init(const char * title, int x, int y, int w, int h, uint32_t flags);
    void clean();
private:
    SDL_Window * m_pWindow;
};

#endif