cmake_minimum_required(VERSION 3.14)
project(ToyEngine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Lägg till Raylib från den lokala external-mappen
add_subdirectory(external/raylib)

add_executable(${PROJECT_NAME} game/main.cpp)
target_include_directories(${PROJECT_NAME} PRIVATE engine game)
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)

if(UNIX AND NOT APPLE)
    target_link_libraries(${PROJECT_NAME} PRIVATE m pthread dl GL X11)
endif()