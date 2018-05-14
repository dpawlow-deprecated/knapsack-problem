#ifndef KNAPSACK_PROBLEM_BACKTRACKING_PODA_FACTIBILIDAD_H
#define KNAPSACK_PROBLEM_BACKTRACKING_PODA_FACTIBILIDAD_H

#include <vector>

Backpack backtrackingFactibilidadRecursion(int i, Backpack bkp, vector<Item> const &items);
unsigned long backtrackingPodaFactibilidad(unsigned long bkpSize, vector<Item> &items);

#endif //KNAPSACK_PROBLEM_BACKTRACKING_PODA_FACTIBILIDAD_H
