#ifndef KNAPSACK_PROBLEM_BACKTRACKING_H
#define KNAPSACK_PROBLEM_BACKTRACKING_H

#include <vector>
#include "utilities/types.h"

bool isMoreValuable(const item& a, const item& b);
bool isLighter(const item&, const item&);
bool hasRoomForMore(int i, backpack const &bkp, vector<item> const &items);
bool maxValueIsReachable(int i, backpack const &bkp, vector<item> const &items, int &maxValue);
backpack backtrackingRecursion(int i, backpack bkp, vector<item> const &items, int maxValue);
backpack backtracking(int bkpSize, vector<item> &items);
void test();


#endif //KNAPSACK_PROBLEM_BACKTRACKING_H
