#include <iostream>
#include <vector>
#include <algorithm>

#include "utilities/types.h"

using namespace std;

int dynamicProgramming(int bkpSize, vector<item> const &items) {
    vector<vector<int>> cache(bkpSize + 1, vector<int>(items.size() + 1));

    for (int size = 1; size < bkpSize + 1; size++) {
        for (int i = 1; i < items.size() + 1; i++) {
            if (items[i-1].size > size) {
                cache[size][i] = cache[size][i - 1];
            } else {
                cache[size][i] = max(cache[size][i - 1], items[i-1].value + cache[size - items[i-1].size][i - 1]);
            }
        }
    }
    return cache[bkpSize][items.size()];
}

