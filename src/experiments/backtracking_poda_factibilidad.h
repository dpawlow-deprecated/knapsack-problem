#ifndef KNAPSACK_PROBLEM_BACKTRACKING_PODA_FACTIBILIDAD_H
#define KNAPSACK_PROBLEM_BACKTRACKING_PODA_FACTIBILIDAD_H

#include <vector>
#include "../types.h"

backpack backtrackingFactibilidadRecursion(int i, backpack bkp, vector<item> const &items);
backpack backtrackingPodaFactibilidad(int bkpSize, vector<item> &items);

#endif //KNAPSACK_PROBLEM_BACKTRACKING_PODA_FACTIBILIDAD_H
