cmake_minimum_required(VERSION 3.10)

project(Snake VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(raylib/include)

add_executable(Snake src/Source/Main.cpp src/Source/Food.cpp src/Source/Frame.cpp src/Source/Game.cpp src/Source/Snake.cpp src/Source/Text.cpp src/Source/Timer.cpp src/Source/Util.cpp)

target_link_libraries(Snake raylib/lib/raylibdll)