# Basic image Drawing

First Project where a normal `Game` class is created in C++
Implementing generic methods

- Init
- Clean
- Render
- Update [TODO]
- HandleEvent

## [IMP] Inside SDL Includes file

**SDL_stdinc.h: Line 260**
``` cpp
#if SAL_ENABLE // TODO, Line extra
#include <sal.h> 
#endif // TODO, Line extra
```

**Inside main.cpp**
``` cpp
#define SAL_ENABLE 0
```

This makes sure that sal.h does not keep throwing an error in VSCode

# [API] FirstProject

## [LEARNT] Structures and Definitions

- SDL_Texture
- [`SDL_Rect`](http://wiki.libsdl.org/SDL_Rect?highlight=%28%5CbCategoryStruct%5Cb%29%7C%28SDLStructTemplate%29)
- SDL_Surface

## Functions

- [`SDL_LoadBMP`](http://wiki.libsdl.org/SDL_LoadBMP?highlight=%28%5CbCategoryAPI%5Cb%29%7C%28SDLFunctionTemplate%29)
- [`SDL_CreateTextureFromSurface`](http://wiki.libsdl.org/SDL_CreateTextureFromSurface?highlight=%28%5CbCategoryAPI%5Cb%29%7C%28SDLFunctionTemplate%29)
- [`SDL_FreeSurface`](http://wiki.libsdl.org/SDL_FreeSurface?highlight=%28%5CbCategoryAPI%5Cb%29%7C%28SDLFunctionTemplate%29)
- [`SDL_QueryTexture`](http://wiki.libsdl.org/SDL_QueryTexture?highlight=%28%5CbCategoryAPI%5Cb%29%7C%28SDLFunctionTemplate%29)
- [`SDL_RenderCopy`](http://wiki.libsdl.org/SDL_RenderCopy?highlight=%28%5CbCategoryAPI%5Cb%29%7C%28SDLFunctionTemplate%29)
