#ifndef _Game_H
#define _Game_H

#include <SDL.h>
#include <SDL_image.h>
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

    init_response_t Init(const char * title);
    init_response_t Init(const char * title, int x, int y, int w, int h, uint32_t flags);
    
    void Clean();

    void Render();
    void Update();
    void HandleEvents();
    
    bool IsRunning() {  return m_bRunning; }
    void ErrorLog() {  cout << "Error: " << SDL_GetError() << endl; }
private:
    bool m_bRunning;
    
    SDL_Window * m_pWindow;
    SDL_Renderer * m_pRenderer;

    SDL_Texture * m_pTexture;
    SDL_Rect m_sourceRectangle;
    SDL_Rect m_destinationRectangle;
};

#endif
