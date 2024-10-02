cmake_minimum_required(VERSION 3.25)
project(HelloRaylib)

set(CMAKE_CXX_STANDARD 17)

# Include Raylib headers
include_directories("/opt/homebrew/Cellar/raylib/5.0/include")

# Link Raylib libraries
link_directories("/opt/homebrew/Cellar/raylib/5.0/lib")

# Add the executable
add_executable(HelloRaylib main.cpp)

# Link the Raylib library
target_link_libraries(HelloRaylib raylib)
