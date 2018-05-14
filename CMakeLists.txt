cmake_minimum_required(VERSION 3.9)
project(knapsack_problem)

set(CMAKE_CXX_STANDARD 11)

add_executable(knapsack_problem
        README.md src/bruteforce.cpp src/backtracking.cpp src/dynamic_programming.cpp src/utilities/types.h src/main.cpp src/backtracking.h src/bruteforce.h src/meet_in_the_middle.cpp src/meet_in_the_middle.h src/utilities/utilities.cpp src/utilities/utilities.h src/experiments/compare_backtracking.cpp src/experiments/config.h src/experiments/backtracking_sin_poda.cpp src/experiments/backtracking_sin_poda.h src/experiments/compare_backtracking.h src/experiments/backtracking_poda_factibilidad.cpp src/experiments/backtracking_poda_factibilidad.h src/experiments/backtracking_poda_optimalidad.cpp src/experiments/backtracking_poda_optimalidad.h src/dynamic_programming.h src/experiments/compare_algorithms.cpp src/experiments/compare_algorithms.h src/utilities/backpack.h src/utilities/item.cpp src/utilities/item.h src/utilities/backpack.cpp)
