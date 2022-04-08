# CMakeList.txt : CMake project for PartC, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("PartC")

# Add source to this project's executable.
add_executable (PartC "PartC.cpp" "PartC.h" "animation.h" "AnimationManager.h" "Frame.h" "Frame.cpp" "AnimationManager.cpp" "Animation.cpp")

# TODO: Add tests and install targets if needed.
