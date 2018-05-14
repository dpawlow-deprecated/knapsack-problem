#include <iostream>
#include <vector>
#include "utilities/item.h"

using namespace std;

unsigned long dynamicProgramming(unsigned long bkpSize, vector<Item> const &items) {
    vector<vector<unsigned long>> cache(bkpSize + 1, vector<unsigned long>(items.size() + 1));

    for (int size = 1; size < bkpSize + 1; size++) {
        for (int i = 1; i < items.size() + 1; i++) {
            if (items[i-1].getSize() > size) {
                cache[size][i] = cache[size][i - 1];
            } else {
                cache[size][i] = max(cache[size][i - 1], items[i-1].getValue() + cache[size - items[i-1].getSize()][i - 1]);
            }
        }
    }
    return cache[bkpSize][items.size()];
}

