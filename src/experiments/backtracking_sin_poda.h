#ifndef KNAPSACK_PROBLEM_BACKTRACKING_SIN_PODA_H
#define KNAPSACK_PROBLEM_BACKTRACKING_SIN_PODA_H

#include <vector>
#include "../utilities/backpack.h"

Backpack backtrackingSinPodaRecursion(int i, Backpack bkp, vector<Item> const &items);
unsigned long backtrackingSinPoda(unsigned long bkpSize, vector<Item> &items);

#endif //KNAPSACK_PROBLEM_BACKTRACKING_SIN_PODA_H
