cmake_minimum_required(VERSION 3.9)
project(knapsack_problem)

set(CMAKE_CXX_STANDARD 11)

add_executable(knapsack_problem
        README.md src/bruteforce.cpp src/backtracking.cpp src/dynamic_programming.cpp src/types.h src/main.cpp src/backtracking.h src/bruteforce.h src/meet_in_the_middle.cpp src/meet_in_the_middle.h src/utilities.cpp src/utilities.h)
