#include <iostream>
#include <vector>
#include <algorithm>
#include "../backtracking.h"

using namespace std;

Backpack backtrackingFactibilidadRecursion(int i, Backpack bkp, vector<Item> const &items) {
    if (i >= items.size() || !hasRoomForMore(i, bkp, items)) {
        return bkp;
    }
    Backpack backpackWithoutItem = backtrackingFactibilidadRecursion(i + 1, bkp, items);

    if (bkp.getLoad() + items[i].getSize() > bkp.getSize()) {
        return backpackWithoutItem;
    }
    bkp.addItem(items[i]);
    Backpack backpackWithItem = backtrackingFactibilidadRecursion(i + 1, bkp, items);

    if (backpackWithItem.getValue() > backpackWithoutItem.getValue()) {
        return backpackWithItem;
    } else {
        return backpackWithoutItem;
    }
}

unsigned long backtrackingPodaFactibilidad(unsigned long bkpSize, vector<Item> &items) {
    Backpack bkp = Backpack(bkpSize);
    return backtrackingFactibilidadRecursion(0, bkp, items).getValue();
};