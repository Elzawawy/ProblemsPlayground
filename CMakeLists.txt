cmake_minimum_required(VERSION 3.12)
project(ProblemsPlayground)

set(CMAKE_CXX_STANDARD 17)
file(GLOB PROBLEMS_SOURCE src/*.cpp src/*/*.cpp src/*/*/*.cpp)
add_executable(ProblemsPlayground main.cpp useful_IO.h ${PROBLEMS_SOURCE})