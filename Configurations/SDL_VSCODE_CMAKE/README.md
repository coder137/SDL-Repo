# SDL with VSCode and CMake 

Build System installed is **NINJA**

### VSCode Extensions

- Install **CMake Tools** by **vector-of-bool**
- Install **CMake** by **twxs**

### Update `User-Local CMake Kits`

``` json
{
    "name": "Codeblocks MinGW",
    "compilers": {
      "CXX": "C:\\Program Files (x86)\\CodeBlocks\\MinGW\\bin\\g++.exe",
      "C": "C:\\Program Files (x86)\\CodeBlocks\\MinGW\\bin\\gcc.exe"
    }
},
```

- Change the CXX and C to your path
- Restart VSCode

### Update CMakeLists.txt

- Update **Project name**
- Set `SDL2_PATH`
- Inside `add_executable` and `target_link_libraries` change **Test** to **project_name**

### VSCode

- Click on the **CMAKE** icon on the left of VSCode
- Click on Build/Configure to select your kit and configure your entire target
- `Control + Shift + B` -> **Create a Build Target**
- Created generic `tasks.json` file
    - Since **Ninja** is being used ive configured the build to use that
- `F5` -> **Create a Run Target**
- Created a `launch.json` file
    - Point to the `project_name.exe` file inside `build` folder 
- Updated `intellisense` path
    - Added `SDL2` include libraries to configure intellisense autocomplete
