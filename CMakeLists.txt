cmake_minimum_required(VERSION 3.12)
project(ProblemsPlayground)

set(CMAKE_CXX_STANDARD 17)

add_executable(ProblemsPlayground src useful_IO.h  src/30days-challenge/3_maximum_subarray.cpp src/codejam-2020/vestigium.cpp src/codejam-2020/nesting_depth.cpp src/codejam-2020/parenting_partnering_returns.cpp  src/30days-challenge/4_move_zeroes.cpp src/30days-challenge/5_best_time_buy_sell_stock2.cpp src/codejam-2020/expogo.cpp src/30days-challenge/24_lru_cache.cpp src/30days-challenge/6_group_anagrams.cpp src/30days-challenge/7_counting_elements.cpp src/30days-challenge/8_middle_linked_list.cpp src/30days-challenge/9_backspace_string_compare.cpp src/30days-challenge/10_min_stack.cpp)