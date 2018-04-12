#include <iostream>
#include <vector>
#include <algorithm>
#include "../utilities/types.h"
#include "../backtracking.h"

using namespace std;

backpack backtrackingFactibilidadRecursion(int i, backpack bkp, vector<item> const &items) {
    if (i >= items.size() || !hasRoomForMore(i, bkp, items)) {
        return bkp;
    }
    backpack backpackWithoutItem = backtrackingFactibilidadRecursion(i + 1, bkp, items);

    if (bkp.load + items[i].size > bkp.size) {
        return backpackWithoutItem;
    }

    bkp.load += items[i].size;
    bkp.value += items[i].value;
    bkp.items.push_back(items[i]);
    backpack backpackWithItem = backtrackingFactibilidadRecursion(i + 1, bkp, items);

    if (backpackWithItem.value > backpackWithoutItem.value) {
        return backpackWithItem;
    } else {
        return backpackWithoutItem;
    }
}

int backtrackingPodaFactibilidad(int bkpSize, vector<item> &items) {
    backpack bkp;
    bkp.value = 0;
    bkp.load = 0;
    bkp.size = bkpSize;

    //Se ordena primero por valor decreciente y luego con un algoritmo estable por tamaño creciente
    //El ordenamiento se usa en las podas
    sort(items.begin(), items.end(), isMoreValuable);
    stable_sort(items.begin(), items.end(), isLighter);

    return backtrackingFactibilidadRecursion(0, bkp, items).value;
};