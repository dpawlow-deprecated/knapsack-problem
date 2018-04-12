#ifndef KNAPSACK_PROBLEM_BRUTEFORCE_H
#define KNAPSACK_PROBLEM_BRUTEFORCE_H

#include <vector>
#include "utilities/types.h"

void solvePortion(int bkpSize, vector<item> const &items, vector<backpack> backpacks);
int bruteforce(int bkpSize, vector<item> const &items);

#endif //KNAPSACK_PROBLEM_BRUTEFORCE_H
