#ifndef KNAPSACK_PROBLEM_BACKTRACKING_H
#define KNAPSACK_PROBLEM_BACKTRACKING_H

#include <vector>
#include "types.h"

bool isLighter(const item&, const item&);
bool hasRoomForMore(int i, backpack const &bkp, vector<item> const &items);
bool maxValueIsReachable(int i, backpack const &bkp, vector<item> const &items, int &maxValue);
backpack backtracking(int i, backpack bkp, vector<item> const &items, int maxValue);
backpack solveC(int bkpSize, vector<item> &items);
void test();


#endif //KNAPSACK_PROBLEM_BACKTRACKING_H
