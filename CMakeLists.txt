cmake_minimum_required(VERSION 3.14)
project(MyRaylibProject)

# Aktivera C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# FetchContent är tillgängligt från CMake 3.11+
include(FetchContent)

# Hämta raylib
FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG        5.0  # Du kan byta till en annan tag eller branch om du vill
)

# Gör innehållet tillgängligt
FetchContent_MakeAvailable(raylib)

# Din exekverbara fil
add_executable(ToyEngine main.cpp)

# Länka mot raylib och dess beroenden
target_link_libraries(ToyEngine PRIVATE raylib)

# På vissa system (som Linux) kan du behöva länka extra bibliotek
if(UNIX AND NOT APPLE)
    target_link_libraries(ToyEngine PRIVATE m pthread dl GL X11)
endif()
