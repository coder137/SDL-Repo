# First SDL Project


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