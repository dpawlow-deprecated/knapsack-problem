#include <iostream>
#include <vector>
#include <algorithm>
#include "../utilities/types.h"
#include "../backtracking.h"

using namespace std;

Backpack backtrackingOptimalidadRecursion(int i, Backpack bkp, vector<Item> const &items, unsigned long maxValue) {
    if (i >= items.size() || !maxValueIsReachable(i, bkp, items, maxValue)) {
        if (bkp.getValue() > maxValue) {
            maxValue = bkp.getValue();
        }
        return bkp;
    }
    Backpack backpackWithoutItem = backtrackingOptimalidadRecursion(i + 1, bkp, items, maxValue);

    if (bkp.getLoad() + items[i].getSize() > bkp.getSize()) {
        return backpackWithoutItem;
    }

    bkp.addItem(items[i]);
    Backpack backpackWithItem = backtrackingOptimalidadRecursion(i + 1, bkp, items, maxValue);

    if (backpackWithItem.getValue() > backpackWithoutItem.getValue()) {
        return backpackWithItem;
    } else {
        return backpackWithoutItem;
    }
}

unsigned long backtrackingPodaOptimalidad(unsigned long bkpSize, vector<Item> &items) {
    Backpack bkp = Backpack(bkpSize);

    //Se ordena primero por valor decreciente y luego con un algoritmo estable por tamaño creciente
    //El ordenamiento se usa en las podas
    sort(items.begin(), items.end(), isMoreEfficient);

    return backtrackingOptimalidadRecursion(0, bkp, items, 0).getValue();
};
