#ifndef KNAPSACK_PROBLEM_UTILITIES_H
#define KNAPSACK_PROBLEM_UTILITIES_H

int isOdd(int x);
void getCombination(int combination, backpack &bkp, vector<item> const &items);

bool isLighter(const item& a, const item& b);
bool isMoreValuable(const item& a, const item& b);

bool isMoreValuableBackpack(const backpack& a, const backpack& b);


#endif //KNAPSACK_PROBLEM_UTILITIES_H
