cmake_minimum_required(VERSION 3.10)

project(Matrix)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

set (headers
include/Matrix.hpp
)

set (sources
Matrix.cpp
)

add_executable(${PROJECT_NAME} main.cpp ${headers} ${sources})