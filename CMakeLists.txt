cmake_minimum_required(VERSION 3.12)
project(ProblemsPlayground)

set(CMAKE_CXX_STANDARD 17)
file(GLOB PROBLEMS_SOURCE src/*.cpp)
file(GLOB CODEJAM_2020 src/codejam-2020/*.cpp)
file(GLOB LEETCODE_THIRTY_DAYS src/30-days-challenge/*.cpp)
add_executable(ProblemsPlayground main.cpp useful_IO.h ${PROBLEMS_SOURCE} ${LEETCODE_THIRTY_DAYS} ${CODEJAM_2020})