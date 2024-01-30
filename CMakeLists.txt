cmake_minimum_required(VERSION 3.27)
project(OakEngine)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Cmake standard library outpud folder
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

# My includes
include_directories(include)

add_library(OakEngine SHARED src/Engine.cpp
        src/Math/Vec2.cpp
        src/Physics/Colliders/BaseCollider.cpp
        src/Physics/Colliders/CircleCollider.cpp
        src/Physics/PhysicsSpace.cpp
)

target_link_libraries(OakEngine PRIVATE DataStructs SDL2)
