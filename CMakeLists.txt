cmake_minimum_required(VERSION 3.9)
project(knapsack_problem)

set(CMAKE_CXX_STANDARD 11)

add_executable(knapsack_problem
        README.md src/Bruteforce.cpp src/Backtracking.cpp src/dynamic-programming.cpp src/types.h src/main.cpp src/Backtracking.h src/Bruteforce.h)
