cmake_minimum_required(VERSION 3.12)
project(ProblemsPlayground)

set(CMAKE_CXX_STANDARD 17)

add_executable(ProblemsPlayground src useful_IO.h src/30days-challenge src/30days-challenge/3_maximum_subarray.cpp src/codejam-2020/vestigium.cpp src/codejam-2020/nesting_depth.cpp src/codejam-2020/parenting_partnering_returns.cpp)