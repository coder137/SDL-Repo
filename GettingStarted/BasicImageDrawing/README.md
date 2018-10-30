# Basic image Drawing

First Project where a normal `Game` class is created in C++
Implementing generic methods

- Init
- Clean
- Render
- Update
- HandleEvent

Art created using [PiskelApp](https://www.piskelapp.com/)

# IMP

## [1] Inside SDL Includes file

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

## [2] Installing additional libraries like `SDL_image` using CMAKE

Example taken `SDL_image`

- Download the **Development Libraries** -> **SDL2_image-devel-mingw** (name can change)
- Copy the **32 bit version** and add it to the folder of your choice
    - `C:/sdl/sdl_image`
- Set the include directory path
    - `C:/sdl/sdl_image/include/SDL2`
- Set the library path
    - `C:/sdl/sdl_image/lib`
- Modify **SDL_LIBRARIES**
    - `"-L${SDL2_LIB_DIR} -L${SDL2_IMAGE_LIB_DIR} -lmingw32 -lSDL2main -lSDL2 -lSDL2_image"`
- add **Include directory**
    - `include_directories(${SDL2_IMAGE_INCLUDE_DIR})`
- Update **.vscode/c_cpp_properties**
- Make sure you copy all the DLLs present inside `C:/sdl/sdl_image/bin` near your .exe file OR add it to path

## [3] Difference between `m_sourceRectangle` and `m_destinationRectangle`

**Basic Information**
- `m_sourceRectangle` is the data of the image itself
- `m_destinationRectangle` is the destination of the image data rendered onto the screen

**m_sourceRectangle**
- `m_sourceRectangle.w` and `m_sourceRectangle.h` set the width and height of the image explicitly
- `m_sourceRectangle.x` and `m_sourceRectangle.y` sets the point from which the data is looked at (default 0,0) (top left)

**m_destinationRectangle**
- `m_destinationRectangle.w` and `m_destinationRectangle.h` can be set the `m_sourceRectangle` since they are usually the same
- `m_destinationRectangle.x` and `m_destinationRectangle.y` can be set to a point that is rendered onto the screen (default 0,0) (top left)

# [API] BasicImageDrawing

- [x] Loading a BMP Image
- [x] Animating a Image Frame
- [ ] Flipping Images
- [x] Installing [`SDL_Image`](https://www.libsdl.org/projects/SDL_image/) library
- [x] Using `SDL_Image` library
- [ ] Writing a TextureManager Class

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
- `SDL_GetTicks`

## [SDL_image] Functions

- `IMG_Load`
