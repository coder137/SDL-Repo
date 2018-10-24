# SDL with Codeblocks and CMAKE

Built in Windows

## IMPORTANT

### [FIRST] Check CMakeLists.txt

- Open `CmakeLists.txt`
- Change the **project** Name as per your need
- **Set** the `SDL2_PATH` using **forward slashes (/)**
- Inside `add_executable` and `target_link_library` change **Test** to **project_name**

### [MANUAL] Build project into `build` directory

- Create `build` folder and navigate
- run command 
    - `cmake -G "Codeblocks - MinGW Makefiles ..`
        - This is to compile the `CMakeLists.txt`
    - `mingw32-make`
        - This builds the entire project code
- Navigate to `SDL2_PATH/bin` and copy  `SDL2.dll` to this folder

### Run via Codeblocks

- Inside the `build` directory
- Open **project_name.cbp** inside codeblocks
- Select `Build Targets` and select `Test`
- Build and Run in codeblocks
