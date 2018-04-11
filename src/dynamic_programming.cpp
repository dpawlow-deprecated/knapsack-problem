#include <iostream>
#include <vector>
#include <algorithm>

#include "utilities/types.h"

using namespace std;

int dynamicProgramming(int bkpSize, vector<item> const &items) {
    int cache[bkpSize + 1][items.size() + 1];
    for (int i = 0; i < bkpSize + 1; i++) {
        for (int j = 0; j < items.size() + 1; j++) {
            cache[i][j] = 0;
        }
    }

    for (int size = 1; size < bkpSize + 1; size++) {
        for (int item = 1; item < items.size() + 1; item++) {
            if (items[item].size > size) {
                cache[size][item] = cache[size][item - 1];
            } else {
                cache[size][item] = max(cache[size][item - 1], items[item].value + cache[size - items[item].size][item - 1]);
            }
        }
    }
    return cache[bkpSize][items.size()];
}

int recursiveDynamicProgramming(int bkpSize, vector<item> const &items) {

}
