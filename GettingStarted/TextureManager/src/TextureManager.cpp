#include "TextureManager.h"

TextureManager * TextureManager::s_pInstance = 0;

bool TextureManager::load(string filename, string id, SDL_Renderer * pRenderer)
{
    SDL_Surface *pTempSurface = IMG_Load(filename.c_str());

    if (pTempSurface == NULL)
    {
        return false;
    }

    SDL_Texture * pTexture = SDL_CreateTextureFromSurface(pRenderer, pTempSurface);

    SDL_FreeSurface(pTempSurface);

    if(pTexture == NULL)
    {
        return false;
    }

    this->m_textureMap[id] = pTexture;
    return true;
}
    
void TextureManager::draw(string id, int x, int y, int w, int h, SDL_Renderer * pRenderer, SDL_RendererFlip flip)
{
    SDL_Rect srcRect, destRect;

    srcRect.x = srcRect.y = 0;
    srcRect.w = destRect.w = w;
    srcRect.h = destRect.h = h;

    destRect.x = x;
    destRect.y = y;

    SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, &destRect, 0, 0, flip);
}

void TextureManager::drawFrame(string id, int x, int y, int w, int h, int currentRow, int currentFrame, SDL_Renderer * pRenderer, SDL_RendererFlip flip)
{
    SDL_Rect srcRect, destRect;

    srcRect.x = w * currentFrame;
    srcRect.y = h * (currentRow - 1);

    srcRect.w = destRect.w = w;
    srcRect.h = destRect.h = h;

    destRect.x = x;
    destRect.y = y;

    SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, &destRect, 0, 0, flip);
}
