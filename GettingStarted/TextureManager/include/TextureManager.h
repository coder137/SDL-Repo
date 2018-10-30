#ifndef _TextureManager_H
#define _TextureManager_H

#include <SDL.h>
#include <map>

#include <SDL_image.h>

#include "IncludeNamespace.h"


class TextureManager
{
public:
    bool load(string filename, string id, SDL_Renderer * pRenderer);
    
    void draw(string id, int x, int y, int w, int h, SDL_Renderer * pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

    void drawFrame(string id, int x, int y, int w, int h, int currentRow, int currentFrame, SDL_Renderer * pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
private:
    std::map<string, SDL_Texture*> m_textureMap;
};

#endif
