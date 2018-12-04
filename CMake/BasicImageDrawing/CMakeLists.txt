cmake_minimum_required(VERSION 3.5)

# set(CMAKE_GENERATOR "CodeBlocks - MinGW Makefiles" CACHE INTERNAL "" FORCE)

project(Test)

# message(STATUS ${CMAKE_CURRENT_LIST_DIR})

# * Set the variables that we are using
# TODO, Only change this as per your need (the rest configures itself)
set(SDL2_PATH "C:/sdl")

# Setting up SDL_Image
set(SDL2_IMAGE_INCLUDE_DIR "${SDL2_PATH}/sdl_image/include/SDL2")
set(SDL2_IMAGE_LIB_DIR "${SDL2_PATH}/sdl_image/lib")

# Setting up SDL2
set(SDL2_INCLUDE_DIR "${SDL2_PATH}/include/SDL2")
set(SDL2_LIB_DIR "${SDL2_PATH}/lib")

# Link all these to SDL2_Libraries -> consumed by target link library
set(SDL2_LIBRARIES "-L${SDL2_LIB_DIR} -L${SDL2_IMAGE_LIB_DIR} -lmingw32 -lSDL2main -lSDL2 -lSDL2_image")
string(STRIP "${SDL2_LIBRARIES}" SDL2_LIBRARIES)

# ! debug statements
message(STATUS "SDL2_PATH: " ${SDL2_PATH})
message(STATUS "SDL2_INCLUDE_DIR: " ${SDL2_INCLUDE_DIR})
message(STATUS "SDL2_LIB_DIR: " ${SDL2_LIB_DIR})
message(STATUS "SDL2_LIBRARIES: " ${SDL2_LIBRARIES})

# ! We need to set SDL2_DIR to find_package (contains sdl2-config.cmake)
# set(SDL2_DIR "C:/sdl/lib/cmake/SDL2")
# find_package(SDL2 REQUIRED)
include_directories(include)
include_directories(${SDL2_INCLUDE_DIR})
include_directories(${SDL2_IMAGE_INCLUDE_DIR})

file(GLOB SOURCES "src/*.cpp")
message(STATUS "Sources: " ${SOURCES})

add_executable(Test ${SOURCES})
target_link_libraries(Test ${SDL2_LIBRARIES})
