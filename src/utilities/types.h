#ifndef KNAPSACK_PROBLEM_TYPES_H
#define KNAPSACK_PROBLEM_TYPES_H

#include <vector>

using namespace std;

struct item {
    int size;
    int value;
};

struct backpack {
    int size;
    int load;
    int value;
    vector<item> items;
};

#endif //KNAPSACK_PROBLEM_TYPES_H
