#ifndef KNAPSACK_PROBLEM_BRUTEFORCE_H
#define KNAPSACK_PROBLEM_BRUTEFORCE_H

#include <vector>
#include "types.h"

void solvePortion(int bkpSize, vector<item> const &items, struct backpack *backpacks);
backpack solveA(int bkpSize, vector<item> const &items);

#endif //KNAPSACK_PROBLEM_BRUTEFORCE_H
