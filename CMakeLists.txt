cmake_minimum_required(VERSION 3.7)
set(CMAKE_CXX_STANDARD 17)

project(Asteroids)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})
include_directories("include")


file(GLOB SOURCES "src/*.cpp")

add_executable(Asteroids ${SOURCES})
target_link_libraries(Asteroids ${SDL2_LIBRARIES})
