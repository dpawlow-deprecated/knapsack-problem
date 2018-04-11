#include <iostream>
#include <vector>
#include <algorithm>
#include "../utilities/types.h"
#include "../backtracking.h"

using namespace std;

backpack backtrackingOptimalidadRecursion(int i, backpack bkp, vector<item> const &items, int maxValue) {
    if (i >= items.size() || !maxValueIsReachable(i, bkp, items, maxValue)) {
        if (bkp.value > maxValue) {
            maxValue = bkp.value;
        }
        return bkp;
    }
    backpack backpackWithoutItem = backtrackingOptimalidadRecursion(i + 1, bkp, items, maxValue);

    if (bkp.load + items[i].size > bkp.size) {
        return backpackWithoutItem;
    }

    bkp.load += items[i].size;
    bkp.value += items[i].value;
    bkp.items.push_back(items[i]);
    backpack backpackWithItem = backtrackingOptimalidadRecursion(i + 1, bkp, items, maxValue);

    if (backpackWithItem.value > backpackWithoutItem.value) {
        return backpackWithItem;
    } else {
        return backpackWithoutItem;
    }
}

backpack backtrackingPodaOptimalidad(int bkpSize, vector<item> &items) {
    backpack bkp;
    bkp.value = 0;
    bkp.load = 0;
    bkp.size = bkpSize;

    //Se ordena primero por valor decreciente y luego con un algoritmo estable por tamaño creciente
    //El ordenamiento se usa en las podas
    sort(items.begin(), items.end(), isMoreValuable);
    stable_sort(items.begin(), items.end(), isLighter);

    return backtrackingOptimalidadRecursion(0, bkp, items, 0);
};
