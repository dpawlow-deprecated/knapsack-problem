#include <iostream>
#include <vector>
#include <algorithm>
#include "../utilities/types.h"

using namespace std;

backpack backtrackingSinPodaRecursion(int i, backpack bkp, vector<item> const &items) {
    if (i >= items.size()) {
        return bkp;
    }
    backpack backpackWithoutItem = backtrackingSinPodaRecursion(i + 1, bkp, items);

    if (bkp.load + items[i].size > bkp.size) {
        return backpackWithoutItem;
    }

    bkp.load += items[i].size;
    bkp.value += items[i].value;
    bkp.items.push_back(items[i]);
    backpack backpackWithItem = backtrackingSinPodaRecursion(i + 1, bkp, items);

    if (backpackWithItem.value > backpackWithoutItem.value) {
        return backpackWithItem;
    } else {
        return backpackWithoutItem;
    }
}

backpack backtrackingSinPoda(int bkpSize, vector<item> &items) {
    backpack bkp;
    bkp.value = 0;
    bkp.load = 0;
    bkp.size = bkpSize;

    return backtrackingSinPodaRecursion(0, bkp, items);
};
