cmake_minimum_required(VERSION 3.25)
project(04_TetrisGame)

set(CMAKE_CXX_STANDARD 20)

# Include Raylib headers
include_directories("/opt/homebrew/Cellar/raylib/5.0/include")

# Link Raylib libraries
link_directories("/opt/homebrew/Cellar/raylib/5.0/lib")

# Add the executable
add_executable(04_TetrisGame main.cpp grid.cpp position.h block.h colors.cpp block.cpp position.cpp game.cpp)

# Link the Raylib library
target_link_libraries(04_TetrisGame raylib)
