cmake_minimum_required(VERSION 3.14)
project(ToyEngine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Lägg till Raylib från den lokala external-mappen
add_subdirectory(external/raylib)

add_executable(my_game main.cpp)
target_link_libraries(my_game PRIVATE raylib)

if(UNIX AND NOT APPLE)
    target_link_libraries(my_game PRIVATE m pthread dl GL X11)
endif()