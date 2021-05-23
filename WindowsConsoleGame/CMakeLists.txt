# CMakeList.txt : CMake project for CMakeGame1, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (WindowsConsoleGame "CGameItem.cpp" "CGameItem.h" "Container.h" "Entity.cpp" "Entity.h" "GroundItem.h" "Map.h" "Player.h" "Tester.cpp")

# TODO: Add tests and install targets if needed.
