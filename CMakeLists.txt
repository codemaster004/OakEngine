cmake_minimum_required(VERSION 3.27)
project(OakEngine)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Cmake standard library output folder
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)

# Library paths
set(LIB_DS_PATH /Users/filip/Developer/Cpp/DataStructs)
set(LIB_SDL2_PATH /Users/filip/Developer/Cpp/SDL)

# My SDL build
include_directories(${LIB_SDL2_PATH}/include)
link_directories(${LIB_SDL2_PATH}/build)

# Data Structures Library
include_directories(${LIB_DS_PATH}/include)
link_directories(${LIB_DS_PATH}/lib)

# 3-party libraries
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/vendor/spdlog/include)

# My includes
include_directories(include)

add_library(OakEngine SHARED include/Oak.h
        src/Engine.cpp
        src/Math/Vec2.cpp
        src/Physics/Colliders/BaseCollider.cpp
        src/Physics/Colliders/CircleCollider.cpp
        src/Physics/PhysicsSpace.cpp
        src/Physics/CollisionTests.cpp
        src/Physics/Solvers/PositionSolver.cpp
        src/Logs/Logs.cpp
        src/Physics/PhysicsObject.cpp
        src/Physics/Dynamic/DynamicObject.cpp
        src/Physics/Dynamic/DynamicSpace.cpp
        src/Window/MacWindow.cpp
)

target_link_libraries(OakEngine PRIVATE DataStructs SDL2)
