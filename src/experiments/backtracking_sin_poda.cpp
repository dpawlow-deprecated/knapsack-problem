#include <iostream>
#include <vector>
#include <algorithm>
#include "../utilities/backpack.h"

using namespace std;

Backpack backtrackingSinPodaRecursion(int i, Backpack bkp, vector<Item> const &items) {
    if (i >= items.size()) {
        return bkp;
    }
    Backpack backpackWithoutItem = backtrackingSinPodaRecursion(i + 1, bkp, items);

    if (bkp.getLoad() + items[i].getSize() > bkp.getSize()) {
        return backpackWithoutItem;
    }

    bkp.addItem(items[i]);
    Backpack backpackWithItem = backtrackingSinPodaRecursion(i + 1, bkp, items);

    if (backpackWithItem.getValue() > backpackWithoutItem.getValue()) {
        return backpackWithItem;
    } else {
        return backpackWithoutItem;
    }
}

unsigned long backtrackingSinPoda(unsigned long bkpSize, vector<Item> &items) {
    Backpack bkp = Backpack(bkpSize);

    return backtrackingSinPodaRecursion(0, bkp, items).getValue();
};
