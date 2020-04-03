cmake_minimum_required(VERSION 3.12)
project(ProblemsPlayground)

set(CMAKE_CXX_STANDARD 17)

add_executable(ProblemsPlayground src main.cpp useful_IO.h src/30days-challenge src/30days-challenge/3_maximum_subarray.cpp)