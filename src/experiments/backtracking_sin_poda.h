#ifndef KNAPSACK_PROBLEM_BACKTRACKING_SIN_PODA_H
#define KNAPSACK_PROBLEM_BACKTRACKING_SIN_PODA_H

#include <vector>
#include "../utilities/types.h"

backpack backtrackingSinPodaRecursion(int i, backpack bkp, vector<item> const &items);
int backtrackingSinPoda(int bkpSize, vector<item> &items);

#endif //KNAPSACK_PROBLEM_BACKTRACKING_SIN_PODA_H
