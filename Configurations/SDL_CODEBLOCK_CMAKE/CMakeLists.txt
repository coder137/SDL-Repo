cmake_minimum_required(VERSION 3.5)

# set(CMAKE_GENERATOR "CodeBlocks - MinGW Makefiles" CACHE INTERNAL "" FORCE)

# TODO, Change this as per your project name
project(Test)

# message(STATUS ${CMAKE_CURRENT_LIST_DIR})

# * Set the variables that we are using
# TODO, Only change this as per your need (the rest configures itself)
set(SDL2_PATH "C:/sdl")

set(SDL2_INCLUDE_DIR "${SDL2_PATH}/include/SDL2")
set(SDL2_LIB_DIR "${SDL2_PATH}/lib")
set(SDL2_LIBRARIES "-L${SDL2_LIB_DIR} -lmingw32 -lSDL2main -lSDL2")
string(STRIP "${SDL2_LIBRARIES}" SDL2_LIBRARIES)

# ! debug statements
message(STATUS "SDL2_PATH: " ${SDL2_PATH})
message(STATUS "SDL2_INCLUDE_DIR: " ${SDL2_INCLUDE_DIR})
message(STATUS "SDL2_LIB_DIR: " ${SDL2_LIB_DIR})
message(STATUS "SDL2_LIBRARIES: " ${SDL2_LIBRARIES})

# ! We need to set SDL2_DIR to find_package (contains sdl2-config.cmake)
# set(SDL2_DIR "C:/sdl/lib/cmake/SDL2")
# find_package(SDL2 REQUIRED)

include_directories(${SDL2_INCLUDE_DIR})

# TODO, Change Test to your project name
add_executable(Test main.cpp)
target_link_libraries(Test ${SDL2_LIBRARIES})
