cmake_minimum_required(VERSION 3.7)
set(CMAKE_CXX_STANDARD 17)

project(Asteroids)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS})

find_package(SDL2_ttf REQUIRED)
include_directories(${SDL2_TTF_INCLUDE_DIRS})

include_directories("include")

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

file(GLOB SOURCES "src/*.cpp")

add_executable(Asteroids ${SOURCES})
target_link_libraries(Asteroids ${SDL2_LIBRARIES} ${SDL2_TTF_LIBRARIES})
