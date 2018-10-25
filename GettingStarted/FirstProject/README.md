# First SDL Project

First Project where a normal `Game` class is created in C++
Implementing generic methods

- Init
- Clean
- Render
- Update [TODO]
- HandleEvent

## [IMP] Inside SDL Includes file

**SDL_stdinc.h: Line 260**
```
#if SAL_ENABLE // TODO, Line extra
#include <sal.h> 
#endif // TODO, Line extra
```

**Inside main.cpp**
```
#define SAL_ENABLE 0
```

This makes sure that sal.h does not keep throwing an error in VSCode

# [API] FirstProject

## Structures and Definitions

- `SDL_Window`
- `SDL_Renderer`
- [`SDL_Event`](http://wiki.libsdl.org/SDL_Event?highlight=%28%5CbCategoryStruct%5Cb%29%7C%28SDLStructTemplate%29)

## Functions

- [`SDL_Init`](http://wiki.libsdl.org/SDL_Init?highlight=%28%5CbCategoryAPI%5Cb%29%7C%28SDLFunctionTemplate%29)
- [`SDL_CreateWindow`](http://wiki.libsdl.org/SDL_CreateWindow?highlight=%28%5CbCategoryAPI%5Cb%29%7C%28SDLFunctionTemplate%29)
- [`SDL_CreateRenderer`](http://wiki.libsdl.org/SDL_CreateRenderer?highlight=%28%5CbCategoryAPI%5Cb%29%7C%28SDLFunctionTemplate%29)
- [`SDL_SetRenderDrawColor`](http://wiki.libsdl.org/SDL_SetRenderDrawColor?highlight=%28%5CbCategoryAPI%5Cb%29%7C%28SDLFunctionTemplate%29)
- [`SDL_RenderClear`](http://wiki.libsdl.org/SDL_RenderClear?highlight=%28%5CbCategoryAPI%5Cb%29%7C%28SDLFunctionTemplate%29)
- [`SDL_RenderPresent`](http://wiki.libsdl.org/SDL_RenderPresent?highlight=%28%5CbCategoryAPI%5Cb%29%7C%28SDLFunctionTemplate%29)
- [`SDL_DestroyRenderer`](http://wiki.libsdl.org/SDL_DestroyRenderer?highlight=%28%5CbCategoryAPI%5Cb%29%7C%28SDLFunctionTemplate%29)
- [`SDL_DestroyWindow`](http://wiki.libsdl.org/SDL_DestroyWindow?highlight=%28%5CbCategoryAPI%5Cb%29%7C%28SDLFunctionTemplate%29)
- [`SDL_Quit`](http://wiki.libsdl.org/SDL_Quit?highlight=%28%5CbCategoryAPI%5Cb%29%7C%28SDLFunctionTemplate%29)
- [`SDL_PollEvent`](http://wiki.libsdl.org/SDL_PollEvent?highlight=%28%5CbCategoryAPI%5Cb%29%7C%28SDLFunctionTemplate%29)
