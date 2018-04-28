#ifndef KNAPSACK_PROBLEM_BACKTRACKING_H
#define KNAPSACK_PROBLEM_BACKTRACKING_H

#include <vector>
#include "utilities/backpack.h"

bool isMoreValuable(const Item& a, const Item& b);
bool hasRoomForMore(int i, const Backpack &bkp, vector<Item> const &items);
bool maxValueIsReachable(int i, const Backpack &bkp, vector<Item> const &items, int &maxValue);
Backpack backtrackingRecursion(int i, Backpack bkp, vector<Item> const &items, unsigned long maxValue);
int backtracking(int bkpSize, vector<Item> &items);
void test();


#endif //KNAPSACK_PROBLEM_BACKTRACKING_H
