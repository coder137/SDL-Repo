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

