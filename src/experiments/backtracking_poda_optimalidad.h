#ifndef KNAPSACK_PROBLEM_BACKTRACKING_PODA_OPTIMALIDAD_H
#define KNAPSACK_PROBLEM_BACKTRACKING_PODA_OPTIMALIDAD_H

#include <vector>
#include "../utilities/types.h"

backpack backtrackingOptimalidadRecursion(int i, backpack bkp, vector<item> const &items);
backpack backtrackingPodaOptimalidad(int bkpSize, vector<item> &items);

#endif //KNAPSACK_PROBLEM_BACKTRACKING_PODA_OPTIMALIDAD_H
