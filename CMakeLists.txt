cmake_minimum_required(VERSION 3.27)
project(OakEngine)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)

find_package(SDL2 REQUIRED)

include_directories(include)

add_library(OakEngine SHARED src/Engine.cpp
        src/Math/Vec2.cpp
        src/Physics/Colliders/BaseCollider.cpp
)

target_link_libraries(OakEngine PRIVATE SDL2::SDL2)
