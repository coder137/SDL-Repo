#ifndef _TextureManager_H
#define _TextureManager_H

#include <SDL.h>
#include <map>

#include <SDL_image.h>

#include "IncludeNamespace.h"


class TextureManager
{
private:
    TextureManager() { }
public:
    static TextureManager* Instance()
    {
        if (s_pInstance == NULL)
        {
            s_pInstance = new TextureManager();
            return s_pInstance;
        }

        return s_pInstance;
    }

    bool load(string filename, string id, SDL_Renderer * pRenderer);
    
    void draw(string id, int x, int y, int w, int h, SDL_Renderer * pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

    void drawFrame(string id, int x, int y, int w, int h, int currentRow, int currentFrame, SDL_Renderer * pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
private:
    std::map<string, SDL_Texture*> m_textureMap;

    static TextureManager *s_pInstance;

};

#endif
